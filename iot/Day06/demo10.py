
class person:
    pass

p1 = person()
setattr(p1, 'name', "abc")
setattr(p1, 'age', 35)

print(f"type(p1) = {type(p1)}")
print(f"name = {getattr(p1, 'name')}")
print(f"age = {getattr(p1, 'age')}")
print(f"p1 = {p1.__dict__}")

