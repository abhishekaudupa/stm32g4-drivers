SUBDIRS := $(wildcard */)

.PHONY: all clean

all:
	@$(foreach dir,$(SUBDIRS),$(MAKE) -C $(dir);)

clean:
	@$(foreach dir,$(SUBDIRS),$(MAKE) -C $(dir) clean;)
