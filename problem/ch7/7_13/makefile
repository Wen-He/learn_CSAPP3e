all:
	gcc -Og sample.c -o sg
	gcc -Og -g sample.c -o dg

dump:
	objdump -d sg > sg.s
	objdump -d dg > dg.s

slib:
	ldd sg

.PHONY: clean
clean:
	rm sg dg *.s
