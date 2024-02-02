# Given N integers, compute their average, rounded to three decimal places.

avg=0
echo "Enter the number of integers you want to count the average of:"
read num
echo "Enter the integers one by one:"
for (( i=0 ; i<num ; i++ ))
do
	read int
	avg=$(( $avg + $int )) 
done


avg=$(echo "scale=3; $avg / $num"  | bc)
echo "The average is : $avg "


