cat /etc/passwd | grep -v '#' | cut -d ':' -f1 | sed -n 'n;p' | rev | sort -r | awk -v st=$FT_LINE1 -v en=$FT_LINE2 'NR>=st && NR<=en' | tr '\n' ',' | sed 's/,/, /' | sed 's/,$/./' | tr -d '\n' 
