ENTRY(reset_handler)

MEMORY {
    flash(rx): ORIGIN = 0x8000000, LENGTH = 512K
    sram(rwx): ORIGIN = 0x20000000, LENGTH = 96K 
    ccmsram(rwx): ORIGIN = 0x10000000, LENGTH = 16K 
}

_estack = ORIGIN(sram) + LENGTH(sram);

SECTIONS {
    
    .sysivt : {
        KEEP(*(".sysivt"))
    }> flash

    .ivt : {
        KEEP(*(".ivt"))
    }> flash

    .text : {
        *(".text.*")
    }> flash

    .rodata : {
        . = ALIGN(4);
        *(".rodata.*")
        _etext = .;
    }> flash
    
    .data : {
        . = ALIGN(4);
        _sdata = .;
        *(".data.*")
        _edata = .;
    }> sram AT> flash
    
    .bss : {
        . = ALIGN(4);
        _sbss = .;
        *(".bss.*")
        _ebss = .;
    }> sram
}
