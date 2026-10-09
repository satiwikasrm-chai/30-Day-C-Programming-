#include <stdio.h>

int main() {
    float amount, distance;
    float discountRate, discount, deliveryCharge;
    float finalAmount;
    int customerType;

    printf("===== SMARTCART =====\n");

    printf("Enter purchase amount: Rs. ");
    scanf("%f", &amount);

    printf("Customer Type:\n");
    printf("1. Regular Customer\n");
    printf("2. Premium Customer\n");
    printf("Enter customer type (1 or 2): ");
    scanf("%d", &customerType);

    printf("Enter delivery distance in km: ");
    scanf("%f", &distance);

    if (amount < 0 || distance < 0) {
        printf("Invalid input!\n");
        return 0;
    }

    if (customerType == 1) {
        if (amount >= 2000)
            discountRate = 10;
        else if (amount >= 1000)
            discountRate = 5;
        else
            discountRate = 0;
    }
    else if (customerType == 2) {
        if (amount >= 2000)
            discountRate = 20;
        else if (amount >= 1000)
            discountRate = 10;
        else
            discountRate = 5;
    }
    else {
        printf("Invalid customer type!\n");
        return 0;
    }

    discount = amount * discountRate / 100;

    if (distance <= 5)
        deliveryCharge = 0;
    else if (distance <= 10)
        deliveryCharge = 50;
    else
        deliveryCharge = 100;

    finalAmount = amount - discount + deliveryCharge;

    printf("\n===== BILL SUMMARY =====\n");
    printf("Purchase Amount : Rs. %f\n", amount);
    printf("Discount Rate   : %f\n", discountRate);
    printf("Discount Amount : Rs. %f\n", discount);
    printf("Delivery Charge : Rs. %f\n", deliveryCharge);
    printf("Final Payable   : Rs. %f\n", finalAmount);

    return 0;
}
