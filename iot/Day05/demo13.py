string = "SUNbeam"

print(f"string = {string}")
print(f"string[0] = {string[0]}")
print(f"string[1] = {string[1]}")
print(f"string[4] = {string[4]}")
print(f"string[-1] = {string[-1]}")
print(f"string[-4] = {string[-4]}")
print(f"string[2:6] = {string[2:6]}")   
    # characters from index 2 to 5
print(f"string[2:] = {string[2:]}")   
    # characters from index 2 to last(len-1) 
print(f"string[:6] = {string[:6]}")   
    # characters from start(0) to 5


print("string in upper case : " + string.upper())
print("string in lower case : " + string.lower())


str = " IoT "

print(f"before : str = {str} (len = {len(str)})")
str = str.strip()
print(f"after : str = {str} (len = {len(str)})")