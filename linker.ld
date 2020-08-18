MEMORY
{
	ROM   (rx) : ORIGIN = 0x00007000, LENGTH = (2k)
}

latte = 0x000000c0;
ENTRY(_start)

SECTIONS
{
	.text :
	{
		*(.text*)
		*(.rodata*)
	} > ROM

    /DISCARD/ :
    {
        *(.ARM.*)
        *(.debug_*)
        *(.comment)
    }
}


