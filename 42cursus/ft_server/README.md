# ft_server
* Grade: 100 / 100

### Summary
1. Objective
   * to discover `Docker` and install a complete web server, which will run multiple services including Wordepress, phpMyAdmin, and a SQL database
2. **Mandatory Part**
   - [Dockerfile](./Dockerfile)
   - srcs/
     - [run.sh](./srcs/run.sh)
     - [nginx.conf](./srcs/nginx.conf)
     - [config.inc.php](./srcs/config.inc.php)
     - [wp-config.php](./srcs/wp-config.php)
3. Check
   - all the necessary configuration files of the server are in the folder __srcs__.
   - the __Dockerfile__ is at the root of the repository.
   - you can run the `docker build .` command.
   - the you have only one container, which is built with __Debian Buster__.
   - you can run the container with `docker run xxx` without problems.
   - __Nginx__ uses the __SSL protocol__.
   - the server __redirects__ to the correct website, according to the url.
   - the server runs multiple services __(WordPress and phpMyAdmin)__.
   - the server is running with an __autoindex__ which can be deactivated when the container is launched (via an environment variable for example).
   - the WordPress website runs entirely with the MySQL database. You can __go to the site, log in, and watch the database__.
   - the SQL database works with phpMyAdmin. You should see the WordPress __tables and data__.
