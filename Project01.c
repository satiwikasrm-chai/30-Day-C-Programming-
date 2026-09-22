#include <stdio.h>

int main()
{
    float m1, m2, m3, m4, m5;
    float total, average, percentage;

    printf("Enter marks for five subjects: ");
    printf("Enter marks for subject 1: ");
    scanf("%f", &m1);
    printf("Enter marks for subject 2: ");
    scanf("%f", &m2);
    printf("Enter marks for subject 3: ");
    scanf("%f", &m3);
    printf("Enter marks for subject 4: ");
    scanf("%f", &m4);
    printf("Enter marks for subject 5: ");
    scanf("%f", &m5);       

    total = m1 + m2 + m3 + m4 + m5;
    average = total / 5.0;
    percentage = (total / 500.0) * 100;

    printf("Total Marks = %f\n", total);
    printf("Average Marks = %f\n", average);
    printf("Percentage = %f\n", percentage);

    return 0;
}