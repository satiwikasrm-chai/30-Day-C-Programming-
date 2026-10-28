#include <stdio.h>

int main() {
    int ticket[15];
    int n, i, j;
    int count;
    int missingId = 0, duplicateId = 0;
    int missingCount = 0, duplicateCount = 0;
    int outOfOrderPairs = 0;
    int registrationDigits, target, targetCount = 0;

    printf("===== TICKET TRACE =====\n");

    printf("Enter N (5 to 15): ");
    scanf("%d", &n);

    while (n < 5 || n > 15) {
        printf("Invalid N. Enter a value from 5 to 15: ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        printf("Enter ticket ID at position %d (1 to %d): ", i + 1, n);
        scanf("%d", &ticket[i]);

        while (ticket[i] < 1 || ticket[i] > n) {
            printf("Invalid ticket ID. Enter a value from 1 to %d: ", n);
            scanf("%d", &ticket[i]);
        }
    }

    printf("\nOriginal scan sequence: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ticket[i]);
    }
    printf("\n");

    for (i = 1; i <= n; i++) {
        count = 0;

        for (j = 0; j < n; j++) {
            if (ticket[j] == i) {
                count++;
            }
        }

        if (count == 0) {
            missingId = i;
            missingCount++;
        } else if (count == 2) {
            duplicateId = i;
            duplicateCount++;
        } else if (count != 1) {
            duplicateCount++;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ticket[i] > ticket[j]) {
                outOfOrderPairs++;
            }
        }
    }

    printf("Out-of-order pairs: %d\n", outOfOrderPairs);

    printf("\nEnter the last two digits of your registration number (0 to 99): ");
    scanf("%d", &registrationDigits);

    while (registrationDigits < 0 || registrationDigits > 99) {
        printf("Invalid digits. Enter a value from 0 to 99: ");
        scanf("%d", &registrationDigits);
    }

    target = (registrationDigits % n) + 1;

    printf("Personalised target ID: %d\n", target);
    printf("Target position(s): ");
    for (i = 0; i < n; i++) {
        if (ticket[i] == target) {
            printf("%d ", i + 1);
            targetCount++;
        }
    }
    printf("\nTarget occurrence count: %d\n", targetCount);

    if (missingCount == 1 && duplicateCount == 1) {
        printf("\nDuplicated ticket ID: %d\n", duplicateId);
        printf("Missing ticket ID: %d\n", missingId);
    } else {
        printf("\nInvalid scan log: exactly one ID must be missing and one different ID must appear twice.\n");
    }

    return 0;
}
