
num1 = 10

def function1():
    num1 = 20
    print(f"inside function1() : num1 = {num1}")

#print(f"inside main program : num1 = {num1}")
#function1()

num2 = 10

def function2():
    global num2
    num2 = 20
    print(f"inside function1() : num2 = {num2}")

#print(f"inside main program before : num2 = {num2}")
#function2()
#print(f"inside main program after : num2 = {num2}")


num3 = 10

def function3():
    #nonlocal num3  # error
    #num3 = 20
    def inner():
        #nonlocal num3
        #global num3
        #num3 = 30
        print(f"inside inner : num3 = {num3}")
    
    inner()
    print(f"inside function3 : num3 = {num3}")

print(f"inside main program : num3 = {num3}")
function3()

