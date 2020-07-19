#!/bin/bash

wget https://files.phpmyadmin.net/phpMyAdmin/4.5.5/phpMyAdmin-4.5.5-all-languages.zip
unzip phpMyAdmin-4.5.5-all-languages.zip
mv phpMyAdmin-4.5.5-all-languages /var/www/html/phpmyadmin

wget https://wordpress.org/latest.tar.gz
tar -zxvf latest.tar.gz
mv wordpress /var/www/html/
chown www-data.www-data /var/www/html/wordpress/* -R
mv /root/wp-config.php /var/www/html/wordpress/wp-config.php
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.pem -keyout /etc/nginx/ssl/localhost.key -subj "/C=KR/ST=Seoul/L=Seoul/O=42 Seoul/OU=Ecole/CN=localhost"

service php7.3-fpm start
service mysql start
service nginx start
service php7.3-fpm restart

bash /root/mysql_secure_installation.sh
mysql < /root/init.sql
/bin/bash
