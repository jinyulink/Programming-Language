#!/bin/bash
fileName=practice
if [ $# -lt 1 ];then
    echo -e "\033[31mMissing fileName.\033[0m"
    exit 1
fi

instruction1="bison -d -o $fileName.tab.c $fileName.y"
instruction2="gcc -c -g -I.. $fileName.tab.c"
instruction3="flex -o $fileName.yy.c $fileName.l"
instruction4="gcc -c -g -I.. $fileName.yy.c"
instruction5="gcc -o $fileName $fileName.tab.o $fileName.yy.o"

run() {
    $*
    if [ $? -eq 0 ];then
        echo -e "\033[32mInstruction ($*) finish.\033[0m"
    else
        echo -e "\033[31mError in instruction ($*).\033[0m"
        exit 0
    fi
}

run $instruction1
run $instruction2
run $instruction3
run $instruction4
run $instruction5

