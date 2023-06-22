CC = cc
COPTS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all:	1/barebones \
	2/constants 2/variables\
	3/functions\
	4/increment_basic 4/increment_return\
	5/if 5/else 5/else_if 5/no_brackets 5/switch 5/boolean 5/logical\
	6/while 6/do_while 6/for 6/loop_control\
	7/printf\
	8/array\
	9/comments 9/genius 9/self_explanatory\
	10/sane 10/insane\
	13/include.o 13/floatstuff.o 13/intstuff.o\
	14/globals\
	15/return_parameter 15/malloc 15/const_size\
	17/messenger 17/typedef\
	18/enum 18/enum_vals.o\
	19/flip 19/data_loss 19/implicit\
	21/faulty 21/correct\
	22/generics\
	23/string_reverse\
	24/fixsizeint 24/evil_goto 24/float 24/cstrings 24/static

1/barebones: 1/barebones.c
	$(CC) ${COPTS} -o $@ $^

2/constants: 2/constants.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

2/variables: 2/variables.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

3/functions: 3/functions.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

4/increment_basic: 4/increment_basic.c
	$(CC) ${COPTS} -o $@ $^

4/increment_return: 4/increment_return.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

5/if: 5/if.c
	$(CC) ${COPTS} -o $@ $^

5/else: 5/else.c
	$(CC) ${COPTS} -o $@ $^

5/else_if: 5/else_if.c
	$(CC) ${COPTS} -o $@ $^

5/no_brackets: 5/no_brackets.c
	$(CC) ${COPTS} -Wno-uninitialized -o $@ $^

5/switch: 5/switch.c
	$(CC) ${COPTS} -o $@ $^

5/boolean: 5/boolean.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

5/logical: 5/logical.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

6/while: 6/while.c
	$(CC) ${COPTS} -o $@ $^

6/do_while: 6/do_while.c
	$(CC) ${COPTS} -o $@ $^

6/for: 6/for.c
	$(CC) ${COPTS} -o $@ $^

6/loop_control: 6/loop_control.c
	$(CC) ${COPTS} -o $@ $^

7/printf: 7/printf.c
	$(CC) ${COPTS} -o $@ $^

8/array: 8/array.c
	$(CC) ${COPTS} -o $@ $^

9/comments: 9/comments.c
	$(CC) ${COPTS} -o $@ $^

9/genius: 9/genius.c
	$(CC) ${COPTS} -o $@ $^

9/self_explanatory: 9/self_explanatory.c
	$(CC) ${COPTS} -o $@ $^

10/sane: 10/sane.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

10/insane: 10/insane.c
	$(CC) ${COPTS} -Wno-unused -Wno-implicit-fallthrough \
		-o $@ $^

13/include.o: 13/include.c
	touch 13/my_file.h
	$(CC) ${COPTS} -c -o $@ $^
	rm 13/my_file.h

13/floatstuff.o: 13/floatstuff.c
	$(CC) ${COPTS} -c -o $@ $^

13/intstuff.o: 13/intstuff.c
	$(CC) ${COPTS} -c -o $@ $^

14/globals: 14/globals.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

# not in all (intentionally fails to compile)
14/namespaces: 14/namespaces.c
	$(CC) ${COPTS} -o $@ $^

15/return_parameter: 15/return_parameter.c
	$(CC) ${COPTS} -o $@ $^

15/malloc: 15/malloc.c
	$(CC) ${COPTS} -o $@ $^
	
15/const_size: 15/const_size.c
	$(CC) ${COPTS} -Wno-uninitialized -o $@ $^

17/messenger: 17/messenger.c
	$(CC) ${COPTS} -o $@ $^

17/typedef: 17/typedef.c
	$(CC) ${COPTS} -o $@ $^

18/enum: 18/enum.c
	$(CC) ${COPTS} -Wno-unused -o $@ $^

18/enum_vals.o: 18/enum_vals.c
	$(CC) ${COPTS} -c -o $@ $^

19/flip: 19/flip.c
	$(CC) ${COPTS} -o $@ $^

19/data_loss: 19/data_loss.c
	$(CC) ${COPTS} -o $@ $^

19/implicit: 19/implicit.c
	$(CC) ${COPTS} -o $@ $^

21/faulty: 21/faulty.c 21/faulty_string.c 21/string_utils.c
	$(CC) ${COPTS} -o $@ $^

21/correct: 21/correct.c 21/correct_string.c 21/string_utils.c
	$(CC) ${COPTS} -o $@ $^

20/generics: 20/generics.c
	$(CC) ${COPTS} -std=c11 -o $@ $^

23/string_reverse: 23/string_reverse.c
	$(CC) ${COPTS} -o $@ $^

24/fixsizeint: 24/fixsizeint.c
	$(CC) ${COPTS} -o $@ $^

24/evil_goto: 24/evil_goto.c
	$(CC) ${COPTS} -o $@ $^

24/float: 24/float.c
	$(CC) ${COPTS} -o $@ $^

24/cstrings: 24/cstrings.c
	$(CC) ${COPTS} -o $@ $^

24/static: 24/static.c
	$(CC) ${COPTS} -o $@ $^

clean:
	rm -f */*.o
