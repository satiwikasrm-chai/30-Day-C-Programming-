#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Reads one decimal value and makes sure the whole line is valid. */
int readDecimal(const char *message, double *value) {
    char input[100];
    char *end;

    printf("%s", message);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }

    *value = strtod(input, &end);

    while (isspace((unsigned char)*end)) {
        end++;
    }

    if (*value != *value || *value == HUGE_VAL || *value == -HUGE_VAL) {
        return 0;
    }

    return end != input && *end == '\0';
}

/* Reads a customer type without accepting values such as 1.5 or 2abc. */
int readCustomerType(int *customerType) {
    char input[100];
    char *end;
    long value;

    printf("Enter customer type (1 or 2): ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }

    value = strtol(input, &end, 10);

    while (isspace((unsigned char)*end)) {
        end++;
    }

    if (end == input || *end != '\0' || (value != 1 && value != 2)) {
        return 0;
    }

    *customerType = (int)value;
    return 1;
}

int main(void) {
    double amount, distance;
    double discountRate, discount, deliveryCharge;
    double finalAmount;
    int customerType;

    printf("===== SMARTCART =====\n");

    if (!readDecimal("Enter purchase amount: Rs. ", &amount) || amount < 0) {
        printf("Invalid purchase amount!\n");
        return 1;
    }

    printf("Customer Type:\n");
    printf("1. Regular Customer\n");
    printf("2. Premium Customer\n");
    if (!readCustomerType(&customerType)) {
        printf("Invalid customer type!\n");
        return 1;
    }

    if (!readDecimal("Enter delivery distance in km: ", &distance) || distance < 0) {
        printf("Invalid delivery distance!\n");
        return 1;
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
    discount = amount * discountRate / 100;

    if (distance <= 5)
        deliveryCharge = 0;
    else if (distance <= 10)
        deliveryCharge = 50;
    else
        deliveryCharge = 100;

    finalAmount = amount - discount + deliveryCharge;

    printf("\n===== BILL SUMMARY =====\n");
    printf("Purchase Amount : Rs. %.2f\n", amount);
    printf("Discount Rate   : %.0f%%\n", discountRate);
    printf("Discount Amount : Rs. %.2f\n", discount);
    printf("Delivery Charge : Rs. %.2f\n", deliveryCharge);
    printf("Final Payable   : Rs. %.2f\n", finalAmount);

    return 0;
}
