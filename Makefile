all: t9search numeromaker filebuilder
t9search: t9search.c
	gcc -std=c99 -Wall -Wextra -Werror -o t9search t9search.c -I.
numeromaker: numeromaker.c
	gcc -std=c99 -Wall -Wextra -Werror -o numeromaker numeromaker.c -I.
filebuilder: filebuilder.c
	gcc -std=c99 -Wall -Wextra -Werror -o filebuilder filebuilder.c -I.

