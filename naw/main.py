import math
x, y = map(int, input().split())
sin_x = math.sin(x)
cos_x = math.cos(x);
S_up = sin_x * sin_x - cos_x * cos_x
S_down = math.sin((x+y)/2)
LG = math.log(x)
print((M*LG - math.sqrt(x - 1))/3)	