#!/bin/bash

export TMP_PWD='dkansk'

SECURE_MYSQL=$(expect -c "
set timeout 3
spawn mysql_secure_installation
expect \"Enter current password for root (enter for none):\"
send \"$MYSQL\r\"
expect \"Set root password?\"
send \"y\r\"
expect \"New password:\"
send \"$TMP_PWD\r\"
expect \"Re-enter new password:\"
send \"$TMP_PWD\r\"
expect \"Remove anonymous users?\"
send \"y\r\"
expect \"Disallow root login remotely?\"
send \"n\r\"
expect \"Remove test database and access to it?\"
send \"y\r\"
expect \"Reload privilege tables now?\"
send \"y\r\"
expect eof
")

LOGIN_MYSQL=$(expect -c "
set timeout 3
spawn mysql -uroot -p
expect \"Enter password:\"
send \"$TMP_PWD\r\"
expect eof
")

echo "$SECURE_MYSQL"
echo "$LOGIN_MYSQL"