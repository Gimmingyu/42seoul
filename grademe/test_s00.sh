#!/bin/bash
# version : 0.3

if [ "$1" != "nc" ]
then
  CYAN='\033[1;36m'
  LCYAN='\033[0;34m'
  GRAY='\033[1;30m'
  NC='\033[0m' # No Color
  PURPLE='\033[0;32m'
fi

function printline()
{
  echo -e ${GRAY}'------------------------------------------------------------'${NC}
}

function printsharp()
{
  echo "##"
}

function printdoubleline()
{
  echo ""
  echo ""
  echo ""
  echo '============================================================'
}
function printhead()
{
  printdoubleline
  echo -e ${CYAN}'##' "$1" 테스트를 시작합니다.${NC}
}
function printmsg()
{
  echo ""
  echo '>>>' "$1"
}
function printcontent()
{
  echo '##' 실행 명령 : "$1"
  eval $1
}

function test
{
  testname=$1
  filename=$2
  desc="$3"
  testexecute="$4"
  exampleresult="$5"

  printhead $testname
  cd $testname

  if [ "$filename" != "" ]
  then
    printline
    echo -e ${LCYAN}"##" 파일 이름: $filename ${NC}
    echo -e ${LCYAN}"## 파일 출력\n\n${NC}$(cat $filename)\n\n"
  fi

  if [ "$desc" != "" ]
  then
    printline
    echo -e ${LCYAN}"## 테스트 방법: $desc\n## 테스트 결과\n"${NC}
    eval "$testexecute"
    echo -e "\n\n"
  fi
  if [ "$exampleresult" != "" ]
  then
    printline
    echo -e ${LCYAN}"## 문제지(pdf)에서의 예제 결과${NC}\n\n$exampleresult\n\n"
  fi
  # printline
  # echo $?
  # echo "hi!!"
  cd ..

}

function tests
{
  test ex00 z "cat z 실행" "cat z" \
'?>cat z
Z
?>'


  test ex01 "" "압축해제 후 ls -l 실행" \
    'tar -xf testShell00.tar ;
    mv testShell00.tar .. ;
    ls -l ;
    mv ../testShell00.tar . ;
    chmod 777 testShell00 ;
    rm testShell00' \
'%> ls -l
total 1
-r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell00
%>'


  test ex02 "" "압축해제 후 ls -l 실행" \
    'tar -xf exo2.tar ;
    mv exo2.tar .. ;
    ls -l ;
    mv ../exo2.tar . ;
    chmod 777 test* ;
    rm -r test*' \
'%> ls -l
total XX
drwx--xr-x 2 XX XX XX Jun 1 20:47 test0
-rwx--xr-- 1 XX XX  4 Jun 1 21:46 test1
dr-x---r-- 2 XX XX XX Jun 1 22:45 test2
-r-----r-- 2 XX XX  1 Jun 1 23:44 test3
-rw-r----x 1 XX XX  2 Jun 1 23:43 test4
-r-----r-- 2 XX XX  1 Jun 1 23:44 test5
lrwxr-xr-x 1 XX XX  5 Jun 1 22:20 test6 -> test0
%>'


  test ex03 klist.txt "" "" ""


  test ex04 midLS "파일 적절히 생성 후 /bin/sh midLS 실행" \
    'printmsg "파일 생성 결과" ;
    touch t_first t_second t_third ;
    mkdir t_something_folder ;
    cd t_something_folder ;
    touch t_yes t_no ;
    cd .. ;
    touch t_oldest ;
    touch -t 201012311200 t_oldest ;
    touch -t 205012211200 t_newest ;
    ls -ltU ;

    printmsg "명령 실행 결과" ;
    /bin/sh midLS ;
    rm -r t_*'


  test ex05 git_commit.sh "bash git_commit.sh | cat -e 실행" \
    'bash git_commit.sh | cat -e ;
    printmsg "참고사항 (아래는 현재 저장소의 git log 최근 3개)" ;
    git log -3 | cat' \
'%> bash git_commit.sh | cat -e
baa23b54f0adb7bf42623d6d0a6ed4587e11412a$
2f52d74b1387fa80eea844969e8dc5483b531ac1$
905f53d98656771334f53f59bb984fc29774701f$
5ddc8474f4f15b3fcb72d08fcb333e19c3a27078$
e94d0b448c03ec633f16d84d63beaef9ae7e7be8$
%>'


  test ex06 git_ignore.sh ".gitignore 파일 생성 후, tg_a, tg_b, tg_c 추가 후, bash git_ignore.sh | cat -e 실행하여 결과 확인" \
    'cd .. ;
    echo -e "tg_a\ntg_b\ntg_c" > .gitignore ;
    cd ex06 ;
    touch tg_a tg_b ;
    mkdir tg_c ;
    cd tg_c ;
    touch tg_d tg_e ;
    cd ..
    bash git_ignore.sh | cat -e
    cd ..
    rm .gitignore
    cd ex06
    rm -r tg_*
    ls' \
'%> bash git_ignore.sh | cat -e
.DS_Store$
mywork.c~$
%>'


  test ex07 b "" "" ""
  test ex08 clean "적절한 파일 생성후, /bin/sh clean 실행" \
    'printmsg "각종 파일 생성" ;
    touch t_normal "t_some~" "t_some#" "#t_some#" ;
    mkdir t_f ;
    cd t_f ;
    touch "#t_dumb#" "~t_dumb~" ;
    cd .. ;
    ls -lR ;
    printmsg "명령 실행 출력 결과" ;
    /bin/sh clean ;
    printmsg "명령 실행 이후 디렉토리";
    ls -lR ;
    rm -r *t_* ;
    ls'
  test ex09 ft_magic "적절한 파일 생성, 매직 파일 컴파일 후 적용 결과 확인" \
    'printmsg "something 에서 감지되어야 함." ;
    file -C -m ft_magic ;
    echo 0000000000111111111122222222223333333333442 > something ;
    file -m ft_magic * ;
    rm *.mgc something ;
    cd ..'
}


echo -e '본 테스트 스크립트가 잘못되어 있을 수도 있으니,
결과가 이상하다면 슬랙으로 꼭 공유해주세요.
결과가 너무 길다면 bash test_s01.sh nc > test_result.txt 를 실행하세요
'$NC

tests