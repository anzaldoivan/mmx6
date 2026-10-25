# sdk.mk — the vendor SDK leg (phase 1.9 T4, docs/ops/decomp-environment.md ## SDK leg): `make SDK=/sdk build` links
# the ledger's vendor TUs of the exe from the PsyQ SDK's own objects. After split, tools/mmx6/sdk.py extracts and
# converts them to build/sdk/<TU>.o, solves their data/bss addresses and unresolved globals from relocations vs the
# retail exe and writes build/sdk/<bin>.{ld,main.ld,mk}; the included .mk sets SDK_DROP_<bin> (asm objects that leave
# the link), SDK_OBJS_<bin> and SDK_LD_<bin> (the splat script pointing at them), read by the build/%.elf rule.
# SDK unset: nothing here applies and those variables are empty, so every recipe is unchanged.
# SDK_ONLY=<regex>: substitute only the matching TUs (iteration aid).
ifneq ($(SDK),)
.PHONY: sdk-objs
build: sdk-objs
sdk-objs: split
	$(PYTHON) tools/mmx6/sdk.py --sdk $(SDK) $(if $(SDK_ONLY),--only '$(SDK_ONLY)')
-include build/sdk/SLUS_013.95.mk
endif
