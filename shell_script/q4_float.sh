#!/bin/bash

echo "Enter the first floating-point number:"
read float1

echo "Enter the second floating-point number:"
read float2

# Use bc to compare float values
result=$(echo "$float1 > $float2" | bc)

if [ "$result" -eq 1 ] 
then
    echo "The first number is greater than the second."
elif [ "$result" -eq 0 ] 
then
    echo "The two numbers are equal."
else
    echo "The first number is less than the second."
fi

