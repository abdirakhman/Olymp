import os
print("Name of problem:")
G = input()
stxr = "mkdir -p /home/ismail_a/Documents/CODES/Codeforces\ Archive/" + G
os.system(stxr)
sss = "/home/ismail_a/Documents/CODES/Codeforces\ Archive/" + G + '/'
os.system("cp /home/ismail_a/Documents/Template/input " + sss)
os.system("cp /home/ismail_a/Documents/Template/main.cpp " + sss)
os.system("cp /home/ismail_a/Documents/Template/output " + sss)