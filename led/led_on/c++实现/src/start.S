.text

.global _start
_start:
	/*设置内存 sp*/
	//nand启动
	ldr sp, =4096
	//nor启动
	//ldr sp, =0x40000000+4096

	/*调用 main*/
	bl main

halt:
	b halt
