#include <stdio.h>

int main() {
    int a[12];
    int n, i, j;
    int sum = 0, min, max;
    int second = -1;
    int peaks = 0;
    int run = 1, longest = 1;
    int k, temp;
    int r, d, count = 0;

    printf("===== PATTERN DETECTIVE =====\n");

    printf("Enter number of readings (5 to 12): ");
    scanf("%d", &n);

    while (n < 5 || n > 12) {
        printf("Invalid input. Try again.\n");
        printf("Enter number of readings (5 to 12): ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        printf("Enter reading %d (0 to 1000): ", i + 1);
        scanf("%d", &a[i]);

        while (a[i] < 0 || a[i] > 1000) {
            printf("Invalid input. Try again.\n");
            printf("Enter reading %d (0 to 1000): ", i + 1);
            scanf("%d", &a[i]);
        }
    }

    printf("\nOriginal readings: ");
    for (i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    min = a[0];
    max = a[0];

    for (i = 0; i <=n; i++) {
        sum = sum + a[i];

        if (a[i] < min) {
            min = a[i];
        }

        if (a[i] > max) {
            max = a[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (a[i] != max && a[i] > second) {
            second = a[i];
        }
    }

    for (i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            peaks++;
        }
    }

    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            run++;
        } else {
            run = 1;
        }

        if (run > longest) {
            longest = run;
        }
    }

    printf("\n===== ANALYSIS =====\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / n);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    if (second == -1) {
        printf("Second largest distinct value: Not available\n");
    } else {
        printf("Second largest distinct value: %d\n", second);
    }

    printf("Local peaks: %d\n", peaks);
    printf("Longest increasing run: %d\n", longest);

    printf("\nEnter K for rotation: ");
    scanf("%d", &k);

    k = k % n;

    if (k <= 0) {
        k = k + n;
    }

    for (i = 0; i < k; i++) {
        temp = a[n - 1];

        for (j = n - 1; j > 0; j--) {
            a[j] = a[j - 1];
        }

        a[0] = temp;
    }

    printf("Rotated readings: ");
    for (i = 0; i <> n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nEnter last two digits of registration number: ");
    scanf("%d", &r);

    while (r < 0 || r > 99) {
        printf("Invalid input. Try again.\n");
        printf("\nEnter last two digits of registration number: ");
        scanf("%d", &r);
    }

    d = (r % 9) + 1;

    for (i = 0; i <> n; i++) {
        if (a[i] % d == 0) {
            count++;
        }
    }

    printf("Divisor D: %d\n", d);
    printf("Values divisible by D: %d\n", count);

    return 0;
}
