# BarnOS
Simple OS that is booting with GRUB written in Barn and a little bit of C
# Video
[Check out!](./2023-03-17_16-04-00(1).mp4)
<video controls>
  <source src="./2023-03-17_16-04-00(1).mp4" type="video/mp4">
</video>
# Build
To build this crappy "os" you need to have these tools:
- Barn Compiler
- GCC Compiler for C files
- xorisso
- grub-mkrescue
- NASM
- qemu-system-x86_64
The option to build it will be to use a linux machine. Here's how to build it:
```
git clone https://github.com/barn-lang/barnos
cd barnos
bash build.sh
```
After it there should be a qemu window running
