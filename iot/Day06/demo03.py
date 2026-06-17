
def function1():
    l1 = [
        [1, 2, 3, 4],
        [10, 20, 30, 40],
        [11, 22, 33, 44]
    ]

    print(l1)
    print("l1 = ", l1)
    print(f"l1 = {l1}")

#function1()

def function2():
    l1 = [
        [1, 2, 3, 4],
        [10, 20, 30, 40],
        [11, 22, 33, 44]
    ]

    for l in l1:
        print(l)

#function2()

def function3():
    l1 = [
        [1, 2, 3, 4],
        [10, 20, 30, 40],
        [11, 22, 33, 44]
    ]

    for l in l1:
        for e in l:
            print(e, end=" ")
        print("")

#function3()

def function4():
    students = [
        [12, "abc", 97.0],
        [9, "xyz", 89.5],
        [15, "pqr", 91.7]
    ]

    #print(students)

    #for stud in students:
    #    print(stud)

    #for stud in students:
    #    print(f"rollno = {stud[0]}, name = {stud[1]}, marks = {stud[2]}")

    for rollno, name, marks in students:
        print(f"rollno = {rollno}, name = {name}, marks = {marks}")

function4()



