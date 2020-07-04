#!/bin/sh
groups $FT_USER | tr " " "," | cat -e | cut -d "$" -f 1
