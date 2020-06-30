# 42seoul
2기 1차: 이노베이션 아카데미 Piscine

<details>
<summary>Shell: 파일크기지정, chmod, hard_symbolic_link, klist, ls, git, cat, find </summary>
 
## 특정 크기로 지정하여 파일 만들기(파일크기지정)

```dd if=/dev/zero of=[file name] bs=[read size] count=[file size]```
* ```/dev/zero```의 특수 장치에서 ```bs```만큼 지정된 사이즈 씩 읽어서 ```count```의 크기를 지닌 파일을 생성
* ```dd if=/dev/zero of=test_file.img bs=4M count=256```: ```/dev/zero```에서 ```4M```씩 읽어서 ```256M```의 크기를 지닌 ```test_file.img``` 생성


## chmod: CHange MODe
* 대상 파일과 디렉토리의 사용권한을 변경할 때 사용
* ```chmod [option] [mode] [file]```
* ```ls -l```로 현재 파일들이 어떤 허가를 받았는지 볼 수 있음
  * ```-rwxr-xr-x```: 파일 접근 권한 분류 표기로, 처음 -는 파일 분류 타입
  * 파일 타입
    * ```d```: 디렉토리
    * ```l(소문자 L)```: 링크 카운터
    * ```s```: 소켓
    * ```p```: 파이프
    * ```-```: 일반
    * ```c```: 특수문자
    * ```b```: 특수블록
1. option
   * ```-r```: 하위 파일과 디렉토리 모든 권한 변경
   * ```-v```: 실행되고 있는 모든 파일을 나열
   * ```-c```: 권한이 변경된 파일 내용 출력
2. mode
   1. 문자열 모드: ```chmod [option] [(reference) (operator) (modes)] [file]```
      * reference(대상)
        * ```u```: user의 권한(사용자의 권한)
        * ```g```: group의 권한(파일의 group 멤버인 사용자의 권한)
        * ```o```: other의 권한(user, group의 멤버가 아닌 사용자의 권한)
        * ```a```: all의 권한(위의 셋을 포함하는 모든 사용자의 권한)
      * operator
        * ```+```: 해당 권한 추가
        * ```-```: 해당 권한 제거
        * ```=```: 해당 권한을 설정한대로 변경
      * modes:
        * ```r```: read 권한(읽기)
        * ```w```: write 권한(쓰기)
        * ```x```: excute 권한(실행)
        * ```-```: 사용권한 없음
   ```
   chmod ug+rw sample       # sample파일의 user나 group 멤버들에게 읽기,쓰기 권한 추가
   chmod u=rwx,g+x sample   # sample파일의 user는 읽기,쓰기,실행 권한 부여 / group 멤버들에게 실행권한 추가
   ```
   2. 8진법 수 모드: ```chmod [option] (8진법 수) [file]```
      * 예제로 알아보자: ```rwxr-xrw-```
        * ```r```: 파일 읽기. 4
        * ```w```: 파일 쓰기. 2
        * ```x```: 파일 실행. 1
        * 처음 3개 문자 ```rwx```: user의 권한
        * 중간 3개 문자 ```r-x```: group의 권한
        * 마지막 3개 문자 ```rw-```: other의 권한
      * 특수 권한
        * ```777```: 일반적인 8진법 형태
        * ```4777```: SetUid 설정 때 4000을 더함
        * ```2777```: SetGid 설정 때 2000을 더함
        * ```1777```: Sticky bit 설정 때 1000을 더함
      ```
      chmod 777 test   # test파일의 user, group, other의 권한을 모두 rwx로 변경
      chmod 4755 test  # test파일의 user id설정을 지정하고, user에게 rwx 권한 부여, group과 other에게 r-x권한 부여
      ```
3. file
변경 설정을 할 파일이나 디렉토리

## Hard-Symbolic Link
윈도우로 치면 "바로가기" 같은 개념이다. 리눅스에도 특정 파일이나 디렉터리에 링크 기능을 제공하는데, 제목에서 보다시피 두 가지가 있다.<br>두 개 모두 처리하는 역할은 같지만 개념은 다르다.
```
하드 링크(hard link)
심볼릭 링크(symbolic link)
```
1. 하드 링크(hard link)
   * 원본 파일과 동일한 inode를 가진다<br>: 원본 파일이 삭제되더라도 원본 파일의 inode를 갖고 있는 링크 파일은 여전히 사용 가능
   * 같은 inode를 가르키는 서로 다른 이름이라고 생각해도 될 듯. 원본이라는 개념이 없음
   * 아래의 예제에서 ```test```의 inode인 ```787314```를 ```bbbb```도 동일하게 사용하는 것을 알 수 있다.
   ```bash
   echo "This is a test file" > test
   ls -ali test
   # 787314    -rw-r--r--    1    root    root    18    2020-06-29    15:23    test
  
   ln -s test aaaa    # make symbolic link file
   ln test bbbb       # make hard link file
   ls -ali
   # 787313    drwxr-xr-x    2    root    root    4096    2020-06-29    15:25    .
   # 787311    drwxr-xr-x    3    root    root    4096    2020-06-29    15:23    ..
   # 787316    lrwxrwxrwx    1    root    root       4    2020-06-29    15:24    aaaa -> test
   # 787314    -rw-r--r--    2    root    root      18    2020-06-29    15:24    bbbb
   # 787314    -rw-r--r--    2    root    root      18    2020-06-29    15:23    test
   ```
2. 심볼릭 링크(symbolic link)
   * 원본 파일의 이름을 가리키는 링크=원본 파일이 사라지면 망가짐
   * 전혀 다른 파일이라도 원본 파일과 이름이 같다면 계속 사용이 가능함<br>주로 dynamic library의 so 파일과 연계해서 사용
   * 아래 예제에서 ```aaaa```는 링크가 깨져서 접근이 불가. ```bbbb```는 사용 가능
   * ```aaaa```를 다시 사용하기 위해서는 ```test```라는 이름을 가진 파일을 생성하면 된다.
   ```bash
   rm -rf test
   ls -ali
   # 787313    drwxr-xr-x    2    root    root    4096    2020-06-29    15:25    .
   # 787311    drwxr-xr-x    3    root    root    4096    2020-06-29    15:23    ..
   # 787316    lrwxrwxrwx    1    root    root       4    2020-06-29    15:24    aaaa -> test
   # 787314    -rw-r--r--    1    root    root      18    2020-06-29    15:24    bbbb
   
   cat aaaa
   # cat: aaaa: 그런 파일이나 디렉터리가 없습니다
   
   cat bbbb
   # This is a test file
   ```

## klist

## ls

## git

## cat

## find
</details>
