Authors: Joona Pellinen and Altti Väätäinen
Tested on Ubuntu 20.04.4 LTS

This is repository contains three different miniprojects and README.md file.
This documentation contains examples of how to run the projects after cloning this repository to your own local device.


PROJECT 4 KERNEL:
The original OS was downloaded from https://github.com/mit-pdos/xv6-public. All the changes were made to the original OS, see the documentation for the changelog.
If you don't have qemu installed on your system, run command "sudo apt install qemu".
If you are using 64 bit OS, you have a high change that the system is unable to find a working qemu executable.
You should change Makefile at line 54 and uncomment the line "QEMU = qemu-system-x86_64". 
(Please be noted, that these changes have been made already, if you cloned this repository)
After changing the Makefile, you should install qemu-system-x86_64 with command "sudo apt install qemu-system-x86"

After necessary installations and changes, run command "make".
Then run command "make qemu" to start the kernel on qemu-emulator.
You can run the getreadcount program with command "getreadcount" on the emulator.
You can reset the counter with passing any argument to the getreadcount function.

Used sources on this project:
For xv6 and qemu installations this instruction post was used: https://www.assistedcoding.eu/2017/11/06/install-vx6-operating-system/
For the code part the provided background video and background section was used.
Additionally the following sources provided useful insights and tips for the code part:
https://www.geeksforgeeks.org/xv6-operating-system-adding-a-new-system-call/
https://stackoverflow.com/questions/8021774/how-do-i-add-a-system-call-utility-in-xv6
