## Exercise 00: Z
```bash
mkdir ex00
cd ex00
vi Z          # Z 입력
```
<br>

## Exercise 01: testShell00
[#파일크기지정](README.md#특정-크기로-지정하여-파일-만들기), [#chmod](../README.md#chmod-change-mode)
```bash
mkdir ex01
cd ex01
dd if=/dev/zero of=testShell00 bs=4M count=40
chmod 455 testShell00
tar -cf testShell00.tar testShell00
rm testShell00
```
<br>

## Exercise 02: Oh yeah, mooore...
[#파일크기지정](README.md#특정-크기로-지정하여-파일-만들기), [#chmod](../README.md#chmod-change-mode), [#hard_symbolic_link](../README.md#hard-symbolic-link)
```bash
mkdir ex02
cd ex02

# test0, test2
mkdir test0
ln test0 test2
chmod 715 test0
chmod 504 test2

# test1
dd if=/dev/zero of=test1 bs=4M count=4
chmod 714 test1

# test3, test5
dd if=/dev/zero of=test3 bs=4M count=1
chmod 404 test3
ln test3 test5

# test4
dd if=/dev/zero of test4 bs=4M count=2
chmod 541 test4

# test6
ln -s test0 test6
chmod 755 test6

# compressing & delete origin files(test0~test6)
tar -ef exo2.tar *
rm -rf test0 test1 test2 test3 test4 test5 test6
```
<br>

## Exercise 03: Connect me!
[#klist](../README.md#klist)
```bash
klist -l > klist.txt
```
<br>

## Exercise 04: midLS
[#ls](../README.md#ls)
```bash
vi midLS    # midLS 내용은 아래 참고
```
```bash
# midLS 내용
ls -p -m
```
<br>

## Exercise 05: GiT commit
[#git](../README.md#git)
```bash
vi git_comment  # git_comment 내용은 아래 참고
```
```bash
# git_comment 내용
git log -n 5 --pretty=format:"%H"
echo ""
```
<br>

## Exercise 06: gitignore
[#git](../README.md#git)
```bash
vi gitignore    # gitignore 내용은 아래 참고
```
```bash
# gitignore 내용
git ls-files . --exclude-standard --ignored
```


<br>

## Exercise 07: diff
[#cat](../README.md#cat)
```bash
vi a      # a 내용은 아래 참고
vi b      # b 내용은 아래 참고
diff a b > sw.diff
rm a b
```
```bash 
# a 내용
STARWARS
Episode IV, A NEW HOPE It is a period of civil war.

Rebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire.
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the DEATH STAR,
an armored space station with enough power to destroy an entire planet.

Pursued by the Empire's sinister agents, Princess Leia races home aboard her starship, custodian of the stolen plans that can save her people and restore freedom to the galaxy...
```
```bash
# b 내용
Episode V, A NEW H0PE It is a period of civil war
Rebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire. 
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the STAR DEATH, an armored space station with enough power to destroy an entire planet.


Pursued by the Empire's sinister agents,
Princess Mehdi races home aboard her starship, custodian of the stolen plans that can save her people and restore the dictatorship to the galaxie..



```
<br>

## Exercise 08: clean
[#find](../README.md#find)
```bash
mkdir ex08
cd ex08
vi clean    # clean 내용은 아래 참고
```
```bash
# clean 내용
find . \( -type f -name "*~" -o -name "#*" \) -print -delete
```
<br>

## Exercise 09: Illusion, not tricks, Michael...
```bash
vi ft_magic   # ft_magic 내용은 아래 참고
```
```bash
# ft_magic 
41 string 42  42 file
```
