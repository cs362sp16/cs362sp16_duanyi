#!/bin/bash -e


cd $1
make clean
make all
./testdominion $3 >> results.out
echo "GCOV After Playing a Game" >> results.out
gcov dominion.c >> results1.out
cp results1.out $2
cd ..
cd $2
make clean
make all
./testdominion $3 >> results.out
echo "GCOV After Playing a Game" >> results.out
gcov dominion.c >> results2.out

if diff -s -y results1.out results2.out; then
    echo "TEST PASSED"
else
    echo "TEST FAILED"
fi
