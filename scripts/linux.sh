#! usr/bin/bash

outdir="../build/linux"
src="../src"
srcfiles="$src/main.c"

mkdir -p $outdir

gcc $srcfiles -o $outdir/app.exe -L ../lib/linux -I ../include -lm -lraylib -Wall
