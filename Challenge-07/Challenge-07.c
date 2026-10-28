#include <stdio.h>

int main() {
    int ticket[100];
    int n, i, j, k;
    int duplicateFound, missingFound;
    int outOfOrderPairs = 0;
    int registrationDigits;
    int personalCount = 0;

    printf("===== TICKET TRACE =====\n");
    printf("Enter number of ticket IDs (1 to 100): ");
    scanf("%d", &n);

    while (n < 1 || n > 100) {
        printf("Invalid number. Enter a value from 1 to 100: ");
        scanf("%d", &n);
    }

    printf("Enter %d ticket IDs (each from 1 to %d):\n", n, n);
    for (i = 0; i < n; i++) {
        printf("Ticket %d: ", i + 1);
        scanf("%d", &ticket[i]);

        while (ticket[i] < 1 || ticket[i] > n) {
            printf("Invalid ID. Enter a value from 1 to %d: ", n);
            scanf("%d", &ticket[i]);
        }
    }

    printf("\nTicket IDs entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ticket[i]);
    }

    printf("\n\nDuplicate ticket ID(s): ");
    duplicateFound = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (ticket[i] == ticket[j]) {
                break;
            }
        }

        if (j == i) {
            for (k = i + 1; k < n; k++) {
                if (ticket[i] == ticket[k]) {
                    printf("%d ", ticket[i]);
                    duplicateFound = 1;
                    break;
                }
            }
        }
    }

    if (duplicateFound == 0) {
        printf("None");
    }

    printf("\nMissing ticket ID(s): ");
    missingFound = 0;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < n; j++) {
            if (ticket[j] == i) {
                break;
            }
        }

        if (j == n) {
            printf("%d ", i);
            missingFound = 1;
        }
    }

    if (missingFound == 0) {
        printf("None");
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ticket[i] > ticket[j]) {
                outOfOrderPairs++;
            }
        }
    }
    printf("\nOut-of-order pairs: %d\n", outOfOrderPairs);

    printf("\nEnter the last two digits of YOUR registration number (0 to 99): ");
    scanf("%d", &registrationDigits);

    while (registrationDigits < 0 || registrationDigits > 99) {
        printf("Invalid digits. Enter a value from 0 to 99: ");
        scanf("%d", &registrationDigits);
    }

    for (i = 0; i < n; i++) {
        if (ticket[i] == registrationDigits) {
            personalCount++;
        }
    }

    printf("Personal check: ticket ID %d appears %d time(s).\n",
           registrationDigits, personalCount);

    return 0;
}
