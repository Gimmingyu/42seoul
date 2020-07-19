gcc main.c lib.c puzzle.c validation.c io.c
./a.out "4" "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
echo "\n----------------------------------\n"
echo "1 2 3 4$\n2 3 4 1$\n3 4 1 2$\n4 1 2 3$\n"
