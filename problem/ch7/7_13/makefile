all:
	gcc -Og sample.c -o sg
	gcc -Og -g sample.c -o dg

dump:
	objdump -d sg
	objdump -d dg

slib:
	ldd sg

.PHONY: clean
clean:
	rm sg dg
