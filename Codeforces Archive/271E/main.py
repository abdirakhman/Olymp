from fractions import *

n, m = map(int, raw_input().split())
r = reduce(gcd, [x - 1 for x in map(int, raw_input().split())])
f = []
for i in range(1, int(r ** .5) + 1):
	if not r % i:
		f.extend([i, r / i])
s = set()
for x in f:
	while x < m:
		s.add(x)
		x *= 2
print sum(m - x for x in s)