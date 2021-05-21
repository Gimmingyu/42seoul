# Push_Swap
* Grade: 105 / 100 (mandatory 100 + bonus 5)

### Summary
1. Objective
   * coding a very simple and highly effective sort algorithm, push_swap
   * Allowed functions: `write` `read` `malloc` `free` `exit`
   * Not allowed functions: `Segmentation fault` `bus error` `double free` `memory leaks`
2. **Mandatory Part**: make `push_swap` program
   * This is composed of 2 stack named `a` and `b`
     * `a` contains a random number of either positive or negative numbers without any duplicates
     * `b` is empty
   * sort in ascending order numbers into stack `a` using command
     ```
     sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
     sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
     ss : sa and sb at the same time.
     pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
     pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
     ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
     rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
     rr : ra and rb at the same time.
     rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
     rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
     rrr : rra and rrb at the same time.
     ```
4. **Bonus Part**: make `checker` program
   * If this algorithm is really effective
   *  and checker program runs really well, 
   *  you can get bunus point
   ```
   In my case, the checker program works well,
   but it is not efficient algorithm perfectly
   so I got 5 bonus out of 25
   (efficient score: 3/5)
   ```

---

### Tester
* There's few testers, so I just make very simple tester: [`checker_tester.sh`](./checker_tester.sh)
* if you want to get random numbers, follow this one:
  ```
  1) generate random value using this site: https://www.minzkn.com/random.html
  2) copy and paste the numbers in [checker_random_values.py] > nums(list type)
  3) run [checker_random_values.py]
  4) copy and paste the result in [checker_tester.sh]
  ```
