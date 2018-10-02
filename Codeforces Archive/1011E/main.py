from functools import reduce
from math import gcd
n, k = map(int, input().split())
A = list(map(int, input().split()))
G = gcd(k, reduce(lambda x,y:gcd(x,y),A))
print(k // G); print(*list(range(0, k, G)))