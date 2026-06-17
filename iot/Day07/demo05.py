
def toupper(func):
    def inner():
        return func().upper()

    return inner

@toupper
def msg():
    return "SunBeam"

print(msg())