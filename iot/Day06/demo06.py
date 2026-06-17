
def function1():
    import mymath

    print(f"pi = {mymath.PI}")
    print(f"sum(20, 10) = {mymath.sum(20, 10)}")
    print(f"2^3 = {mymath.pow(2, 3)}")
    mymath.fun()

#print(f"__name__ = {__name__}")
#function1()


def function2():
    import mymath as m

    print(f"pi = {m.PI}")
    print(f"sum(20, 10) = {m.sum(20, 10)}")
    print(f"2^3 = {m.pow(2, 3)}")

#function2()

def function3():
    from mymath import sum
    from mymath import diff
    
    print(f"sum(20, 10) = {sum(20, 10)}")
    print(f"diff(20, 10) = {diff(20, 10)}")
    
#function3()

def function4():
    from mymath import sum as s
    from mymath import diff as d
    
    print(f"sum(20, 10) = {s(20, 10)}")
    print(f"diff(20, 10) = {d(20, 10)}")
    
function4()