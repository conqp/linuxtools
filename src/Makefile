emerg_reboot: emerg_reboot.o sysrq.o textfile.o
	gcc -o emerg_reboot emerg_reboot.o sysrq.o textfile.o

emerg_reboot.o: emerg_reboot.c
	gcc -c emerg_reboot.c

sysrq.o: sysrq.c
	gcc -c sysrq.c

textfile.o: textfile.c
	gcc -c textfile.c
