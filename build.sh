#!/bin/bash

BARN_SOURCES=`find ./kernel -name "*.ba"`
C_SOURCES=`find ./kernel -name "*.c"`

OUTPUTS=""

for barn_file in $BARN_SOURCES
do
    barn $barn_file --no-main --no-stdlib --no-delete-cout --cflags "-m32 -c -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -o $barn_file.o"
    OUTPUTS="$OUTPUTS $barn_file.o"
done

for c_file in $C_SOURCES
do
    gcc $c_file -o $c_file.o -m32 -c -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs
    OUTPUTS="$OUTPUTS $c_file.o"
done

nasm -f elf ./asm/loader.asm -o ./asm/loader.o
OUTPUTS="$OUTPUTS ./asm/loader.o"

mkdir -p build/iso/boot/grub/

ld -m elf_i386 -Tlinker.ld -o build/iso/boot/kernel.elf $OUTPUTS
cp -f grub.cfg build/iso/boot/grub/
grub-mkrescue -o barnos.iso build/iso

qemu-system-x86_64 -cdrom barnos.iso -m 1G