## Exercise 00: Exam
알아서 등록하기!
<br>

## Exercise 01: print_groups
```bash
mkdir ex01
cd ex01
vi print_groups.sh    # print_groups.sh 내용은 아래 참고
chmod 777 print_groups.sh
./print_groups.sh     # checking
```
```bash
# print_groups.sh 내용
groups $FT_USER | tr " " "," | cat -e | cut -d "$" -f 1
```
