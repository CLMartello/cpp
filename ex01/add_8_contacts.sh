#!/bin/bash

(
echo "ADD"
echo "John"
echo "Doe"
echo "JD"
echo "123456789"
echo "Secret1"

echo "ADD"
echo "Jane"
echo "Smith"
echo "JS"
echo "987654321"
echo "Secret2"

echo "ADD"
echo "Alice"
echo "Brown"
echo "AB"
echo "111111111"
echo "Secret3"

echo "ADD"
echo "Bob"
echo "White"
echo "BW"
echo "222222222"
echo "Secret4"

echo "ADD"
echo "Charlie"
echo "Black"
echo "CB"
echo "333333333"
echo "Secret5"

echo "ADD"
echo "David"
echo "Green"
echo "DG"
echo "444444444"
echo "Secret6"

echo "ADD"
echo "Eve"
echo "Blue"
echo "EB"
echo "555555555"
echo "Secret7"

echo "ADD"
echo "Frank"
echo "Gray"
echo "FG"
echo "666666666"
echo "Secret8"

cat   # 👈 keeps stdin open and interactive
) | ./phonebook
