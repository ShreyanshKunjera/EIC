# Given two integers, X and Y, identify whether X > Y or X < Y or X = Y.

echo 'Enter the values of X and Y:'
read X
read Y

if [[ $X > $Y ]]
then
	echo "X is greater than Y"
elif [ $X -lt $Y ]
then
	echo "X is less than Y"
else
	echo "X is equal to Y"
fi
