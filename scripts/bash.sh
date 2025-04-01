#! usr/bin/bash

outdir="../build/linux"
src="../src"
srcfiles="$src/main.c"

mkdir -p $outdir
mkdir -p $outdir/lib

gcc $srcfiles -o $outdir/app.exe -L ../lib -I ../include -lm -lraylib -Wall
cp ../lib/libraylib.a $outdir/lib
