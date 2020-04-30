/*
*led_on: GPF4
*/
.text
.global _start

_start:

/*配置GPF4为输出引脚*/
/*把0x100写到0x56000050*/
	ldr r1, =0x56000050
	ldr r0, =0x100
	str r0, [r1]

//向GPF4中写入0
//把0写到0x56000054
	ldr r1, =0x56000054
	ldr r0, =0
	str r0, [r1]

halt:
	b halt

