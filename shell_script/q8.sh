# Given a list of countries, each on a new line, your task is to read them into
# an array. Then slice the array and display only the elements lying between 
# positions 3 and 7, both inclusive. Indexing starts from 0.



arr=()
echo "Enter the number of countries:"
read num

echo "Enter the countries one by one"
for (( i=0 ; i<num ; i++ ))
do
	read arr[i]
done

echo "Countries between position 3 and 7 are :"
for (( j=3 ; j<=7 ; j++ ))
do
	echo ${arr[j]}
done

	
