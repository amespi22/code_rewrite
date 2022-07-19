BUILD_DIR=./build
#all:    INIT CLEANME default_target POST
#include $(BUILD_DIR)/Makefile
all:    CLEANME BUILD POST
#include $(BUILD_DIR)/Makefile
VERBOSE?=OFF


CLEANME: 
	@[ -d $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && rm -f CMakeCache.txt
	@cd $(BUILD_DIR) && cmake -DBUILD_SHARED_LIBS=ON -DBUILD_STATIC_LIBS=OFF -DBINARY=${CB} -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE)  ../

BUILD:
	@cd $(BUILD_DIR) && make ${CB}

POST:
	@cd $(BUILD_DIR) &&  cp compile_commands.json ../

CLEAN:
	@cd $(BUILD_DIR) && make clean

clean: CLEAN
