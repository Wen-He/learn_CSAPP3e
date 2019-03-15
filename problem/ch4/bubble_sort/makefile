YAS = ~/Documents/archlab-handout/sim/misc/yas
YIS = ~/Documents/archlab-handout/sim/misc/yis

test_pointer:
	gcc -std=c99 main.c bubble_p.c \
		-o test_p

assemble:
	gcc -Og -S bubble_p.c

pointer:
	$(YAS) bubble_p.ys
	$(YIS) bubble_p.yo

clean:
	rm test_p *.s *.yo