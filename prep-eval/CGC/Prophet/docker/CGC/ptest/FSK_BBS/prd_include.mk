# Example include file
BIN:=FSK_BBS
DETOUR_BIN ?= $(BIN).trampoline.bin
MYSRC ?= decompiled_source.c
MYREP ?= repair.c
DETOUR_PREFIX := det_
#DETOUR_DEFS := <fn0>:<fn0_symbol_dependencies> <fn1>:<fn1_symbol_dependencies>
DETOUR_DEFS := 
DETOUR_CALLS := $(patsubst %, --external-funcs $(DETOUR_PREFIX)%, $(DETOUR_DEFS))
DETOURS := $(patsubst %, $(DETOUR_PREFIX)%, $(DETOUR_DEFS))
FUNCINSERT_PARAMS := $(DETOURS) $(DETOUR_CALLS) --debug 
