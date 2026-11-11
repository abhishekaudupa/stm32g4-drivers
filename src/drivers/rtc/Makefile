MODULE 	:= $(notdir $(CURDIR))
SRC 	:= $(MODULE).c $(MODULE).h
TARGET 	:= $(BUILD_DIR)/$(MODULE).o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	@echo "Building $(MODULE) driver"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(CLEAN_TARGETS)
