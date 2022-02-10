import sys
import decimal

for line in sys.stdin:
    decimal.getcontext().prec = 500
    d =decimal.Decimal(int(line))
    res = d**(decimal.Decimal(1) / decimal.Decimal(3))
    print(round(res))