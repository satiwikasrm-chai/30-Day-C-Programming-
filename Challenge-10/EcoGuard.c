#include <stdio.h>

#define ZONES 5
#define DAYS 7

void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
                       float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]);
void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
                     int riskDays[ZONES]);
void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES],
                       float greenIndex[ZONES]);
void displayRanking(float greenIndex[ZONES]);
void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES],
                            int riskDays[ZONES]);
void displayAverages(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]);
int readChoice(void);

int main(void) {
    float temp[ZONES][DAYS] = {0}, humidity[ZONES][DAYS] = {0};
    int aqi[ZONES][DAYS] = {0}, riskDays[ZONES] = {0};
    float avgTemp[ZONES] = {0}, avgHumidity[ZONES] = {0}, avgAQI[ZONES] = {0},
          greenIndex[ZONES] = {0};
    int choice, dataReady = 0;

    do {
        printf("\nECOGUARD - Campus Environmental Monitoring\n");
        printf("1 Input / Update Data\n2 Display Data\n3 Zone-wise Averages\n4 Detect Risk Days\n");
        printf("5 Green Index and Ranking\n6 Recommendations\n7 Exit\nEnter choice: ");
        choice = readChoice();
        if (choice == 1) {
            inputData(temp, humidity, aqi);
            dataReady = 1;
        } else if (choice >= 2 && choice <= 6 && !dataReady)
            printf("Enter data first using option 1.\n");
        else if (choice == 2)
            displayData(temp, humidity, aqi);
        else if (choice == 3) {
            calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
            displayAverages(avgTemp, avgHumidity, avgAQI);
        } else if (choice == 4)
            detectRiskZones(temp, humidity, aqi, riskDays);
        else if (choice == 5) {
            calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
            computeGreenIndex(avgTemp, avgHumidity, avgAQI, greenIndex);
            displayRanking(greenIndex);
        } else if (choice == 6) {
            calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
            detectRiskZones(temp, humidity, aqi, riskDays);
            displayRecommendations(avgTemp, avgHumidity, avgAQI, riskDays);
        } else if (choice != 7)
            printf("Invalid choice.\n");
    } while (choice != 7);
    return 0;
}

int readChoice(void) {
    int choice;
    if (scanf("%d", &choice) != 1)
        choice = 0;
    while (getchar() != '\n') {
    }
    return choice;
}

void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]) {
    int z, d;
    for (z = 0; z < ZONES; z++) {
        printf("\nZone %d\n", z + 1);
        for (d = 0; d < DAYS; d++) {
            do {
                printf("Day %d temperature (10-50 C): ", d + 1);
                if (scanf("%f", &temp[z][d]) != 1)
                    temp[z][d] = -1;
                while (getchar() != '\n') {
                }
            } while (temp[z][d] < 10 || temp[z][d] > 50);
            do {
                printf("Day %d humidity (0-100%%): ", d + 1);
                if (scanf("%f", &humidity[z][d]) != 1)
                    humidity[z][d] = -1;
                while (getchar() != '\n') {
                }
            } while (humidity[z][d] < 0 || humidity[z][d] > 100);
            do {
                printf("Day %d AQI (0-500): ", d + 1);
                if (scanf("%d", &aqi[z][d]) != 1)
                    aqi[z][d] = -1;
                while (getchar() != '\n') {
                }
            } while (aqi[z][d] < 0 || aqi[z][d] > 500);
        }
    }
}

void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]) {
    const char *names[ZONES] = {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports Area"};
    int z, d;
    printf("\nData matrices (rows: zones; columns: days 1-7)\n");
    for (z = 0; z < ZONES; z++) {
        printf("%s  Temp:", names[z]);
        for (d = 0; d < DAYS; d++)
            printf(" %.1f", temp[z][d]);
        printf("\n              Hum :");
        for (d = 0; d < DAYS; d++)
            printf(" %.1f", humidity[z][d]);
        printf("\n              AQI :");
        for (d = 0; d < DAYS; d++)
            printf(" %d", aqi[z][d]);
        printf("\n");
    }
}

void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
                       float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]) {
    int z, d;
    for (z = 0; z < ZONES; z++) {
        avgTemp[z] = avgHumidity[z] = avgAQI[z] = 0;
        for (d = 0; d < DAYS; d++) {
            avgTemp[z] += temp[z][d];
            avgHumidity[z] += humidity[z][d];
            avgAQI[z] += aqi[z][d];
        }
        avgTemp[z] /= DAYS;
        avgHumidity[z] /= DAYS;
        avgAQI[z] /= DAYS;
    }
}

