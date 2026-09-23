#include <stdio.h>

int main(void)
{
    float mark1, mark2, mark3, mark4, mark5;
    float total, average, percentage;

    printf("Enter marks for subject 1: ");
    scanf("%f", &mark1);
    printf("Enter marks for subject 2: ");
    scanf("%f", &mark2);
    printf("Enter marks for subject 3: ");
    scanf("%f", &mark3);
    printf("Enter marks for subject 4: ");
    scanf("%f", &mark4);
    printf("Enter marks for subject 5: ");
    scanf("%f", &mark5);

    total = mark1 + mark2 + mark3 + mark4 + mark5;
    average = total / 5.0f;
    percentage = (total / 500.0f) * 100.0f;

    printf("Total Marks = %.2f\n", total);
    printf("Average Marks = %.2f\n", average);
    printf("Percentage = %.2f%%\n", percentage);

    return 0;
}
