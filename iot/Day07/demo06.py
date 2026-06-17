
def changecase(n):
    def changecase(func):
        def inner():
            if n == 1:
                return func().upper()
            else:
                return func().lower()
        return inner
    return changecase

@changecase(1)
def msg():
    return "SunBeam"

print(msg())