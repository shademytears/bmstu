#!/bin/bash
echo "number: $1"
if [ $(($1 % 2)) -eq 0 ]; then
    echo "number is even"
else
    echo "number is odd"
fi
