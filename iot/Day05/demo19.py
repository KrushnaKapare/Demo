# list
#   - collection of similar or dissimilar type of data
#   - mutable
#   - ordered

# mylist = [11, 22, 33, 44, 55]
# mylist = list()       -- empty list

def function1():
    mylist = [11, 22, 33, 44, 55]

    print(f"len(mylist) = {len(mylist)}")
    print(f"type(mylist) = {type(mylist)}")
    print(f"mylist = {mylist}")

    print(f"mylist[0] = {mylist[0]}")
    print(f"mylist[2] = {mylist[2]}")

    print("mylist using for loop : ")
    for value in mylist:
        print(value)

#function1()

def function2():
    l = [11, 22, 33, 44]

    print(f"Before len = {len(l)} , l = {l}")

    #l.append(100)         # value is appended at the end
    #l.insert(1, 100)       # value is inserted at index

    #l.pop()                 # last value will be removed
    #l.remove(22)            # given value will be removed
    #l.reverse()
    #l.clear()
    print(f"index of 33 = {l.index(33)}")

    print(f"after len = {len(l)} , l = {l}")


#function2()

def function3():
    student = [120, "abc", 4, 98.0]

    print(f"list = {student}")
    print(f"type of student = {type(student)}")

    i = 0
    while i < len(student):
        print(f"student[{i}] = {student[i]} ({type(student[i])})")
        i += 1

function3()

