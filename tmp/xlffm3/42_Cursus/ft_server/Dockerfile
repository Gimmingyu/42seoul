# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/19 02:00:08 by jipark            #+#    #+#              #
#    Updated: 2020/04/19 11:38:50 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

MAINTAINER JIN HONG PARK <xlffm3@gmail.com>

RUN apt-get update
RUN apt-get install -y wget
RUN apt-get install -y zip
RUN apt-get install -y nginx
RUN apt-get install -y php-fpm
RUN apt-get install -y mariadb-server php-mysql
RUN apt-get install -y php-mbstring
RUN apt-get install -y php-curl
RUN apt-get install -y expect

COPY srcs/nginx /etc/nginx/sites-available/
COPY srcs/php /var/www/html/
COPY srcs/wordpress/wp-config.php /root/
COPY srcs/sql/init.sql /root/
COPY srcs/sql/mysql_secure_installation.sh /root/
COPY srcs/init_container.sh /root/

CMD ["/bin/bash", "/root/init_container.sh"]

EXPOSE 80 443
