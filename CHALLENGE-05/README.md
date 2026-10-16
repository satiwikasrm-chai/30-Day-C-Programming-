# CODE2THINK Challenge 05 — Equation Solver+

## Project description

This beginner-friendly C program has a menu for solving a linear equation,
calculating a factorial, and solving a quadratic equation. The menu repeats
until the user selects Exit.

## Challenge objectives

- Practise C variables, input/output, calculations, and conditions.
- Use `switch` to select a menu operation.
- Use a `do-while` loop to repeat the menu and a `for` loop for factorials.
- Solve linear equations and interpret the quadratic discriminant.
- Check whether `scanf` read the requested kind of input.
- Keep a factorial result within the range of `long long`.

## Folder contents

```text
CHALLENGE-05/
├── CHALLENGE-05.c
├── output.txt
└── README.md
```

The source code and documentation are in these three files. Compile the
program to create an executable when you want to run it; do not add that
generated executable to this folder.

## Software requirements

- GCC or another C compiler that supports the standard C library and `math.h`.
- Windows PowerShell or Command Prompt, or a Linux/WSL terminal.

The quadratic solver calls `sqrt()` from the math library. GCC may require
`-lm` to link that library, so put `-lm` at the end of the compile command.

## Compile and run

Open a terminal in the `CHALLENGE-05` folder.

### Windows

```powershell
gcc CHALLENGE-05.c -o CHALLENGE-05.exe -lm
.\CHALLENGE-05.exe
```

### Linux or WSL

```sh
gcc CHALLENGE-05.c -o CHALLENGE-05 -lm
./CHALLENGE-05
```

If GCC reports an undefined reference to `sqrt`, make sure `-lm` appears
after the source file and output name as shown above. Some GCC distributions
link the math library automatically.

## Explanation of the operations

### Linear equation: `ax + b = 0`

The program reads `a` and `b`. If `a` is not zero, rearrange the equation:

```text
ax + b = 0
ax = -b
x = -b / a
```

When both `a` and `b` are zero, every value of `x` works, so there are
infinitely many solutions. When `a` is zero but `b` is nonzero, the equation
cannot be true, so there is no solution. The `a != 0` condition avoids
dividing by zero.

### Factorial: `n!`

The factorial of a non-negative integer is the product of all integers from
`1` through `n`. The program starts `fact` at `1`, then a `for` loop
multiplies it by each number from `1` to `n`. For `0!`, the loop runs zero
times and `fact` remains `1`.

This version accepts integers from `0` to `20`. A `long long` can store every
factorial in that range; `20!` is `2432902008176640000`, which fits in the
minimum range guaranteed for `long long`. Larger and negative values are
rejected before the loop, preventing the factorial calculation from
overflowing the variable.

### Quadratic equation: `ax^2 + bx + c = 0`

The program calculates the discriminant:

```text
D = b*b - 4*a*c
```

If `D > 0`, the program uses `sqrt(D)` and the quadratic formula to calculate
two distinct real roots:

```text
x = (-b + sqrt(D)) / (2*a)
x = (-b - sqrt(D)) / (2*a)
```

If `D == 0`, both roots are equal, and the program calculates
`x = -b / (2*a)`. If `D < 0`, it reports that there are no real roots.
Because the `sqrt()` calls are only made in the `D > 0` case, the program
does not try to take the square root of a negative discriminant.

If `a == 0`, the equation is not quadratic. The program then treats it as
`bx + c = 0`: it calculates `x = -c / b` when `b` is nonzero, and handles
the infinitely-many-solutions and no-solution cases when `b` is zero.

## Algorithms

### Menu and repeat loop

1. Display the four choices and read the user's menu number.
2. If the menu input is not an integer, display an error and end the program.
3. Use `switch` to run the linear, factorial, or quadratic operation. If the
   choice is not `1`, `2`, `3`, or `4`, display an invalid-choice message.
4. For choices `1`, `2`, and `3`, return to the menu.
5. For choice `4`, display the goodbye message and stop repeating.
6. End the program.

### Linear equation

1. Read `a` and `b`. If either input is not a number, display an error and
   end the program.
2. If `a` is nonzero, calculate `x = -b / a` and display it.
3. Otherwise, if `b` is zero, report infinitely many solutions.
4. Otherwise, report no solution.
5. Return to the menu.

### Factorial

1. Read the integer `n`. If it is not an integer, display an error and end
   the program.
