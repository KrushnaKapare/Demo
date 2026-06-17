
class Person:
    def __init__(self, pname = '', page = 0):
        self.__name = pname
        self.__age = page

    def display(self):
        print(f"name = {self.__name} [age = {self.__age}]")


class Student(Person):
    def __init__(self, pname='', page=0, no=0, m=0.0):
        #Person().__init__(pname, page)
        super().__init__(pname, page)
        self.__rollno = no
        self.__marks = m

    def display(self):
        super().display()
        print(f"rollno = {self.__rollno}, marks = {self.__marks}")


s1 = Student('abc', 10, 12, 98.0)
s1.display()

#print(f"attrs = {s1.__dict__}")


