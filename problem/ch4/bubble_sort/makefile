YAS = ~/Documents/archlab-handout/sim/misc/yas
YIS = ~/Documents/archlab-handout/sim/misc/yis

cpointer:
	gcc -std=c99 main.c bubble_p.c \
		-o main

assemble:
	gcc -Og -S bubble_p.c

pointer:
	$(YAS) bubble_p.ys
	$(YIS) bubble_p.yo

cmove3:
	$(YAS) bubble_p_cmov_3.ys
	$(YIS) bubble_p_cmov_3.yo

cmove1:
	$(YAS) bubble_p_cmov_1.ys
	$(YIS) bubble_p_cmov_1.yo

testA: cpointer
	./main

testB: pointer

test4_48: cmove3

test4_49: cmove1

.PHONY: clean
clean:
	-rm -f main *.s *.yo