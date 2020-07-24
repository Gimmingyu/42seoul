#!/bin/bash
for i in $(seq 4 10); do
	echo "=== $i X $i & 1 obstacle ==="
	./map.pl $i $i 1 > a
	./bsq a
done
for i in $(seq 4 10); do
	echo "=== $i X $i & 2 obstacles ==="
	./map.pl $i $i 2 > a
	./bsq a
done
for i in $(seq 4 10); do
	echo "=== $i X $i & 3 obstacles ==="
	./map.pl $i $i 3 > a
	./bsq a
done
for i in $(seq 4 10); do
	echo "=== $i X $i & 4 obstacles ==="
	./map.pl $i $i 4 > a
	./bsq a
done
for i in $(seq 4 10); do
	./map.pl 5 5 2 > ex$i
done
echo " === 5 X 5 & 2 obstacles & 2 arguments ==="
./bsq ex4 ex5
echo " === 5 X 5 & 2 obstacles & 3 arguments ==="
./bsq ex4 ex5 ex6
echo " === 5 X 5 & 2 obstacles & 4 arguments ==="
./bsq ex4 ex5 ex6 ex7
echo " === 5 X 5 & 2 obstacles & 5 arguments ==="
./bsq ex4 ex5 ex6 ex7 ex8
echo " === 5 X 5 & 2 obstacles & 6 arguments ==="
./bsq ex4 ex5 ex6 ex7 ex8 ex9
echo " === 5 X 5 & 2 obstacles & 7 arguments ==="
./bsq ex4 ex5 ex6 ex7 ex8 ex9 ex10
for i in $(seq 4 10); do
	rm -f ex$i
done
rm -rf a