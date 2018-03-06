#!/usr/bin/bash

ASM=./asm/asm
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

OUT=${1##*/}
OUT=${OUT/".s"/".cor"}

mkdir -p $TMP

$ASM $1 1> /dev/null
mv $OUT $TMP/asm.cor

$REF $1 1> /dev/null
mv $OUT $TMP/ref.cor

DUMP="hexdump -C"

$DUMP $TMP/asm.cor > $TMP/dump_asm.txt
$DUMP $TMP/ref.cor > $TMP/dump_ref.txt

diff -y -W 122 --color $TMP/dump_ref.txt $TMP/dump_asm.txt

rm -rf $TMP
