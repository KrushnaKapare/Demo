
def function1():
    t1 = (
        (1, 2, 3, 4),
        (10, 20, 30, 40),
        (11, 22, 33, 44)
    )

    #print(t1)

    #for t in t1:
    #    print(t)

    for t in t1:
        for e in t:
            print(e, end=" ")
        print("")

#function1()

def function2():
    students = (
        (2, "abc", 97.0),
        (9, "xyz", 89.5),
        (15, "pqr", 91.7)
    )

    #print(students)

    #for stud in students:
    #    print(stud)
    
    #for stud in students:
    #    print(f"rollno = {stud[0]}, name = {stud[1]}, marks = {stud[2]}")

    for rollno, name, marks in students:
        print(f"rollno = {rollno}, name = {name}, marks = {marks}")

function2()