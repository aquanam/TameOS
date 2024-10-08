#!/usr/bin/bash
set -e

export ARCH="i386"

export CC="i686-elf-gcc"
export AS="i686-elf-as"

echo -e "\n[ build.sh - TameOS ]"
echo "Chosen architecure to build: ${ARCH}"
echo "Cross compiler: ${CC}"
echo -e "Cross compiler (assembler): ${AS}\n"

echo "Build phase..."
echo "[I] Building libraries..."
# this compilation progress is manky...
${CC} -c src/arch/${ARCH}/lib/c/int.c -o int.o -O2 -Wall -Wextra
${CC} -c src/arch/${ARCH}/lib/c/string.c -o string.o -O2 -Wall -Wextra
${CC} -c src/arch/${ARCH}/lib/panic.c -o panic.o -O2 -Wall -Wextra
${CC} -c src/arch/${ARCH}/lib/cpu.c -o cpu.o -O2 -Wall -Wextra
${CC} -c src/arch/${ARCH}/lib/vga.c -o vga.o -O2 -Wall -Wextra
${CC} -c src/arch/${ARCH}/lib/tty.c -o tty.o -O2 -Wall -Wextra
echo "[I] Buiding kernel..."
${AS} src/arch/${ARCH}/boot.s -o boot.o
${CC} -c src/arch/${ARCH}/kern.c -o kern.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

echo "[I] Linking kernel..."
${CC} -T linker.ld -o tameos.bin -ffreestanding -O2 -nostdlib \
    boot.o kern.o \
    string.o int.o \
    panic.o cpu.o vga.o tty.o -lgcc

echo "[I] Verifying multiboot..."
if grub-file --is-x86-multiboot tameos.bin; then
  echo "[-] Multiboot confirmed"
else
  echo "[-] File is not multiboot!"
  echo "[E] Multiboot invalid..."
  exit -1
fi

echo -e "\nInstall phase..."

echo "[I] Moving over OS .bin file..."
mv tameos.bin iso/boot/tameos.bin

echo "[I] Making bootable CD-ROM..."
echo "[-] Using GRUB..."
grub-mkrescue -o tameos.iso iso

echo -e "\nFinished successfully!\n"
