SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
DEP := $(OBJ:.o=.d)

.PHONY: all clean

all: $(OBJ)

$(BUILD_DIR)/%.o: %.c
	@echo "Building main program from files: $<"
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(CLEAN_TARGETS)

-include $(DEP)
