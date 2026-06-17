
# to start a new block use indentation (tab)

#   if condition:
#       statement(s)

#   if condition:
#       statement(s)
#   else:
#       statement(s)

#   if condition:
#       statement(s)
#   elif condition:
#       statement(s)
#   else:
#       statement(s)

n1 = int(input("Enter n1 : "))
n2 = int(input("Enter n2 : "))

max = 0
if n1 == n2:
    max = n1
    print("n1 and n2 are equal")
elif n1 < n2:
    max = n2
    print("n2 is maximum")
else:
    max = n1
    print("n1 is maximum")

print(f"maximum value : {max}")