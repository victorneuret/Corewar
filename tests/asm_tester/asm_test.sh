#!/usr/bin/bash

ASM=./asm
REF=./tests/asm_tester/asm_ref
TMP=./tests/asm_tester/tmp

if [[ $# != 1 ]]
then
	echo "Expected one argument: path of the assembly source."
	exit 1
fi

if [ ! -f $1 ]
then
	echo "File $1 does not exist."
	exit 1
fi

if [ ! -f $ASM ]
then
	echo "Cannot find asm binary."
	exit 1
fi

if [ ! -f $REF ]
then
	echo "Cannot find asm binary."
	exit 1
fi

mkdir -p $TMP

$ASM $1 1> /dev/null
mv *.cor $TMP/asm.cor

$REF $1 1> /dev/null
mv *.cor $TMP/ref.cor

hexdump -C $TMP/asm.cor > $TMP/dump_asm.txt
hexdump -C $TMP/ref.cor > $TMP/dump_ref.txt

diff -y $TMP/dump_asm.txt $TMP/dump_ref.txt

rm -rf $TMP
