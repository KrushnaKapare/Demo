

def function1():
    student = [12, "abc", 6, 75.6]

    print(student)

    print(f"rollno = {student[0]}")
    print(f"name = {student[1]}")
    print(f"std = {student[2]}")
    print(f"marks = {student[3]}")

# function1()

# dict
# data is stored in key-value pairs
def function2():
    student = {'rollno':12, 'name':'abc', 'std':6, 'marks':75.6}

    print(f"student = {student}")

    print(f"rollno = {student['rollno']}")
    print(f"name = {student['name']}")
    print(f"std = {student['std']}")
    print(f"marks = {student['marks']}")

    print(f"keys : {student.keys()}")
    print(f"values : {student.values()}")
    
function2()