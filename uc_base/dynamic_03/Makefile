.PHONY : dynamic test clean
dynamic:
	gcc ./dynamic.c -ldl -Wl,-rpath=. -o dynamic

test:
	gcc ./test.c -Itmath -Ltmath -ltmath -o tt -std=c99

clean :
	rm dynamic
