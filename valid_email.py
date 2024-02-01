# Given an integer followed by email addresses. Your task is to print a list containing only valid email addresses in lexicographical order.

import string

def main():
	lst_of_emails=[]
	valid_list_of_email=[]
	output=[]
	no_of_emails=int(input("Enter the number of emails you want to give: "))

	print("Enter the emails one by one")
	for i in range(no_of_emails):
		lst_of_emails.append(input())

	valid_lst_of_email=list(filter(lambda x:validate_email(x),lst_of_emails))
	output = sorted(valid_lst_of_email)
	print(output)

	
def validate_email(s):
	if s.count("@")!=1 or s.count(".")!=1:
		return False
	position_of_attherate=s.find("@")
	position_of_dot=s.find(".")
	username_string=s[:position_of_attherate]
	websitename_string=s[position_of_attherate+1:position_of_dot]
	extension_string=s[position_of_dot+1:]
	print(username_string)
	print(websitename_string)
	print(extension_string)

	for i in username_string:
		if ((not('a'<=i and i<='z')) and (not('A'<=i and i<='Z')) and (i!='-') and (i!='_') and (i in string.punctuation)):
			return False 
		elif (i.isdigit() and (not(0<=int(i) and int(i)<=9))):
			return False

	for i in websitename_string:
		if i in string.punctuation:
			return False

	if len(extension_string) > 3:
		return False
	
	for i in extension_string:
		if ((not('a'<=i and i<='z')) and (not('A'<=i and i<='Z')) and (i in string.punctuation)):
			return False 
		elif (i.isdigit() and (not(0<=int(i) and int(i)<=9))):
			return False

	return True
				 
	
if __name__=='__main__':
	main()
