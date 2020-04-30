.text
.global _start

_start:

	/*关闭看门狗*/
	ldr r0, =0x53000000
	ldr r1, =0
	str r1, [r0]
	
	/*设置内存 sp
	*分辨是nand启动/nor启动
	*nand可读可写，nor只可读
	*方法：向0地址写入0，再读出，如果结果为0,则为
	*nand启动，反之为nor启动
	*/
	//保存0地址处的值
	mov r1, #0
	ldr r0, [r1]
	//向0地址写入0
	str r1, [r1]
	//读出0地址处的值
	ldr r2, [r1]
	cmp r1,r2
	//先假设为nor启动
	ldr sp, =0x40000000+4096
	//nand启动
	moveq sp, #4096
	//如果是nand启动，则恢复原来的值
	streq r0,[r1]

	/*调用 main*/
	bl main

halt:
	b halt