2. If `n` is less than `0` or greater than `20`, display the accepted range.
3. Otherwise, set `fact = 1`.
4. Use a `for` loop with `i` starting at `1` and continuing through `n`.
   Multiply `fact` by `i` on each pass.
5. Display the result. For `n = 0`, the loop does not run, and the result is
   `1`.
6. Return to the menu.

### Quadratic equation

1. Read `a`, `b`, and `c`. If any input is not a number, display an error
   and end the program.
2. If `a` is zero, treat the equation as linear. If `b` is nonzero, display
   `x = -c / b`; otherwise, report infinitely many solutions if `c` is zero,
   or no solution if `c` is nonzero.
3. If `a` is nonzero, calculate `D = b*b - 4*a*c`.
4. If `D` is positive, use `sqrt(D)` and the quadratic formula to display
   two roots.
5. If `D` is zero, calculate and display the repeated root.
6. If `D` is negative, display that there are no real roots.
7. Return to the menu.

## Flowcharts

### Menu and repeat loop


flowchart TD
    A([Start]) --> B[/Display menu and read choice/]
    B --> C{Was choice an integer?}
    C -- No --> D[/Display invalid input/]
    D --> Z([End with error])
    C -- Yes --> E{Which choice?}
    E -- 1 --> F[Run linear equation]
    E -- 2 --> G[Run factorial]
    E -- 3 --> H[Run quadratic equation]
    E -- 4 --> I[/Display goodbye message/]
    E -- Other --> J[/Display invalid choice/]
    F --> K{Is choice 4?}
    G --> K
    H --> K
    J --> K
    K -- No --> B
    K -- Yes --> I
    I --> L([End])
```

### Linear equation


flowchart TD
    A([Start operation]) --> B[/Read a and b/]
    B --> C{Were both inputs numbers?}
    C -- No --> D[/Display input error/]
    D --> Z([End program with error])
    C -- Yes --> E{Is a nonzero?}
    E -- Yes --> F[Calculate x = -b / a]
    F --> G[/Display x/]
    G --> K([Return to menu])
    E -- No --> H{Is b zero?}
    H -- Yes --> I[/Display infinite solutions/]
    H -- No --> J[/Display no solution/]
    I --> K
    J --> K
```

### Factorial


flowchart TD
    A([Start operation]) --> B[/Read integer n/]
    B --> C{Was input an integer?}
    C -- No --> D[/Display input error/]
    D --> Z([End program with error])
    C -- Yes --> E{Is n below 0 or above 20?}
    E -- Yes --> F[/Display accepted range/]
    F --> K([Return to menu])
    E -- No --> G[Set fact = 1 and i = 1]
    G --> H{Is i <= n?}
    H -- No --> I[/Display factorial/]
    I --> K
    H -- Yes --> J[Multiply fact by i; increase i]
    J --> H
```

### Quadratic equation


flowchart TD
    A([Start operation]) --> B[/Read a, b, and c/]
    B --> C{Were all inputs numbers?}
    C -- No --> D[/Display input error/]
    D --> Z([End program with error])
    C -- Yes --> E{Is a zero?}
    E -- Yes --> F{Is b nonzero?}
    F -- Yes --> G[Calculate x = -c / b]
    G --> H[/Display linear solution/]
    F -- No --> I{Is c zero?}
    I -- Yes --> J[/Display infinite solutions/]
    I -- No --> K[/Display no solution/]
    E -- No --> L[Calculate D = b*b - 4*a*c]
    L --> M{Is D positive?}
    M -- Yes --> N[Use sqrt and quadratic formula]
    N --> O[/Display two real roots/]
    M -- No --> P{Is D zero?}
    P -- Yes --> Q[Calculate repeated root]
    Q --> R[/Display repeated root/]
    P -- No --> S[/Display no real roots/]
    H --> T([Return to menu])
    J --> T
    K --> T
    O --> T
    R --> T
    S --> T
```

## Sample output

The recorded terminal sessions are in [output.txt](output.txt). The main
session demonstrates a linear solution, a factorial, two quadratic roots,
and Exit. Additional runs show important edge cases and input validation.

## Learning outcomes and conclusion

This project gives practice with `printf`, `scanf`, variables, arithmetic,
`if` / `else`, `switch`, and `do-while` and `for` loops. It also demonstrates
how equation formulas translate into C expressions and how the discriminant
indicates the number of real roots.

When explaining the program, first describe how the menu selects an
operation, then explain its formula and conditions. For the factorial, point
out that the loop keeps multiplying a running result, starting at `1`.