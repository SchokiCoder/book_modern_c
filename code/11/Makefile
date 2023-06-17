CC = cc
COPTS = -std=c99 -pedantic -Wall -Wextra -Werror
R_COPTS = ${COPTS} -Os
D_COPTS = ${COPTS} -g

D_lib_math_test: d_main.o d_lib.o
	$(CC) ${D_COPTS} -o $@ $^

lib_math_test: main.o lib.o
	$(CC) ${R_COPTS} -o $@ $^

d_main.o: main.c
	$(CC) ${D_COPTS} -c -o $@ $^

d_lib.o: lib.c
	$(CC) ${D_COPTS} -c -o $@ $^

main.o: main.c
	$(CC) ${R_COPTS} -c -o $@ $^

lib.o: lib.c
	$(CC) ${R_COPTS} -c -o $@ $^

clean:
	rm -f *.o
	rm -f D_lib_math_test
	rm -f lib_math_test
