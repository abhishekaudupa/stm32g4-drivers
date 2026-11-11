ENTRY(reset_handler)

MEMORY {
    flash(rx): ORIGIN = 0x8000000, LENGTH = 512K
    sram(rwx): ORIGIN = 0x20000000, LENGTH = 96K 
    ccmsram(rwx): ORIGIN = 0x10000000, LENGTH = 16K 
}

_estack = ORIGIN(sram) + LENGTH(sram);

SECTIONS {
    
    .sysivt : {
        *(".sysivt")
    }> flash

    .ivt : {
        *(".ivt")
    }> flash

    .text : {
        *(".text")
    }> flash

    .rodata : {
        *(".rodata")
        . = ALIGN(4);
        _etext = .;
    }> flash
    
    .data : {
        _sdata = .;
        *(".data")
        . = ALIGN(4);
        _edata = .;
    }> sram AT> flash
    
    .bss : {
        _sbss = .;
        *(".bss")
        . = ALIGN(4);
        _ebss = .;
    }> sram
}
