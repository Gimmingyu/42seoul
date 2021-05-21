#!/bin/sh

service mysql start


# SSl
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/html.pem -keyout /etc/nginx/ssl/html.key -subj "/C=KR/ST=SEOUL/L=Gaepo-dong/O=42Seoul/OU=kyekim/CN=html"

# NGINX
mkdir var/www/html
mv ./tmp/nginx-conf /etc/nginx/sites-available/default
ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default
chown -R www-data /var/www/*
chmod -R 775 /var/www/*

# Config MYSQL
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

# PHPMYADMIN
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz  -C /var/www/html/
mv /var/www/html/phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
mv ./tmp/config.inc.php /var/www/html/phpmyadmin/config.inc.php

# WORDPRESS
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html/
mv /tmp/wp-config.php /var/www/html/wordpress
chown -R www-data:www-data /var/www/html/wordpress

service nginx start
service mysql restart
service php7.3-fpm start
bash
