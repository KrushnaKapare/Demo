
class person:
    # initializer
    def __init__(self):
        self.name = "abc"
        self.age = 35
    
    def display(self):
        print(f"name = {self.name}, age = {self.age}")

p1 = person()
p1.display()

p2 = person()
p2.name = 'xyz'
p2.age = 17
p2.display()
