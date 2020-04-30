all:
	arm-linux-g++ -c -o led_r.o led_r.cpp
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o led_r.o -o led_r.elf
	arm-linux-objcopy -O binary -S led_r.elf led_r.bin
	arm-linux-objdump -D led_r.elf > led_r.dis

clean:
	rm -rf *.elf *.bin *.o *.dis
