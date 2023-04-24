#!/bin/bash
bison -d -o hw4.tab.c practice.y
gcc -c -g -I.. hw4.tab.c
flex -o hw4.yy.c practice.l
gcc -c -g -I.. hw4.yy.c
gcc -o practice hw4.tab.o hw4.yy.o

