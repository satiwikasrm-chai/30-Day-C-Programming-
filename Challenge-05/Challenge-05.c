#include <stdio.h>
#include <math.h>

int main()
{
    int choice, n, i;
    long long fact;
    double a, b, c, x, d, r1, r2;

    do
    {
        printf("\n--- EQUATION SOLVER+ ---\n");
        printf("1. Linear Equation\n");
        printf("2. Factorial\n");
        printf("3. Quadratic Equation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a menu number.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("\nLinear Equation: ax + b = 0\n");

                printf("Enter a: ");
                if (scanf("%lf", &a) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    return 1;
                }

                printf("Enter b: ");
                if (scanf("%lf", &b) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    return 1;
                }

                if (a != 0)
                {
                    x = -b / a;
                    printf("Answer: x = %.2lf\n", x);
                }
                else if (b == 0)
                {
                    printf("Infinite solutions.\n");
                }
                else
                {
                    printf("No solution.\n");
                }
                break;

            case 2:
                printf("\nFactorial Calculator\n");
                printf("Enter a number (0 to 20): ");
                if (scanf("%d", &n) != 1)
                {
                    printf("Invalid input. Please enter an integer.\n");
                    return 1;
                }

                if (n < 0 || n > 20)
                {
                    printf("Please enter a number from 0 to 20.\n");
                }
                else
                {
                    fact = 1;

                    for (i = 1; i <= n; i++)
                    {
                        fact = fact * i;
                    }

                    printf("Factorial = %lld\n", fact);
                }
                break;

            case 3:
                printf("\nQuadratic Equation: ax^2 + bx + c = 0\n");

                printf("Enter a: ");
                if (scanf("%lf", &a) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    return 1;
                }

                printf("Enter b: ");
                if (scanf("%lf", &b) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    return 1;
                }

                printf("Enter c: ");
                if (scanf("%lf", &c) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    return 1;
                }

                if (a == 0)
                {
                    if (b != 0)
                    {
                        x = -c / b;
                        printf("This is a linear equation.\n");
                        printf("Answer: x = %.2lf\n", x);
                    }
                    else if (c == 0)
                    {
                        printf("Infinite solutions.\n");
                    }
                    else
                    {
                        printf("No solution.\n");
                    }
                }
                else
                {
                    d = b * b - 4 * a * c;

                    if (d > 0)
                    {
                        r1 = (-b + sqrt(d)) / (2 * a);
                        r2 = (-b - sqrt(d)) / (2 * a);

                        printf("First root = %.2lf\n", r1);
                        printf("Second root = %.2lf\n", r2);
                    }
                    else if (d == 0)
                    {
                        r1 = -b / (2 * a);
                        printf("Both roots are equal: %.2lf\n", r1);
                    }
                    else
                    {
                        printf("No real roots.\n");
                    }
                }
                break;

            case 4:
                printf("Program ended. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
