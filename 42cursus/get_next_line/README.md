# get_next_line (GNL)
* Grade: 115 / 100 (mandatory 100 + bonus 15)

### Summary
1. Objective
   * coding a function that returns a line ending with a newline, read from a file descriptor
   * the functions will be allowed to use in all other projects
2. List of funtions
   * **Mandatory Part**: [`get_next_line.h`](./get_next_line.h) [`get_next_line.c`](./get_next_line.c) [`get_next_line_utils.c`](./get_next_line_utils.c)
     * **_function description_** : returns a line read from a file descriptor, without the newline
     * **_compile option_** : 
       ```
       gcc -Wall -Wextra -Werror `-D BUFFER_SIZE=32` get_next_line.c get_next_line_utils.c
       ```
     * since [libft](../libft) is not allowed, up to 5 functions can be added in `get_next_line_utils.c`

     
   * **Bonus Part**: [`get_next_line_bonus.h`](./get_next_line_bonus.h) [`get_next_line_bonus.c`](./get_next_line_bonus.c) [`get_next_line_utils_bonus.c`](./get_next_line_utils_bonus.c)
     * **_requirement 1_**: to succeed get_next_line with a single static variable.
     * **_requirement 2_**: to be able to manage multiple file descriptors with get_next_line without losing the reading thread on each of the descriptors.
---

### Tester
* [libftest](https://github.com/jtoty/Libftest)
    ```
    git clone https://github.com/jtoty/Libftest.git
    ```
* [unit test](https://github.com/alelievr/libft-unit-test)
    ```
    git clone https://github.com/alelievr/libft-unit-test.git
    ```
* [war machine](https://github.com/ska42/libft-war-machine)
    ```
    git clone https://github.com/ska42/libft-war-machine.git
    ```


* [gnlkiller](https://github.com/DontBreakAlex/gnlkiller)
  ```
  git clone https://github.com/DontBreakAlex/gnlkiller.git ; cd gnlkiller; cp ../get_next_line.c .; cp ../get_next_line_utils.c .; cp ../get_next_line.h .; ./run.sh;
  ```
* [GNL_lover](https://github.com/charMstr/GNL_lover)
  ```
  git clone https://github.com/charMstr/GNL_lover.git
  ```
* [gnl-war-machine](https://github.com/Alexandre94H/gnl-war-machine-v2019)
  ```
  git clone https://github.com/Alexandre94H/gnl-war-machine-v2019.git
  ```
* [42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)
  ```
  git clone https://github.com/Mazoise/42TESTERS-GNL.git
  ```
