#!/bin/bash

function printline()
{
  echo '------------------------------------------------------------'
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
  echo '##' "$1" 테스트를 시작합니다.
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
  
  printhead $testname
  cd $testname

  if [ "$filename" != "" ]
  then
    printline
    echo "##" 파일 이름: $filename
    echo "## 파일 출력"
    echo ""
    cat $filename 
    echo ""
    echo ""
  fi
  printline
  echo "## 테스트 방법: $desc"
  echo "## 테스트 결과"
  echo ""
  eval "$testexecute"
  echo ""
  # printline
  # echo $?
  # echo "hi!!"
  cd ..

}

function tests
{
  test ex01 print_groups.sh 'FT_USER=daemon 설정 후 쉘 실행' \
    'FT_USER=daemon ; export FT_USER ; /bin/sh print_groups.sh'
  test ex02 find_sh.sh '적절한 파일 생성후 실행' \
    'touch t_some.sh t_nosh ;
    mkdir t_fol ;
    cd t_fol ;
    touch t_abc.sh t_cd.sh.sh 
    cd .. ;
    printmsg "테스트용 파일 생성후 현재 폴더 상태" ;
    find . ;
    printmsg "./find_sh.sh | cat -e 실행" ;
    ./find_sh.sh | cat -e ;
    rm -r t_*'
  test ex03 count_files.sh '적절한 파일 생성후 실행' \
    'touch t_a t_b t_c ;
    mkdir t_d ;
    cd t_d ;
    touch t_e t_f ;
    cd .. ;
    printmsg "테스트용 파일 생성후 현재 폴더 상태" ;
    find . ;
    printmsg "./count_files.sh | cat -e 실행" ;
    ./count_files.sh | cat -e ;
    rm -r t_*'
  test ex04 MAC.sh "예제 명령 실행" '/bin/sh MAC.sh'
  test ex05 "" "ls -lRa *MaRV* | cat -e 실행" 'ls -lRa *MaRV* | cat -e'
  test ex06 skip.sh "1부터 5까지 파일 생성 후 실행" \
    'touch 1 2 3 4 5;
    /bin/sh skip.sh;
    rm 1 2 3 4 5 '
  test ex07 r_dwssap.sh "FT_LINE1=5, FT_LINE2=10 설정 후 쉘 실행" \
    'FT_LINE1=5;
    export FT_LINE1;
    FT_LINE2=10;
    export FT_LINE2;
    /bin/sh r_dwssap.sh;
    echo -e "$>\n"
    '
  test ex08 add_chelou.sh "예제에 나온 대로 FT_NBR1, FT_NBR2 설정 후 쉘 실행" \
  'FT_NBR1='"'"'\'"'"'"'"'"'"'"'"'?"\"'"'"'"'"'"'"'"'"'\'"'"' ;
  FT_NBR2=rcrdmddd ;
  export FT_NBR1 ;
  export FT_NBR2 ;
  echo "" ;
  echo FT_NBR1=$FT_NBR1 ;
  echo FT_NBR2=$FT_NBR2 ;
  /bin/sh add_chelou.sh ;

  FT_NBR1='"'"'\"\"!\"\"!\"\"!\"\"!\"\"!\"\"'"'"' ;
  FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo ;
  export FT_NBR1 ;
  export FT_NBR2 ;
  echo "" ;
  echo FT_NBR1=$FT_NBR1 ;
  echo FT_NBR2=$FT_NBR2 ;
  /bin/sh add_chelou.sh' ;

}


echo '본 테스트 스크립트가 잘못되어 있을 수도 있으니, '
echo '결과가 이상하다면 슬랙으로 꼭 공유해주세요.'
echo '결과가 너무 길다면 > test_result.txt 를 뒤에 추가하면 파일로 나옵니다.'

tests