## Exercise 00: Z
```
mkdir ex00
cd ex00
vi Z          # Z 입력
```

## Exercise 01: testShell00
[#파일크기지정](README.md#특정-크기로-지정하여-파일-만들기), [#chmod](../README.md#chmod-change-mode)
```
mkdir ex01
cd ex01
dd if=/dev/zero of=testShell00 bs=4M count=40
chmod 455 testShell00
tar -cf testShell00.tar testShell00
rm testShell00
```

## Exercise 02: Oh yeah, mooore...
