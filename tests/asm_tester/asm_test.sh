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
$REF $1 1> /dev/null

rm -rf $TMP
