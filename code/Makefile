CC = cc
COPTS = -std=c99 -pedantic -Wall -Wextra -Werror -g
TARGET_PATH = target

all: ${TARGET_PATH}\
	1_barebones \
	2_constants 2_variables\
	3_functions\
	4_increment_basic 4_increment_return\
	5_if 5_else 5_else_if 5_no_brackets 5_switch 5_boolean 5_logical\
	6_while 6_do_while 6_for 6_loop_control\
	7_printf\
	8_array\
	9_comments 9_genius 9_self_explanatory\
	10_sane 10_insane\
	12_include.o 12_floatstuff.o 12_intstuff.o\
	13_globals\
	14_return_parameter 14_malloc 14_const_size\
	15_messenger 15_typedef\
	16_enum 16_enum_vals.o\
	17_flip 17_data_loss 17_implicit\
	19_faulty 19_correct\
	20_generics\
	21_string_reverse\
	22_evil_goto 22_float 22_cstrings

1_barebones: 1_barebones.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

2_constants: 2_constants.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

2_variables: 2_variables.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

3_functions: 3_functions.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

4_increment_basic: 4_increment_basic.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

4_increment_return: 4_increment_return.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

5_if: 5_if.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

5_else: 5_else.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

5_else_if: 5_else_if.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

5_no_brackets: 5_no_brackets.c
	$(CC) ${COPTS} -Wno-uninitialized -o ${TARGET_PATH}/$@ $^

5_switch: 5_switch.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

5_boolean: 5_boolean.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

5_logical: 5_logical.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

6_while: 6_while.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

6_do_while: 6_do_while.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

6_for: 6_for.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

6_loop_control: 6_loop_control.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

7_printf: 7_printf.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

8_array: 8_array.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

9_comments: 9_comments.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

9_genius: 9_genius.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

9_self_explanatory: 9_self_explanatory.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

10_sane: 10_sane.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

10_insane: 10_insane.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

12_include.o: 12_include.c
	touch my_file.h
	$(CC) ${COPTS} -c -o ${TARGET_PATH}/$@ $^
	rm my_file.h

12_floatstuff.o: 12_floatstuff.c
	$(CC) ${COPTS} -c -o ${TARGET_PATH}/$@ $^

12_intstuff.o: 12_intstuff.c
	$(CC) ${COPTS} -c -o ${TARGET_PATH}/$@ $^

13_globals: 13_globals.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

# not in all (intentionally fails to compile)
13_namespaces: 13_namespaces.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

14_return_parameter: 14_return_parameter.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

14_malloc: 14_malloc.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^
	
14_const_size: 14_const_size.c
	$(CC) ${COPTS} -Wno-uninitialized -o ${TARGET_PATH}/$@ $^

15_messenger: 15_messenger.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

15_typedef: 15_typedef.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

16_enum: 16_enum.c
	$(CC) ${COPTS} -Wno-unused -o ${TARGET_PATH}/$@ $^

16_enum_vals.o: 16_enum_vals.c
	$(CC) ${COPTS} -c -o ${TARGET_PATH}/$@ $^

17_flip: 17_flip.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

17_data_loss: 17_data_loss.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

17_implicit: 17_implicit.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

19_faulty: 19_faulty.c 19_faulty_string.c 19_string_utils.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

19_correct: 19_correct.c 19_correct_string.c 19_string_utils.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

20_generics: 20_generics.c
	$(CC) ${COPTS} -std=c11 -o ${TARGET_PATH}/$@ $^

21_string_reverse: 21_string_reverse.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

22_evil_goto: 22_evil_goto.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

22_float: 22_float.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

22_cstrings: 22_cstrings.c
	$(CC) ${COPTS} -o ${TARGET_PATH}/$@ $^

clean:
	rm -f ${TARGET_PATH}/*

${TARGET_PATH}:
	mkdir ${TARGET_PATH}
