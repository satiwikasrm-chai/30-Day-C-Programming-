#include <stdio.h>

int main(void) {
    double amount, distance;
    double discountRate, discount, deliveryCharge, finalAmount;
    int customerType;

    printf("===== SMARTCART =====\n");

    printf("Enter purchase amount: Rs. ");
    if (scanf("%lf", &amount) != 1 || amount < 0) {
        printf("Invalid purchase amount!\n");
        return 1;
    }

    printf("Customer Type:\n");
    printf("1. Regular Customer\n");
    printf("2. Premium Customer\n");
    printf("Enter customer type (1 or 2): ");
    if (scanf("%d", &customerType) != 1 ||
        (customerType != 1 && customerType != 2)) {
        printf("Invalid customer type!\n");
        return 1;
    }

    printf("Enter delivery distance in km: ");
    if (scanf("%lf", &distance) != 1 || distance < 0) {
        printf("Invalid delivery distance!\n");
        return 1;
    }

    if (customerType == 1) {
        if (amount >= 2000) {
            discountRate = 10;
        } else if (amount >= 1000) {
            discountRate = 5;
        } else {
            discountRate = 0;
        }
    } else {
        if (amount >= 2000) {
            discountRate = 20;
        } else if (amount >= 1000) {
            discountRate = 10;
        } else {
            discountRate = 5;
        }
    }
    discount = amount * discountRate / 100;

    if (distance <= 5) {
        deliveryCharge = 0;
    } else if (distance <= 10) {
        deliveryCharge = 50;
    } else {
        deliveryCharge = 100;
    }

    finalAmount = amount - discount + deliveryCharge;

    printf("\n===== BILL SUMMARY =====\n");
    printf("Purchase Amount : Rs. %.2f\n", amount);
    printf("Discount Rate   : %.0f%%\n", discountRate);
    printf("Discount Amount : Rs. %.2f\n", discount);
    printf("Delivery Charge : Rs. %.2f\n", deliveryCharge);
    printf("Final Payable   : Rs. %.2f\n", finalAmount);

    return 0;
}
