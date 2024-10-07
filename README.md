# TameOS

### About

TameOS is a... minimal OS which has good features like:
- VGA terminal
- Color
- Multiboot support
- CPU(ID) info

### Requirements

To build TameOS, you need a:
- Machine running the GNU/Linux operating system (or perhaps WSL[^1])
- Bash shell
- i686 cross-compiler[^2] (i686-elf is the recommended one) (may not be needed if your computer is i686 architecture, just change the CC variable in build.sh)
- Virtual machine drivers like KVM[^3] and support
- Virtual machine like QEMU[^4]

[^1]: WSL (Windows Subsystem for Linux) allows you to use Linux on your Windows machine.
[^2]: A cross-compiler compiles onto another architecture different to your computer's architecture.
[^3]: KVM (Kernel-based Virtual Machine) is a virtualization module in the Linux kernel that allows the kernel to function as a hypervisor (which creates an runs virtual machines).
[^4]: QEMU (Quick Emulator) is an emulator which can work with operating systems, and can work with KVM[^4].


### Building TameOS

Once you have met requirements, execute build.sh (superuser[^5] access is not required).
If everything goes well, run your virtual machine with the produced TameOS ISO.

[^5]: A superuser is a user, usually referenced as `root`, which can access files which shouldn't be accessed by the usual user, hence the name.

### Thank you for looking at TameOS ❤️
