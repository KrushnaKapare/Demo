
#   match expression:
#       case 1 | 3 | 4:
#           statement{s}
#       case 2:
#           statement{s}    
#       case _:
#           statement{s}

#   match expression:
#       case 1 | 3 | 4 if condition:
#           statement{s}
#       case 2 | 3 | 4:
#           statement{s}    
#       case _:
#           statement{s}

op1 = int(input("Enter op1 : "))
op2 = int(input("Enter op2 : "))

print("1. Add\n2. Sub\n3. Mul\n4. Div")
choice = int(input("Enter your choice : "))

match choice:
    case 1:
        print(f"{op1} + {op2} = {op1 + op2}")
    case 2:
        print(f"{op1} - {op2} = {op1 - op2}")
    case 3:
        print(f"{op1} * {op2} = {op1 * op2}")
    case 4:
        print(f"{op1} / {op2} = {op1 / op2}")
    case _:
        print("invalid operation")
