#!/bin/sh

file1="$1"
file2="$2"

tmp1=$(mktemp)
tmp2=$(mktemp)

cut -c18- "$file1" > "$tmp1"
cut -c18- "$file2" > "$tmp2"

diff "$tmp1" "$tmp2" >>/dev/null && echo "IDENTICAL"

rm -f "$tmp1" "$tmp2"