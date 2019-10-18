palindrome = lambda string : string == string[::-1]
print("The string is a palindrome." if palindrome(input("Enter string: ")) else "The string isn't a palindrome.")