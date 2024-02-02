# A mathematical expression containing +, -, *, ^, / and parenthesis will be provided. Read in the expression, then evaluate it. Display the result rounded to 3 decimal places.

read expression
echo "scale=3; $expression" | bc   # We are giving output of " " to bc and bc will give the stdoutput
#echo $(echo "scale=3; $expression" | bc) #this will also work the same


