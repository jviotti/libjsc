#!/bin/sh

set -eu

mkdir -p out
cd out 
cmake -DPORT="GTK" -DCMAKE_BUILD_TYPE=Release -G Ninja ..
