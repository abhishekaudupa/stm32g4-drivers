MODULE 	:= $(notdir $(CURDIR))
SRC 	:= $(MODULE).c
TARGET 	:= $(BUILD_DIR)/$(MODULE).o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	@echo "Building $(MODULE) driver using files: $(SRC)"
	@$(CC) $(CFLAGS) -c $(SRC) -o $@

clean:
	rm -rf $(CLEAN_TARGETS)

-include $(BUILD_DIR)/$(MODULE).d
