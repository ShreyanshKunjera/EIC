# Given N lines of input, print the 3rd character from each line as a new line 
# of output. It is guaranteed that each of the n lines of input will have a 3rd
# character. (Hint: use ‘cut’ command)

arr=()

echo "Enter the number of lines:"
read num
echo "Enter the lines one by one:"

for(( i=0 ; i<num ; i++ ))
do
	read string
	arr[i]=${string:2:1}
done

for(( i=0 ; i<num ; i++ ))
do
	echo ${arr[i]}
done	
#echo ${string:2:1}
