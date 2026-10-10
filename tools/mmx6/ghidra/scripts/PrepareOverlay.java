// PrepareOverlay.java -- headless preScript for tools/mmx6/ghidra/import.sh --member.
// Args: <version> <base>. version in psx_ldr loader format (e.g. "4.7.0"); base = the config/loadmap.txt base.
// 1. The raw import is made at base 0: Program.setImageBase(base, commit) moves every block by the delta, so the
//    block lands at <base> AND the image base is <base> (BinaryLoader alone leaves the image base at 0, which
//    ImportAnnotations' base check could not tell apart between overlay groups).
// 2. A raw (BinaryLoader) program has no psx_ldr Program Information "PsyQ Version"; psx_ldr's "PsyQ Signatures"
//    analyzer runs on it anyway (canAnalyze: language PSX:LE:32:default) but would fall back to its own
//    "if not found" option. Setting the property before auto-analysis pins the overlays to the exe's detected
//    version (the analyzer reads psyq/<ver w/o dots>/).
import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;
import ghidra.program.model.listing.Program;

public class PrepareOverlay extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2 || args[0].isEmpty()) {
            throw new IllegalArgumentException("usage: PrepareOverlay.java <version> <base>");
        }
        if (currentProgram.getImageBase().getOffset() != 0) {
            throw new IllegalStateException("PrepareOverlay: expected a raw import at base 0, got " + currentProgram.getImageBase());
        }
        currentProgram.setImageBase(toAddr(Long.decode(args[1])), true);
        Options opts = currentProgram.getOptions(Program.PROGRAM_INFO);
        opts.setString("PsyQ Version", args[0]);
        println("PrepareOverlay: " + currentProgram.getName() + " image base " + currentProgram.getImageBase()
                + ", PsyQ Version = " + args[0]);
    }
}
