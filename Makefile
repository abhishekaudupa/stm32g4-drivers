PROJECT_ROOT	:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR 		:= $(PROJECT_ROOT)/build
SRC_DIR			:= $(PROJECT_ROOT)/src
INCLUDE_DIRS	:= -I$(SRC_DIR)

CC 				:= arm-none-eabi-gcc
CFLAGS	 		:= $(INCLUDE_DIRS) -MMD -MP -mcpu=cortex-m4 -mthumb -ffreestanding -O2 -g -Wall
CLEAN_TARGETS	:= *.o *.out *.elf *.bin *.map $(BUILD_DIR)

export PROJECT_ROOT BUILD_DIR SRC_DIR CC CFLAGS CLEAN_TARGETS

MAKEFLAGS		+= --no-print-directory
LINKER_SCRIPT	:= stm32g491re.ld
LINKER_MAP		:= final.map
LDFLAGS 		:= -Wl,-T $(SRC_DIR)/$(LINKER_SCRIPT) -Wl,-Map=$(BUILD_DIR)/$(LINKER_MAP) -nostdlib
ELF				:= final.elf
BIN				:= final.bin

.PHONY: all build_objs clean dump flash debug

all: build_objs $(ELF) $(BIN)

$(ELF):
	@$(MAKE) -C $(SRC_DIR)
	@echo
	@echo "Building firmware ELF"
	@$(CC) $(LDFLAGS) $(BUILD_DIR)/*.o -o $@

$(BIN): $(ELF)
	@echo "Building firmware binary"
	@arm-none-eabi-objcopy -O binary $< $@

build_objs:
	@$(MAKE) -C $(SRC_DIR)

dump: $(ELF)
	arm-none-eabi-objdump -dsh $<

flash: $(ELF)
	openocd -f interface/stlink.cfg -f target/stm32g4x.cfg -c "program $(ELF) verify; reset; exit"

debug: $(ELF)
	./debug.sh $(ELF)

clean:
	@$(MAKE) -C $(SRC_DIR) clean
	rm -rf $(CLEAN_TARGETS)
