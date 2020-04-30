all:
	arm-linux-g++ -c -o led.o led.cpp
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o led.o -o led.elf
	arm-linux-objcopy -O binary -S led.elf led.bin
	arm-linux-objdump -D led.elf > led.dis

clean:
	rm -rf *.elf *.bin *.o *.dis
