FINAL_MODULE	:= firmware
PROJECT_ROOT	:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR 		:= $(PROJECT_ROOT)/build
LOG_DIR			:= $(PROJECT_ROOT)/logs
SRC_DIR			:= $(PROJECT_ROOT)/src
INCLUDE_DIRS	:= -I$(SRC_DIR)

CC 				:= arm-none-eabi-gcc
CFLAGS	 		:= $(INCLUDE_DIRS) -MMD -MP -mcpu=cortex-m4 -mthumb -ffreestanding -O2 -g -Wall
CLEAN_TARGETS	:= *.o *.d *.out *.elf *.bin *.map *.log $(BUILD_DIR) $(LOG_DIR)

MAKEFLAGS		+= --no-print-directory
LINKER_SCRIPT	:= stm32g491re.ld
LINKER_MAP		:= $(FINAL_MODULE).map
LDFLAGS 		:= -Wl,-T $(SRC_DIR)/$(LINKER_SCRIPT) -Wl,-Map=$(BUILD_DIR)/$(LINKER_MAP) -nostdlib
ELF				:= $(FINAL_MODULE).elf
BIN				:= $(FINAL_MODULE).bin

export PROJECT_ROOT BUILD_DIR SRC_DIR CC CFLAGS CLEAN_TARGETS

.PHONY: all build_objs clean dump flash debug

all: build_objs $(ELF) $(BIN)

build_objs:
	@$(MAKE) -C $(SRC_DIR)

$(ELF): $(wildcard $(BUILD_DIR)/*.o)
	@echo "Building firmware ELF"
	@$(CC) $(LDFLAGS) $(BUILD_DIR)/*.o -o $@

$(BIN): $(ELF)
	@echo "Building firmware binary"
	@arm-none-eabi-objcopy -O binary $< $@
	@echo "Firmware binary $(BIN) built succesfully. Size of binary: $$(ls -lh $@ | cut -d ' ' -f 5) bytes"

dump: $(ELF)
	arm-none-eabi-objdump -dsh $<

flash: $(ELF)
	@$(MAKE) build_objs
	@$(MAKE) $(ELF)
	@echo
	@echo "Flashing firmware to the board"
	@openocd -f interface/stlink.cfg -f target/stm32g4x.cfg -c "program $(ELF) verify; reset; exit"

debug: $(ELF)
	@$(MAKE) build_objs
	@$(MAKE) $(ELF)
	@echo
	@echo "Flashing and starting GDB debugger"
	@./debug.sh $(ELF)

clean:
	@$(MAKE) -C $(SRC_DIR) clean
	rm -rf $(CLEAN_TARGETS)
