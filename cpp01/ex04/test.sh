#!/bin/bash

# create test file

echo "Creating test file..."
cat <<EOF > test.txt
hello world
hello 42
abc ab abcd
EOF

# run program

echo "Running program..."
./replace test.txt hello HI

# show result

echo "---- OUTPUT FILE ----"
cat test.txt.replace

# expected behavior

echo "---- EXPECTED ----"
echo "HI world"
echo "HI 42"
echo "abc ab abcd"

# extra test (partial match)

echo "Running partial match test..."
./replace test.txt ab X

echo "---- OUTPUT FILE ----"
cat test.txt.replace

# edge case: empty s1

echo "Testing empty s1..."
./replace test.txt "" X

# cleanup

echo "Cleaning..."
rm -f replace test.txt test.txt.replace

