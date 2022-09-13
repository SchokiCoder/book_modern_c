all: faulty-code correct-code

faulty-code:
	cc "$@.c" "faulty_string.c" "string_utils.c" -o "$@" -g -Wall -Wextra

correct-code:
	cc "$@.c" "correct_string.c" "string_utils.c" -o "$@" -g -Wall -Wextra