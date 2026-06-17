# functions
#   def function_name():
#       statement(s)

#   def function_name(param):
#       statement(s)

#   def function_name(param1, param2):
#       statement(s)
#       return result

# actual arguments - arguments
# formal arguments - parameters

def function1():
    str = """This is our first function
            in python"""            # multi line string
    print(str)


# function1()

def function2(param):
    print(f"param = {param}")
    print(f"type(param) = {type(param)}")

#function2(10)
#function2('sunbeam')
#function2(3.142)
#function2(False)

def function3(op1, op2):
    return op1 + op2

#ret = function3(10, 20)
#ret = function3("Sun", "Beam")
ret = function3(1.5, 2.5)
#ret = function3("Sun", 10)      # error
print(f"sum = {ret} ({type(ret)})")









