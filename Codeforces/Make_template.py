import os
print("Name of contest:")
G = input()
stxr = "mkdir -p /home/ismail_a/Documents/CODES/Codeforces/" + G
os.system(stxr)
print("How many problems:")
cnt = int(input())
for i in range(cnt):
	sss = "/home/ismail_a/Documents/CODES/Codeforces/" + G + '/' + chr(i+65) +'/'
	naw = stxr + '/' + chr(i+65)
	os.system(naw)
	os.system("cp /home/ismail_a/Documents/Template/input " + sss)
	os.system("cp /home/ismail_a/Documents/Template/main.cpp " + sss)
	os.system("cp /home/ismail_a/Documents/Template/output " + sss)