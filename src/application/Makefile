MODULE 	:= main
TARGET 	:= $(BUILD_DIR)/$(MODULE).o
SRC 	:= $(MODULE).c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	@echo "Building main program"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(CLEAN_TARGETS)
