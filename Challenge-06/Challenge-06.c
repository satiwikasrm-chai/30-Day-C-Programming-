#include <stdio.h>

int main() {
    int readings[12];
    int n, i, j;
    int sum = 0;
    int minimum, maximum;
    int secondLargest, secondFound = 0;
    int peakCount = 0;
    int currentRun = 1, longestRun = 1;
    int k, lastValue;
    int registrationNumber, divisor, divisibleCount = 0;
    int input;

    printf("===== PATTERN DETECTIVE =====\n");

    /* Read the number of activity readings. */
    while (1) {
        printf("Enter number of readings (5 to 12): ");
        input = scanf("%d", &n);

        if (input == 1 && n >= 5 && n <= 12) {
            break;
        }

        printf("Invalid input. Please enter a number from 5 to 12.\n");

        while (getchar() != '\n') {
        }
    }

    /* Read every activity value. */
    for (i = 0; i < n; i++) {
        while (1) {
            printf("Enter reading %d (0 to 1000): ", i + 1);
            input = scanf("%d", &readings[i]);

            if (input == 1 && readings[i] >= 0 && readings[i] <= 1000) {
                break;
            }

            printf("Invalid input. Please enter a number from 0 to 1000.\n");

            while (getchar() != '\n') {
            }
        }
    }

    printf("\nOriginal readings: ");
    for (i = 0; i < n; i++) {
        printf("%d ", readings[i]);
    }

    /* Find the sum, minimum, and maximum. */
    minimum = readings[0];
    maximum = readings[0];

    for (i = 0; i < n; i++) {
        sum = sum + readings[i];

        if (readings[i] < minimum) {
            minimum = readings[i];
        }

        if (readings[i] > maximum) {
            maximum = readings[i];
        }
    }

    /* Find the second-largest value that is different from maximum. */
    for (i = 0; i < n; i++) {
        if (readings[i] != maximum) {
            if (secondFound == 0 || readings[i] > secondLargest) {
                secondLargest = readings[i];
                secondFound = 1;
            }
        }
    }

    for (i = 1; i < n - 1; i++) {
        if (readings[i] > readings[i - 1] && readings[i] > readings[i + 1]) {
            peakCount++;
        }
    }

    for (i = 1; i < n; i++) {
        if (readings[i] > readings[i - 1]) {
            currentRun++;
        } else {
            currentRun = 1;
        }

        if (currentRun > longestRun) {
            longestRun = currentRun;
        }
    }

    printf("\n===== ANALYSIS =====\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / n);
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);

    if (secondFound == 1) {
        printf("Second largest distinct value: %d\n", secondLargest);
    } else {
        printf("Second largest distinct value: Not available\n");
    }

    printf("Local peaks: %d\n", peakCount);
    printf("Longest increasing run: %d\n", longestRun);

    while (1) {
        printf("\nEnter K for rotation: ");
        input = scanf("%d", &k);

        if (input == 1) {
            break;
        }

        printf("Invalid input. Please enter an integer.\n");

        while (getchar() != '\n') {
        }
    }

    k = k % n;

    if (k < 0) {
        k = k + n;
    }

    /* Rotate right by moving the last value to the front. */
    for (i = 0; i < k; i++) {
        lastValue = readings[n - 1];

        for (j = n - 1; j > 0; j--) {
            readings[j] = readings[j - 1];
        }

        readings[0] = lastValue;
    }

    printf("Rotated readings: ");
    for (i = 0; i < n; i++) {
        printf("%d ", readings[i]);
    }

    while (1) {
        printf("\nEnter the last two digits of registration number (0 to 99): ");
        input = scanf("%d", &registrationNumber);

        if (input == 1 && registrationNumber >= 0 && registrationNumber <= 99) {
            break;
        }

        printf("Invalid input. Please enter a number from 0 to 99.\n");

        while (getchar() != '\n') {
        }
    }

    divisor = (registrationNumber % 9) + 1;

    for (i = 0; i < n; i++) {
        if (readings[i] % divisor == 0) {
            divisibleCount++;
        }
    }

    printf("Divisor D: %d\n", divisor);
    printf("Values divisible by D: %d\n", divisibleCount);

    return 0;
}
