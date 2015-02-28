/******************************************************************************
*	kernel.ld
*	 by Alex Chadwick
*
*	A linker script for generation of raspberry pi kernel images.
******************************************************************************/

SECTIONS {
    /*
    * First and formost we need the .init section, containing the IVT.
    * coronax - changed this from 0000 to 8000 to work with newer rpi boot
    * loader, which loads code to 8000 regardless
    */
    .init 0x8000 : {
        *(.init)
    }

    /* 
    * We allow room for the ATAGs and the stack and then start our code at
    * 0x8000.
    * coronax - changed to 8080 to make room for .init section
    */
    .text 0x8200 : {
        *(.text)
    }

    /* 
    * Next we put the data.
    */
    .data : {
        *(.data)
    }

    /* coronax - added .rodata and COMMON sections */
    .rodata : {
        *(.rodata)
    }
    
    .bss : {
        *(.bss)
    }

    COMMON : {
        *(COMMON)
    }

    /*
    * Finally comes everything else. A fun trick here is to put all other 
    * sections into this section, which will be discarded by default.
    */
    /DISCARD/ : {
        *(*)
    }
}

GROUP (
	/home/nvreformat/arm-2008q3/lib/gcc/arm-none-eabi/4.9.3/libgcc.a
)
