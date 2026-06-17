
#import pkg2.mod3
from pkg2.mod3 import menu
from pkg1.mod1 import sum
from pkg1.mod2 import diff

while  True:
    choice = menu()

    if choice == 0:
        break
    
    op1 = int(input("Enter op1 : "))
    op2 = int(input("Enter op2 : "))

    match choice:
        case 1:
            print(f"{op1} + {op2} = {sum(op1, op2)}")
        case 2:
            print(f"{op1} - {op2} = {diff(op1, op2)}")
        case _:
            print("invalid choice")
        
