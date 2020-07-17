# 42seoul: La Piscine C [![See & Run on Repl.it](https://repl.it/badge/github/kimkyeongnam/42seoul)](https://repl.it/github/kimkyeongnam/42seoul)
2기 1차: 이노베이션 아카데미 Piscine

## TOC
* C language
  * [Compile](#compile)
    * [gcc](#1-gcc-moulinette는-gcc로-c언어를-컴파일함)
    * [norminette](#2-norminette-moulinette가-사용하는-플래그인--r-checkforbiddensourceheader를-사용할-수-있음)
    * [42 header](#3-42-header-파일-생성-시-꼭-만들어야-하는-header)
  * [Coding Rule](#coding-rule)
* Shell
  * [괄호](#괄호)
  * [파일크기지정](#특정-크기로-지정하여-파일-만들기파일크기지정)
  * [cat](#cat)
  * [cut](#cut)
  * [chmod](#chmod)
  * [file](#file)
  * [find](#find)
  * [git](#git)
  * [groups](#groups)
  * [hard-symbolic link](#hard-symbolic-link)
  * [klist](#klist)
  * [ls](#ls)
  * [tar](#tar)
  * [tr](#tr)
* Etc
  * [Mac](#mac)
  * [Vim](#vim) 

<br><br>

<details>
<summary>C language</summary>
 
## Compile 
* 42에서는 **Moulinette**라는 프로그램으로 과제물을 확인하고 평가한다
* 42에서 c언어 코드를 돌리기 위해서는 ```gcc```, ```norminette``` 둘 다 오류없이 통과해야 한다.
#### 1. gcc: Moulinette는 ```gcc```로 c언어를 컴파일함
```bash
gcc -Wall -Wextra -Werror main.c [c파일1] [c파일2] [c파일3] ...
./a.out    # 원하는 결과가 나오면 통과
```

#### 2. norminette: **Moulinette**가 사용하는 플래그인 ```-R CheckForbiddenSourceHeader```를 사용할 수 있음 
```bash
norminette -R CheckForbiddenSourceHeader main.c [c파일1] [c파일2] [c파일3] ...

# 입력 파일들 모두 별 다른 에러 없이 출력되면 성공
Norme: ./main.c
Norme: ./[c파일1]
Norme: ./[c파일2]
Norme: ./[c파일3]
```

#### 3. 42 header: 파일 생성 시 꼭 만들어야 하는 header
* 파일을 vim으로 생성하고 ```:Stdheader``` 입력
* 만들면 자신의 정보가 담긴 주석이 만들어진다. 업데이트 시간은 알아서 수정되니 만들기만 하고 신경은 쓰지 않아도 된다
  ```
  /* ************************************************************************** */
  /*                                                                            */
  /*                                                        :::      ::::::::   */
  /*   ft_putchar.c                                       :+:      :+:    :+:   */
  /*                                                    +:+ +:+         +:+     */
  /*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
  /*                                                +#+#+#+#+#+   +#+           */
  /*   Created: 2020/07/06 09:37:29 by kyekim            #+#    #+#             */
  /*   Updated: 2020/07/06 11:30:35 by kyekim           ###   ########.fr       */
  /*                                                                            */
  /* ************************************************************************** */

  ```

## Coding Rule
* 사용 금지 함수를 사용하면 부정 행위로 간주됨. -42점이 부여되며, 받은 점수는 절대로 수정 불가능
* 꼭! 반드시 지키도록 하자!!
* **Intra의 돋보기 섹션 >  42 학업 관련 자료 / Norm && Norminette** 에서도 확인이 가능함
1. Conventions de denomination
2. Formatage
   * 모든 파일은 42헤더로 시작: [#42header](#3-42-header-파일-생성-시-꼭-만들어야-하는-header) 참고
   * 들여쓰기는 공백 네 칸 크기의 탭으로 이루어져야 함. 띄어쓰기가 아닌 진짜 탭으로 구성
     * ```#include <unistd.h>```:
     * ```void    함수명(변수)```: 탭 한 번 
     * ```int     main(void)```: 탭 두 번. int형같이 4글자보다 부족한 경우에는 한번 더 해야하는 듯
   * 모든 함수는 함수 자체의 중괄호를 제외하고 25줄 이하
      * 중괄호가 있는 줄은 중괄호만 존재해야 함
        ```
        int     main(void)
        {
            ft_putchar('h');
            return (0);
        }
        ```
   

</details>

<details>
<summary>Shell</summary>

## 괄호
* 코멘드라인에서는 괄호가 제대로 안먹힌다!
* ```(``` 대신에 ```\(```
* ```)``` 대신에 ```\)```

## 특정 크기로 지정하여 파일 만들기(파일크기지정)
```dd if=/dev/zero of=[file name] bs=[read size] count=[file size]```
* ```/dev/zero```의 특수 장치에서 ```bs```만큼 지정된 사이즈 씩 읽어서 ```count```의 크기를 지닌 파일을 생성
* ```dd if=/dev/zero of=test_file.img bs=4M count=256```: ```/dev/zero```에서 ```4M```씩 읽어서 ```256M```의 크기를 지닌 ```test_file.img``` 생성

## cat
* 파일의 내용을 간단하게 출력하거나, 두 개 이상의 파일을 연결(concatenate)해서 출력할 때 사용
* ```cat [option] [filename1] [filename2] [filename3] ... ```
* option
  * ```-n```: 행 번호 표시. 비어있는 행도 포함
  * ```-b```: 행 번호 표시. 비어있는 행은 제외
  * ```-e```: 제어 문자를 ^ 형태로 출력하면서 각 행의 끝에 $ 추가
  * ```-s```: 연속되는 2개 이상의 빈 행을 한 행으로 출력
  * ```-v```: tab과 행 바꿈 문자를 제외한 제어 문자를 ^형태로 출력
  * ```-E```: 행마다 끝에 $ 문자 출력
  * ```-T```: tab 문자 출력
  * ```-A```: ```-vET```옵션과 같은 효과
  

## cut
* 파일에서 필드를 뽑아냄 = 문자 일부분 추출. 필드는 구분자로 구분 가능
* ```cut [option] [filename]
* option
  * ```-c 문자위치```: 잘라낼 곳의 글자 위치 지정. 콤마나 하이픈을 사용하여 범위를 정할 수 있음
  * ```-f 필드```: 잘라낼 필드 설정
  * ```-d 구분자```: 필드 구분 문자 지정(default: tab)
  * ```-s```: 필드 구분자를 포함할 수 없다면 그 행은 패스

## chmod
* CHange MODe
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

## file
* 파일의 종류를 확인하는 명령어
* 대상파일의 확장자와는 별개로 파일의 헤더를 읽어 매직파일의 내용을 참조하여 파일 종류를 알려줌
* ```file [option] [file path]```
* option
  * ```-c```: 매직파일의 포맷 검사
  * ```-f 목록파일```: 목록파일. 많은 파일을 한꺼번에 확인할 때 파일리스트인 목록파일을 만들어서 그 안에 입력된 파일들을 한꺼번에 확인
  * ```-m 매직파일```: 매직파일. 매직파일을 지정하여 확인
  * ```-z```: 압축된 파일 확인
  * ```-L```: 심볼릭 링크 파일 확인
* magic file
  * file은 magic file이라는 것을 이용해 파일에 접근함<br>=magic file이 없으면 파일분류가 되지 않음=매직파일 안에 파일분류를 위한 정보가 들어있음
  * 엔트리가 4개의 필드로 구성됨: ```[처음 혹은 이전 레벨로부터의 오프셋 값] [데이터 종류] [값] [출력 문자열] file```
  ```
  41 string 42 42 file
  ```

## find
* 파일 및 디렉토리를 검사할 때 사용
* ```find [option] [path] [expression]```
1. option
   * ```-P```: 심볼릭 링크를 따라가지 않고, 심볼릭 링크 자체 정보 활용
   * ```-L```: 심볼릭 링크에 연결된 파일 정보 사용
   * ```-H```: 심볼릭 링크를 따라가지 않으나, command line Argument를 처리할 땐 예외
   * ```-D```: 디버그 메시지 출력
2. path
   * ```.```: 현제 디렉토리 및 하위 디렉토리
   * ```/```: 전체 시스템(루트 디렉토리)
3. expression
   * ```-name```: 지정된 문자열 패턴에 해당하는 파일 검색
   * ```-empty```: 빈 디렉토리 또는 크기가 0인 파일 검색
   * ```-delete```: 검색된 파일 또는 디렉토리 삭제
   * ```-exec```: 검색된 파일에 대해 지정된 명령 실행
   * ```-path```: 지정된 문자열 패턴에 해당하는 경로에서 검색
   * ```-print```: 검색 결과 출력. 검색 항목은 newline으로 구분(default)
   * ```-print0```: 검색 결과 출력. 검색 항목은 null로 구분
   * ```-size```: 파일 크기를 사용하여 파일 검색
     * ```123```: 파일 크기가 123 바이트인 파일
     * ```+123```: 파일 크기가 123 바이트 초과인 파일
     * ```-123```: 파일 크기가 123 바이트 미만인 파일
   * ```-type```: 지정된 파일 타입에 해당하는 파일 검색
     * ```b```: block special
     * ```c```: character special
     * ```d```: directory
     * ```f```: regular file
     * ```l```: symbolic link
     * ```p```: FIFO
     * ```s```: socket
   * ```-mindepth```: 검색할 하위 디렉토리의 최소 깊이 지정
   * ```-maxdepth```: 검색할 하위 디렉토리의 최대 깊이 지정
   * ```-atime```: 파일 접근(access) 시각을 기준으로 파일 검색
   * ```-ctime```: 파일 내용 및 속성 변경(change) 시각을 기준으로 파일 검색
   * ```-mtime```: 파일의 데이터 수정(modify) 시각을 기준으로 파일 검색
   
## git

## groups

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
#### 커버로스 프로토콜
* Kerberos Protocol
* 티켓(ticket) 기반의 컴퓨터 네트워크 인증 프로토콜
* 보안이 보장되지 않은 네트워크 환경에서 **요청을 보내는 유저**와 **요청을 받는 서버**가 서로의 신뢰성을 확보하기 위해 사용
##### 티켓 사용 이유
* 유저의 아이디를 안전하게 전달하는 데 사용
  * 유저아이디 
  * 유저 호스트의 IP주소
  * 타임 스탬프(time stamp, 시간기록)
  * 티켓 수명을 정의하는 값
  * 세션 키
* 이러한 정보들을 담고 있는 티켓은 티켓을 발급하는 서버의 secret key로 encrypt됨
##### 단점
* 서버가 하나이기 때문에 서버가 다운될 경우, 새로운 유저는 로그인 할 수 없음<br>따라서 여러 개의 서버를 운용하는 등 서버가 작동하지 않을 때를 대비할 수 있는 메커니즘을 구현해야 함
* 요청 시간에 대한 요구가 엄격함(통상적으로 5분)<br>만약 요청을 주고받는 호스트들 간에 시간 동기화가 되어있지 않을 경우 통신이 불가능함 
##### 명령어
* ```kdestroy```
  * keberos ticket 삭제. 순차로 1개만 삭제하므로 여러 티켓이 있을 경우 주의
  * ```--all```옵션으로 모든 티켓 삭제 가능
* ```kinit```
  * keberos ticket 생성
  * ```kinit -p [your_principal]```형태로 default realm 외 티켓 생성 가능
    * principal 예시: ```your_id@your_realm```
  * ```kinit -t [your_keytab]```형태로 keytab을 이용한 티켓 생성 가능
* ```klist```
  * 만들어진 티켓 목록 확인
  * ```klist -l```로 모든 티켓 목록  확인 가능
  * ```klist -vA```로 모든 티켓 상세내용을 확인 가능(macOS: klist -vA, linux: klist -aA)
* ```ktutil```
  * keytab 생성/관리 기능
  * ```-k```로 keytab위치 지정
    * ```add```로 keytab 생성
      * ```-p```로 principal 기술
      * ```-e```로 encript type 지정
      * ```-V```로 version 기술
    * ```list```로 keytab 내용 확인
  * 사용할 수 있는 ip가 지정된 티켓과 달리 keytab의 경우 접근만 가능하면 쓸 수 있어 **다른 서버로 옮겨 사용이 가능**
  * ktutil 참고 링크: https://kb.iu.edu/d/aumh
  
## ls
* 현재 폴더의 하위 디렉토리의 리스트를 보여줌
* 옵션들은 조합하여 사용할 수 있음: ```ls -al```(옵션 설명은 밑에 참고)
* ```ls [option]```
  * ```-a```: all. 숨겨진 파일들을 모두 보여줌. 숨겨진 파일은 앞에 ```.(마침표)```가 붙음
  * ```-l```: long. 파일권한, 생성 날짜 등의 파일에 대한 자세한 정보를 출력
    ```bash
    -rw-r--r--   1   kyekim   2020_seoul   4096   2020-06-29   16:01   Desktop
    # [파일권한] [하드링크 수] [소유자] [그룹정보] [파일크기(byte)] [최근 수정된 날짜 및 시간] [파일이름]
    ```
  * ```--block-size=크기단위```: 파일 크기를 원하는 단위로 변경
    * 파일 크기를 메가바이트로 표현하고 싶을 때 ```ls -l --block-size=M``` 입력 
      |명령어|단위|
      |:--:|:--:|
      |K|킬로바이트|
      |M|메가바이트|
      |G|기가바이트|
      |T|테라바이트|
      |P|페타바이트|
      |E|엑사바이트|
      |Z|제타바이트|
      |Y|요타바이트|
  * ```-h```: 사람(human)이 보기 편한 파일 사이즈로 자동으로 단위가 변환됨
  * ```-S```: 파일을 크기 순으로 정렬. 대문자로 사용할 것. 그런데 이것만 쓰면 **아무것도 안나옴**
    * 일반적인 ```ls```명령어는 파일 크기를 표시하지 않음
    * 따라서 ```ls -lhS```라고 써야 명령어 적용됨
  * ```-d */```: 파일을 제외한 디렉토리만 반환
  * ```-g```: 소유자 정보를 제외하고 출력. 그룹명은 표시
    ```
    -rw-r--r--   1   root   4096   2020-06-29   16:01   Desktop
    ```
  * ```-lG```: 그룹명만 제외하고 파일 조회. G만 쓰면 조회 안됨
  * ```~```: home 디렉토리의 파일을 모두 표시
  * ```../```: 부모 디렉토리 표시
  * ```-n```: 소유자 및 그룹의 이름 대신 ID 출력
    ```
    drwxr-xr-x    2    101620    4220    4096    2020-06-29    16:02    Hello.c
    ```
  * ```-p```: 디렉토리 뒤에만 ```/```기호를 삽입하여 해당 파일의 종류가 디렉토리인지 표시함
  * ```-F```: 파일의 종류를 기호로 구분
    * ```/```: 디렉토리
    * ```*```: 실행 가능 파일
    * ```@```: 기호 링크
  * ```-r```: 알파벳 역순(reverse)로 리스트 출력. 한글은 ㄱㄴㄷ 순서의 역순으로 출력
  * ```-R```: 하위 디렉토리까지 모두 표시
  * ```-t```: 최근 수정된 파일을 순서대로 정렬
  * ```-u```: 최근 엑세스된 날짜를 순서대로 정렬
  * ```--version```: ls 명령어의 버전 조회
  * ```-m```: 파일 사이를 쉼표로 구분
  
## tar
* Tape ARchiver
* 여러 개의 파일을 하나의 파일로 묶거나 풀 때 사용하는 명령어
* 보통 "tar로 압축(compress)한다"고 하는데, 정확히 말하면 tar 자체는 **"데이터의 크기를 줄이기 위한 파일 압축"** 을 수행하지 않음
  * tar를 통해 하나로 합쳐진 파일을 gzip 또는 bzip2 방식을 사용하여 압축할 수 있는데,<br>이때 gzip 또는 bzip 명령어를 따로 수행하지 않고 tar명령의 옵션으로 처리 가능 
  * "tar로 압축한다"는 표현이 그래서 아주 잘못된 표현은 아님
* 보통 ```.tar``` 확장자 사용
  * gzip으로 압축된 경우: ```.tar.gz```, ```.tgz```
  * bzip2로 압축된 경우: ```.tar.bzip2```, ```.tb2```, ```.tbz```, ```tbz2```
* tar로 묶여지기 전 파일들의 속성과 심볼릭 링크, 디렉토리 구조 등을 그대로 가져갈 수 있음
* ```tar [option] [file]```
* option
  * ```-f```: 대상 tar 아카이브 지정 (default option) 
  * ```-c```: tar 아카이브 생성. 기존 아카이브 덮어 쓰기 (파일 묶을 때 사용)
  * ```-x```: tar 아카이브에서 파일 추출 (파일 풀 때 사용)
  * ```-v```: 처리되는 과정(파일 정보)을 자세하게 나열
  * ```-z```: gzip 압축 적용 옵션
  * ```-j```: bzip2 압축 적용 옵션
  * ```-t```: tar 아카이브에 포함된 내용 확인
  * ```-C```: 대상 디렉토리 경로 지정
  * ```-A```: 지정된 파일을 tar 아카이브에 추가
  * ```-d```: tar 아카이브와 파일 시스템 간 차이점 검색
  * ```-r```, ```-u```: tar 아카이브의 마지막에 파일들 추가
  * ```-k```: tar 아카이브 추출 시, 기존 파일 유지
  * ```-U```: tar 아카이브 추출 전, 기존 파일 삭제
  * ```-w```: 모든 진행 과정에 대해 확인 요청 (interactive)
  * ```-e```: 첫 번째 에러 발생 시 중지
  
## tr

</details>

<details>
<summary>Etc</summary>

## Mac
|동작|세부동작|단축키|
|:--:|:--:|:--:|
|캡쳐|전체|Command + Shift + Control + 3|
||선택영역|Command + Shift + 4|
||선택창|Command + Shift + 4, 캡처할 창에 커서를 올리고 Space, 클릭|

## Vim
|동작|단축키|
|:--:|:--:|
|줄 지우기|명렁, DD|
</details>