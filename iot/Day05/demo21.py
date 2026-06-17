# set
#   - collection of unique value
#   - mutable
#   - unordered

def function1():
    s1 = {11, 22, 33, 44}

    print(f"len(s1) = {len(s1)}")
    print(f"type(s1) = {type(s1)}")
    print(f"s1 = {s1}")

#function1()

def function2():
    s1 = {11, 22, 33, 44}

    print(f"before len = {len(s1)}, s1 = {s1}")

    #s1.add(55)
    #s1.add(33)
    #s1.pop()
    s1.remove(44)
    
    print(f"after len = {len(s1)}, s1 = {s1}")

function2()
