# tuple
#   - collection of similar or dissimilar type of data
#   - immutable
#   - ordered

# t = (11, 22, 33, 44)
#  t = tuple(...)

def function1():
    t1 = (11, 22, 33, 44, 55)

    print(f"len(t1) = {len(t1)}")
    print(f"type(t1) = {type(t1)}")
    print(f"t1 = {t1}")

    print(f"t1[0] = {t1[0]}")
    print(f"t1[2] = {t1[2]}")

    print("t1 using for loop : ")
    for value in t1:
        print(value)

#function1()

def function2():
    t = (11, 22, 33, 44, 22)

    print(f"Before len = {len(t)} , t = {t}")

    print(f"count of 22 = {t.count(22)}")
    print(f"index of 33 = {t.index(33)}")

function2()

def function3():
    student = (120, "abc", 4, 98.0)

    print(f"student = {student}")
    print(f"type of student = {type(student)}")

    i = 0
    while i < len(student):
        print(f"student[{i}] = {student[i]} ({type(student[i])})")
        i += 1

#function3()
