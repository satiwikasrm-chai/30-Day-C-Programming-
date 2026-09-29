#include <stdio.h>

int main()
{
    float distance, mileage, price;
    float fuel, cost;

    printf("Enter distance in km: ");
    scanf("%f", &distance);

    printf("Enter mileage of vehicle: ");
    scanf("%f", &mileage);

    printf("Enter fuel price per litre: ");
    scanf("%f", &price);

    fuel = distance / mileage;
    cost = fuel * price;

    printf("\nFuel required = %f litres", fuel);
    printf("\nTotal fuel cost = Rs %f", cost);

    return 0;
}
