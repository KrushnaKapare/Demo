
def function1():
    students = [
        (2, "abc", 97.0),
        (9, "xyz", 89.5),
        (15, "pqr", 91.7)
    ]

    print(students)

    for stud in students:
        print(stud)
    
    for stud in students:
        print(f"stud[0] = {stud[0]}, stud[1] = {stud[1]}, stud[2] = {stud[2]}")

    for rollno, name, marks in students:
        print(f"rollno = {rollno}, name = {name}, marks = {marks}")

#function1()

def function2():
    students = [
        {'rollno':2, 'name':"abc", 'marks':97.0},
        {'rollno':9, 'name':"xyz", 'marks':89.5},
        {'rollno':15, 'name':"pqr", 'marks':91.7}
    ]

    #print(students)
    
    #for stud in students:
    #    print(stud)

    #for stud in students:
    #    print(f"rollno = {stud['rollno']}, name = {stud['name']}, marks = {stud['marks']}")

    for stud in students:
        print(stud.values())
    

function2()