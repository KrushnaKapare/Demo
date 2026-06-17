
class person:
    # initializer
    def __init__(self, pname='', page=0):
        self.name = pname
        self.age = page
    
    # deinitializer
    def __del__(self):
        print("deinitializer is called")

    def display(self):
        print(f"name = {self.name}, age = {self.age}")

p1 = person()
p1.display()

p2 = person('abc', 35)
p2.display()
