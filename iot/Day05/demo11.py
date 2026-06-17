
#   initialization
#   while condition:
#       statement(s)
#       modification

#   initialization
#   while condition:
#       statement(s)
#       modification
#   else:
#       statement(s)

# when loop condition will be false else block will be executed once

num = int(input("Enter number : "))

#i = 1
#print(f"Table of {num} :")
#while i <= 10:
#    print(i * num)
#    i+=1

fact = 1
i = 1
while i <= num:
    fact *= i
    i += 1
else:
    print("condition is false")

print(f"{num}! = {fact}")