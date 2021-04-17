CC = gcc

emerg_reboot: emerg_reboot.o sysrq.o textfile.o
	${CC} -o emerg_reboot emerg_reboot.o sysrq.o textfile.o

emerg_reboot.o: emerg_reboot.c
	${CC} -c emerg_reboot.c

sysrq.o: sysrq.c
	${CC} -c sysrq.c

textfile.o: textfile.c
	${CC} -c textfile.c
