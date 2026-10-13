#include <stdio.h>
int main() {
    int n, i;
    double budget, expense;
    double total = 0.0;
    double average, highest = 0.0;

    // Input daily budget
    printf("Enter your daily budget: ");
    scanf("%lf", &budget);

    if (budget < 0) {
        printf("Invalid budget!\n");
        return 1;
    }

    // Input number of expenses
    printf("Enter number of expenses: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of expenses must be positive!\n");
        return 1;
    }

    // Read expenses using a loop
    for (i = 1; i <= n; i++) {
        printf("Enter expense %d: ", i);
        scanf("%lf", &expense);

        if (expense < 0) {
            printf("Negative expense is invalid!\n");
            return 1;
        }

        total = total + expense;

        if (i == 1 || expense > highest) {
            highest = expense;
        }
    }

    // Calculate average
    average = total / n;

    // Display expense report
    printf("\n--- Daily Expense Report ---\n");
    printf("Daily Budget:    Rs. %.2f\n", budget);
    printf("Total Expenses:  Rs. %.2f\n", total);
    printf("Average Expense: Rs. %.2f\n", average);
    printf("Highest Expense: Rs. %.2f\n", highest);

    // Analyze budget using conditions
    if (total > budget) {
        printf("Budget exceeded by: Rs. %.2f\n",
               total - budget);
    } else if (total < budget) {
        printf("Remaining Budget: Rs. %.2f\n",
               budget - total);
    } else {
        printf("You spent exactly your budget!\n");
    }

    return 0;
}
