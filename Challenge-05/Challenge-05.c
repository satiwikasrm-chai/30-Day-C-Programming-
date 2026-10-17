
#include <stdio.h>
#include <math.h>

int main()
{
    int choice, n, i, fact;
    double a, b, c, x, d, r1, r2;

    do
    {
        printf("\n--- EQUATION SOLVER+ ---\n");
        printf("1. Linear Equation\n");
        printf("2. Factorial\n");
        printf("3. Quadratic Equation\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter a and b: ");
                scanf("%lf %lf", &a, &b);

                if (a != 0)
                    printf("x = %.2lf\n", -b / a);
                else if (b == 0)
                    printf("Infinite solutions\n");
                else
                    printf("No solution\n");
                break;

            case 2:
                printf("Enter number (0-12): ");
                scanf("%d", &n);

                if (n < 0 || n > 12)
                {
                    printf("Enter a number from 0 to 12\n");
                    break;
                }

                fact = 1;

                for (i = 1; i <= n; i++)
                    fact = fact * i;

                printf("Factorial = %d\n", fact);
                break;

            case 3:
                printf("Enter a, b and c: ");
                scanf("%lf %lf %lf", &a, &b, &c);

                if (a == 0)
                {
                    if (b != 0)
                        printf("Linear equation: x = %.2lf\n", -c / b);
                    else if (c == 0)
                        printf("Infinite solutions\n");
                    else
                        printf("No solution\n");
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
                        printf("Equal roots = %.2lf\n", -b / (2 * a));
                    }
                    else
                    {
                        printf("No real roots\n");
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
