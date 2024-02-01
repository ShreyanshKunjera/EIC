# Given a year, determine whether it is a leap year. If it is a leap year, return the Boolean True, otherwise return False. Note that the code should read from STDIN and passes arguments to the is_leap function. It is only necessary to complete the is_leap function.


def main():
#Take input from user of the year
	year=int(input("Enter a year between 1900 to 100000: "))
	# If user give year < 1900 then tell them to reenter the valid year and terminate the program
	if year<1900:
		print("Enter the year greater than 1900")
		return -1 # return -1 to terminate the code in case of wrong input
	elif year>100000:
		print("Enter the year less than 100000")
		return -1
	print(is_leap(year)) # calling the function and printing the output of true or false


# Defining the function to check if the year is leap year or not
def is_leap(year):
	#if year is not a century then it should be divided by 4 to be a leap year
	#if year is a century then it should be divided by 400 to be a leap year
	if (year%100!=0 and year%4!=0) or (year%100==0 and year%400!=0):
		return False
	else:
		return True

# Calling the main function
if __name__=='__main__':
	main()
