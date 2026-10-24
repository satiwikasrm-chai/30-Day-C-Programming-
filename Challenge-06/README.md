# Challenge 06 Pattern Detective

A beginner-friendly C program that studies a list of smart-campus activity readings.

## What the program does

- Reads 5 to 12 activity readings.
- Checks that every reading is from 0 to 1000.
- Displays the original readings, sum, average, minimum, and maximum.
- Finds the second-largest distinct value.
- Counts local peaks.
- Finds the longest strictly increasing contiguous run.
- Rotates the same array right by `K` positions. A negative `K` rotates left.
- Calculates `D = (R % 9) + 1` using the last two registration-number digits and counts the rotated values divisible by `D`.

The code uses one array only. The rotation is performed in place, without a second array or sorting.

## Algorithm

1. Read a valid number of readings and then read every valid activity value.
2. Use loops to calculate the sum, minimum, maximum, peaks, and increasing run.
3. Find the second-largest value that is different from the maximum.
4. Convert `K` to a value between `0` and `N - 1`, then move the last value to the front one step at a time.
5. Calculate `D` and count the rotated values that are divisible by it.

## Compile and run

With GCC:

```sh
gcc Challenge-06.c -o Challenge-06
./Challenge-06
```

On Windows:

```powershell
.\Challenge-06.exe
```

## Example

For readings `10 20 15 30 25 40 35`, rotation `K = 2`, and registration digits `42`:

- The second-largest distinct value is `35`.
- There are `3` local peaks.
- The longest increasing run has length `2`.
- The rotated readings are `40 35 10 20 15 30 25`.
- `D` is `7`, and one rotated value is divisible by `7`.

## Suggested test cases

| Case | Values to test | What to check |
|---|---|---|
| Normal case | Mixed values with positive K | All calculations and rotation |
| All equal | `5 5 5 5 5` | No second-largest distinct value, no peaks |
| Decreasing | `9 8 7 6 5` | Longest increasing run is 1 |
| Duplicate maximum | `10 50 50 30 20` | Second-largest distinct value is 30 |
| Negative K | Any valid data with `K = -1` | Array rotates left by one |
| Large K | Any valid data with `K` larger than N | K is normalized correctly |
