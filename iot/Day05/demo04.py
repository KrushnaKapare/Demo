
# input() - used to take input from user

# type casting - to change the data type
#   int() - to change type to int
#   float() - to change type to float
#   str() - to change type to str 

print("Enter number :", end=" ")
num = int(input())
print(f"num = {num} (type = {type(num)})")

print("Enter string :", end=" ")
str = input()
print(f"str = {str} (type = {type(str)})")

print("Enter floating number :", end=" ")
f = float(input())
print(f"f = {f}, (type = {type(f)})")