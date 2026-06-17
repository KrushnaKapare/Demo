
# variable
PI = 3.142

# functions
def sum(n1, n2):
    return n1 + n2

def diff(n1, n2):
    return n1 - n2

def fun():
    print(f"__name__ = {__name__}")

# lambda function
sqr = lambda n : n ** 2
cube = lambda n : n ** 3
pow = lambda b, i : b ** i

class test:
    def test_method():
        print("This is a test method")

#print(f"pi = {PI}")
#print(f"sum(20, 10) = {sum(20, 10)}")
#print(f"diff(20, 10) = {diff(20, 10)}")
#print(f"4 cube = {cube(4)}")
#print(f"2^3 = {pow(2, 3)}")

#t1 = test
#print(f"type(t1) = {type(t1)}")
#t1.test_method()

#print(f"__name__ = {__name__}")