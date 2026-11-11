# CODE2THINK Challenge 10 - ECOGUARD

This menu-driven C program analyses seven days of temperature, humidity, and AQI readings across five campus zones. All entered test values are **simulated classroom data**, not campus measurements.

## Requirements covered

- Three 2D arrays (`temp`, `humidity`, and `aqi`) with `ZONES = 5` and `DAYS = 7`.
- Validation: temperature 10-50 C, humidity 0-100%, and AQI 0-500.
- Readable data matrices, seven-day averages, risk-day counts, and triggered day numbers.
- A risk day has AQI > 150, temperature > 35 C, or humidity > 80%; it is counted only once.
- Required user-defined functions, a `dataReady` gate, recommendations, and tied ranks.

## Green Index classroom model

```text
AQI Score         = 100 - (Average AQI / 5)
Temperature Score = 100 - 4 x |Average Temperature - 25|
Humidity Score    = 100 - 2 x |Average Humidity - 50|
Green Index       = 0.4 x AQI Score + 0.3 x Temperature Score + 0.3 x Humidity Score
```

Each component score is clamped to zero. The absolute differences use `if-else`, without a mathematics library.

## Compile and run

```powershell
gcc -Wall -Wextra -std=c11 EcoGuard.c -o EcoGuard.exe
.\EcoGuard.exe
```

## Test checklist

1. Normal readings: verify all three zone averages.
2. AQI risk: use AQI 151 on one day and verify that day is flagged.
3. Temperature and humidity risks: test 36 C and 81% independently.
4. Multiple triggers: use 36 C, 81%, and AQI 151 on one day; it must count once.
5. No risk: keep all readings at or below thresholds.
6. Green Index floor: use average AQI 500 and confirm its component becomes zero.
7. Tied rank: enter identical values for two zones and confirm the same rank.
8. Invalid data: try 9 C, 101% humidity, and AQI 501; each must be re-entered.

## Files

- `EcoGuard.c` - complete C program.
- `Eco_Action_Note.md` and `Eco_Action_Note.pdf` - the one-page Eco Action Note.
