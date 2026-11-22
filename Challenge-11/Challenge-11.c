#include <stdio.h>

#define BUILDINGS 5
#define DAYS 7

/* Calculates the average using pointer access. */
float calculateAverage(int *water, int days)
{
    int i;
    int sum = 0;

    for (i = 0; i < days; i++)
    {
        sum += *(water + i);
    }

    return (float)sum / days;
}

/* Displays water-use data for all selected buildings. */
void displayData(int water[BUILDINGS][DAYS], int buildings, int days)
{
    int i, j;

    printf("\n--- WATER CONSUMPTION REPORT ---\n");

    for (i = 0; i < buildings; i++)
    {
        printf("\nBuilding %d: ", i + 1);

        for (j = 0; j < days; j++)
        {
            printf("%d ", water[i][j]);
        }
    }

    printf("\n");
}

/* Reports daily usage that is more than 150 percent of the average. */
void detectLeak(int *water, int days, float average)
{
    int i;
    int alert = 0;

    for (i = 0; i < days; i++)
    {
        if (*(water + i) > average * 1.5)
        {
            printf("\nPossible leak detected on Day %d!", i + 1);
            alert = 1;
        }
    }

    if (alert == 0)
    {
        printf("\nNo unusual water consumption detected.");
    }
}

int main()
{
    int water[BUILDINGS][DAYS];
    int buildings, days;
    int i, j;

    printf("===== WATERWISE =====\n");
    printf("Campus Water Audit System\n");

    printf("\nEnter number of buildings (1-5): ");
    scanf("%d", &buildings);

    printf("Enter number of days (1-7): ");
    scanf("%d", &days);

    if (buildings < 1 || buildings > BUILDINGS ||
        days < 1 || days > DAYS)
    {
        printf("\nInvalid input!\n");
        return 0;
    }

    for (i = 0; i < buildings; i++)
    {
        printf("\nEnter water consumption for Building %d:\n", i + 1);

        for (j = 0; j < days; j++)
        {
            printf("Day %d (in litres): ", j + 1);
            scanf("%d", &water[i][j]);

            if (water[i][j] < 0)
            {
                printf("Consumption cannot be negative.\n");
                return 0;
            }
        }
    }

    displayData(water, buildings, days);

    printf("\n--- WATER AUDIT RESULTS ---\n");

    for (i = 0; i < buildings; i++)
    {
        float average = calculateAverage(water[i], days);

        printf("\nBuilding %d Average: %.2f litres\n", i + 1, average);
        printf("Leak Analysis:");
        detectLeak(water[i], days, average);
        printf("\n");
    }

    printf("\n--- WATER SAVING SUGGESTIONS ---\n");
    printf("1. Repair leaking taps and pipes.\n");
    printf("2. Avoid unnecessary water usage.\n");
    printf("3. Monitor daily water consumption.\n");
    printf("4. Reuse water wherever possible.\n");

    printf("\n===== AUDIT COMPLETED =====\n");

    return 0;
}
