n = int(input())
a = input()
b = input()
ans = 0
fl = [0] * (n+5)
for i in range(n - 1):
    if fl[i] == 1:
        continue
	if (a[i] != b[i] and a[i + 1] != b[i + 1] and a[i] != a[i + 1]):
		ans += 1
		fl[i] = 1
		fl[i + 1] = 1
for i in range(n):
	if (fl[i] == 1):
		continue
	if (a[i] != b[i]):
		ans += 1
print(ans)