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
    average = total / 5.0;
    percentage = (total / 500.0) * 100.0;

    printf("Total Marks = %f\n", total);
    printf("Average Marks = %f\n", average);
    printf("Percentage = %f\n", percentage);

    return 0;
}
