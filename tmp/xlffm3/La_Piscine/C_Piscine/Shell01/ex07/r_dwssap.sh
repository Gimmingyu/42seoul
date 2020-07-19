#!/bin/sh
cat /etc/passwd | grep ^[^#] | sed -n 'n;p' | awk -F:*: '{print $1}' | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
