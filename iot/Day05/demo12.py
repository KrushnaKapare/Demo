
#   for loop_var in collection
#       statement(s)

#   for loop_var in collection
#       statement(s)
#   else:
#       statement(s)

# collection - list of values
# loop body will be executed for each value in the collection
# in every iteration next of collection will be there in loop_var

string = "sunbeam"

print("string = ", end=" ")
for character in string:
    print(character, end="")
else:
    print("")

print(f"length of string = {len(string)}")

length = 0
for ch in string:
    length += 1

print(f"length of string using for loop : {length}")
