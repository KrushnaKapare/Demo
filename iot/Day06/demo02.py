
def add(n1, n2):
    return n1 + n2

def sub(n1, n2):
    return n1 - n2

def calculate(n1, n2, func):
    return func(n1, n2)

def outer():
    def inner():
        print("This is inner function")
    print("This is outer function")
    return inner


sum = add

print(f"add(10, 20) = {add(10, 20)}")
print(f"sum(10, 20) = {sum(10, 20)}")

s = calculate(20, 10, add)
print(f"s = {s}")

d = calculate(20, 10, sub)
print(f"d = {d}")

func = outer()

func()