void displayAverages(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]) {
    const char *names[ZONES] = {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports Area"};
    int z;
    printf("\nZone                 Temp       Humidity       AQI\n");
    for (z = 0; z < ZONES; z++)
        printf("%-16s %6.1f C %9.1f%% %9.1f\n", names[z], avgTemp[z], avgHumidity[z], avgAQI[z]);
}

void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
                     int riskDays[ZONES]) {
    const char *names[ZONES] = {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports Area"};
    int z, d;
    printf("\nRisk day: AQI > 150 OR temperature > 35 C OR humidity > 80%%.\n");
    for (z = 0; z < ZONES; z++) {
        riskDays[z] = 0;
        printf("%-16s Days:", names[z]);
        for (d = 0; d < DAYS; d++)
            if (aqi[z][d] > 150 || temp[z][d] > 35 || humidity[z][d] > 80) {
                printf(" %d", d + 1);
                riskDays[z]++;
            }
        if (!riskDays[z])
            printf(" none");
        printf(" | Count: %d\n", riskDays[z]);
    }
}

void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES],
                       float greenIndex[ZONES]) {
    int z;
    float aqiScore, tempScore, humidityScore, tempDifference, humidityDifference;
    for (z = 0; z < ZONES; z++) {
        aqiScore = 100 - avgAQI[z] / 5;
        if (avgTemp[z] >= 25)
            tempDifference = avgTemp[z] - 25;
        else
            tempDifference = 25 - avgTemp[z];
        if (avgHumidity[z] >= 50)
            humidityDifference = avgHumidity[z] - 50;
        else
            humidityDifference = 50 - avgHumidity[z];
        tempScore = 100 - 4 * tempDifference;
        humidityScore = 100 - 2 * humidityDifference;
        if (aqiScore < 0)
            aqiScore = 0;
        if (tempScore < 0)
            tempScore = 0;
        if (humidityScore < 0)
            humidityScore = 0;
        greenIndex[z] = 0.4f * aqiScore + 0.3f * tempScore + 0.3f * humidityScore;
    }
}

void displayRanking(float greenIndex[ZONES]) {
    const char *names[ZONES] = {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports Area"};
    int rank[ZONES], z, other, r;
    for (z = 0; z < ZONES; z++) {
        rank[z] = 1;
        for (other = 0; other < ZONES; other++)
            if (greenIndex[other] > greenIndex[z])
                rank[z]++;
    }
    printf("\nRank  Zone              Green Index\n");
    for (r = 1; r <= ZONES; r++)
        for (z = 0; z < ZONES; z++)
            if (rank[z] == r)
                printf("%4d  %-16s %.2f\n", rank[z], names[z], greenIndex[z]);
}

void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES],
                            int riskDays[ZONES]) {
    const char *names[ZONES] = {"Academic Block", "Hostel", "Library", "Cafeteria", "Sports Area"};
    int z;
    for (z = 0; z < ZONES; z++) {
        printf("%s: ", names[z]);
        if (avgAQI[z] > 150)
            printf("Reduce vehicle idling or improve ventilation. ");
        if (avgTemp[z] > 35)
            printf("Add shade or green cover. ");
        if (avgHumidity[z] > 80)
            printf("Check ventilation or stagnant-water sources. ");
        if (avgAQI[z] <= 150 && avgTemp[z] <= 35 && avgHumidity[z] <= 80) {
            if (riskDays[z])
                printf("Review the dates with individual risk readings. ");
            else
                printf("Continue monitoring. ");
        }
        printf("Risk days: %d\n", riskDays[z]);
    }
}
