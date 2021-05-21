FROM    debian:buster

LABEL   maintainer="kyekim@student.42seoul.kr"

RUN     apt-get -y update && apt-get -y upgrade && apt-get -y install\
        nginx \
        mariadb-server \
        php-mysql \
        php-mbstring \
        openssl \
        vim \
        wget \
        php7.3-fpm

COPY    ./srcs/run.sh   ./
COPY    ./srcs/nginx-conf   ./tmp
COPY    ./srcs/wp-config.php    ./tmp
COPY    ./srcs/config.inc.php ./tmp

EXPOSE  80  443

CMD bash run.sh
