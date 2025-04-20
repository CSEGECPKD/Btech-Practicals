print("""
Basic Calculator (using if-else only)

Enter the operation
    1) Add
    2) Subtract
    3) Multiply
    4) Divide
    5) Modulus
""")

operation = int(input("Select your operation [1 to 5]: "))

x = float(input("Enter first number: "))
y = float(input("Enter second number: "))

result = 0

if operation == 1:
	result = x + y
elif operation == 2:
	result = x - y
elif operation == 3:
	result = x * y
elif operation == 4:
	result = x / y
elif operation == 5:
	result = x % y
else:
	result = "None. REASON: Inavlid operation (Available option numbers are: 1 to 5)"

print('\nThe result is' ,result)
