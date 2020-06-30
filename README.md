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
#### 커버로스 프로토콜(Kerberos Protocol)
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
    ```# drwxr-xr-x    2    101620    4220    4096    2020-06-29    16:02    Hello.c```
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
## git

## cat

## find
</details>
