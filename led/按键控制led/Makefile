all:
	arm-linux-g++ -c -o led_key.o led_key.cpp
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o led_key.o -o led_key.elf
	arm-linux-objcopy -O binary -S led_key.elf led_key.bin
	arm-linux-objdump -D led_key.elf > led_key.dis

clean:
	rm -rf *.elf *.bin *.o *.dis
