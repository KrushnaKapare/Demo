### C struct Revision

```C
struct date {
    int day, month, year;
};

struct date d1 = {1, 12, 2025}; // C89 std
struct date d2 = {.day = 1, .month = 12, .year = 2025}; // C99 std -- struct tagged init
```

```C
struct operations {
    int (*op1)(int,int);
    int (*op2)(int,int);
    int (*op3)(int,int);
    int (*op4)(int,int);
};

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

// in main()
struct operations ops1; // struct var declaration
ops1.op1 = add; // struct var member initialization
ops1.op2 = subtract; // struct var member initialization
ops1.op3 = multiply; // struct var member initialization
ops1.op4 = divide; // struct var member initialization

// struct var declaration + initialization
struct operations op2 = {add, subtract, multiply, divide}; // C89 std

// struct var declaration + initialization
struct operations op3 = {
    .op1 = add,
    .op2 = subtract,
    .op3 = multiply,
    .op4 = divide
};
```

### x86 CPU registers

- **16-bit CPU registers -- 8086, 80186, ...**
  - ax, bx, cx, dx, si, di, sp, bp, ip, ...
- **32-bit CPU registers -- 80386, 80486, ...**
  - eax, ebx, ecx, edx, esi, edi, esp, ebp, eip, ...
- **64-bit CPU registers -- x86_64 arch, ...**
  - rax, rbx, rcx, rdx, rsi, rdi, rsp, rbp, rip, ...
