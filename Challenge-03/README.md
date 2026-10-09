# Challenge 03 - SMARTCART

**"Calculate. Check. Decide."**

A C program that calculates the discount, delivery charge, and final payable amount based on the purchase amount, customer type, and delivery distance.

## Discount rules

| Customer type | Purchase amount | Discount |
|---|---:|---:|
| Regular | Less than Rs. 1,000 | 0% |
| Regular | Rs. 1,000 to Rs. 1,999.99 | 5% |
| Regular | Rs. 2,000 or more | 10% |
| Premium | Less than Rs. 1,000 | 5% |
| Premium | Rs. 1,000 to Rs. 1,999.99 | 10% |
| Premium | Rs. 2,000 or more | 20% |

## Delivery charge rules

| Distance | Delivery charge |
|---:|---:|
| Up to 5 km | Free |
| More than 5 km and up to 10 km | Rs. 50 |
| More than 10 km | Rs. 100 |

The program rejects negative purchase amounts or distances and customer types other than `1` or `2`.

## Compile and run

With GCC:

```sh
gcc Challenge-03.c -o Challenge-03
./Challenge-03
```

On Windows, run the compiled program with:

```powershell
.\Challenge-03.exe
```

## Sample run

Enter `2500` for the purchase amount, `2` for Premium Customer, and `8` for the delivery distance in km. The program displays floating-point values with six digits after the decimal point because the source uses `%f`.

```text
===== SMARTCART =====
Enter purchase amount: Rs. 2500
Customer Type:
1. Regular Customer
2. Premium Customer
Enter customer type (1 or 2): 2
Enter delivery distance in km: 8

===== BILL SUMMARY =====
Purchase Amount : Rs. 2500.000000
Discount Rate   : 20.000000
Discount Amount : Rs. 500.000000
Delivery Charge : Rs. 50.000000
Final Payable   : Rs. 2050.000000
```

For these inputs, the premium customer receives a 20% discount (Rs. 500), and the 8 km delivery charge is Rs. 50. The final payable amount is Rs. 2,050.
