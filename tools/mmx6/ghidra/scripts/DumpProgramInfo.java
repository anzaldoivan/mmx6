// DumpProgramInfo.java -- headless postScript for tools/mmx6/ghidra/import.sh.
// Args: <info-file> <input-sha1> | <info-dir> <sha1-map> (batch). Writes the program facts the oracle relies on (format: docs/ops/oracles.md):
// language, image_base, entry, psyq_version (psx_ldr Program Information "PsyQ Version"), sig_functions, functions,
// input_sha1. sig_functions = functions in initialized memory (not GTEMAC) whose primary symbol source is
// USER_DEFINED or IMPORTED, minus the entry point and "main": psx_ldr's SigApplier names matches via
// FlatProgramAPI.createFunction (USER_DEFINED); everything else in a fresh import is DEFAULT/ANALYSIS.
// Adapted from the decomp-architect kit P2 DumpProgramInfo.java.
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Program;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;

public class DumpProgramInfo extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException("usage: DumpProgramInfo.java <info-file> <input-sha1>");
        }
        Program p = currentProgram;
        // Batch mode (import.sh --member, one JVM per base group): args = <info-dir> <sha1-map>, the map's lines
        // `<program> <sha1>`; the info file is <info-dir>/<program>.txt.
        String infoPath = args[0], sha1 = args[1];
        if (new java.io.File(args[0]).isDirectory()) {
            infoPath = new java.io.File(args[0], p.getName() + ".txt").getPath();
            sha1 = null;
            for (String ln : java.nio.file.Files.readAllLines(java.nio.file.Paths.get(args[1]))) {
                String[] kv = ln.trim().split("\\s+");
                if (kv.length == 2 && kv[0].equals(p.getName())) sha1 = kv[1];
            }
            if (sha1 == null) throw new IllegalArgumentException("DumpProgramInfo: no sha1 for " + p.getName());
        }

        AddressIterator eps = p.getSymbolTable().getExternalEntryPointIterator();
        Address entry = null;
        while (eps.hasNext()) {
            Address a = eps.next();
            MemoryBlock b = p.getMemory().getBlock(a);
            println("DumpProgramInfo: external entry " + a + " block " + (b == null ? "-" : b.getName()));
            if (entry == null && b != null && b.isInitialized() && !b.getName().equals("GTEMAC")) {
                entry = a;
            }
        }

        Options opts = p.getOptions(Program.PROGRAM_INFO);
        String ver = opts.contains("PsyQ Version") ? opts.getString("PsyQ Version", "") : "";
        if (ver == null || ver.isEmpty()) {
            ver = "none";
        }

        int sig = 0;
        int byUser = 0, byImported = 0;
        for (Function f : p.getFunctionManager().getFunctions(true)) {
            SourceType src = f.getSymbol().getSource();
            if (src != SourceType.USER_DEFINED && src != SourceType.IMPORTED) {
                continue;
            }
            MemoryBlock b = p.getMemory().getBlock(f.getEntryPoint());
            if (b == null || !b.isInitialized() || b.getName().equals("GTEMAC")) {
                continue;
            }
            if (f.getEntryPoint().equals(entry) || f.getName().equals("main")) {
                continue;
            }
            sig++;
            if (src == SourceType.USER_DEFINED) byUser++; else byImported++;
        }
        println("DumpProgramInfo: sig_functions breakdown USER_DEFINED=" + byUser + " IMPORTED=" + byImported);

        try (PrintWriter w = new PrintWriter(infoPath, "UTF-8")) {
            w.println("language: " + p.getLanguageID() + ":" + p.getCompilerSpec().getCompilerSpecID());
            w.println(String.format("image_base: 0x%08x", p.getImageBase().getOffset()));
            w.println(entry == null ? "entry: none" : String.format("entry: 0x%08x", entry.getOffset()));
            w.println("psyq_version: " + ver);
            w.println("sig_functions: " + sig);
            w.println("functions: " + p.getFunctionManager().getFunctionCount());
            w.println("input_sha1: " + sha1);
        }
        println("DumpProgramInfo: wrote " + infoPath);
    }
}
