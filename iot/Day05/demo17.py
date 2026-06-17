

def function1(num1, num2, num3):
    print(f"num1 = {num1}")
    print(f"num2 = {num2}")
    print(f"num3 = {num3}")

#function1(10, 20, 30)
#function1()         # error
#function1(10, 20)      # error

# default values to the parameters

def function2(num1=0, num2=0, num3=None):
    print(f"num1 = {num1}")
    print(f"num2 = {num2}")
    print(f"num3 = {num3}")

#function2(10, 20, 30)
#function2()
#function2(10, 20)

# function can be called with the help of key - value pairs
#   key - parameter name
#   value - argument value

#function2(num1=10, num3=30)
#function2(num2=20, num3=30, num1=10)

def function3():
    return 10, 20

n1, n2 = function3()
print(f"n1 = {n1}, n2 = {n2}")

function3()
