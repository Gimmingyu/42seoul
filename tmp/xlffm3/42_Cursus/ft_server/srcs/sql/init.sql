CREATE DATABASE wordpress;
use mysql;
update user set plugin='' where user='root';
flush privileges;
