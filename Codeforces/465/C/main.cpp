#include <bits/stdc++.h>
using namespace std;
 
int main() {
	double R,x1,x2,y1,y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	double d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
	y2 -= y1;
	x2 -= x1;
	if(sqrt(d) >= R)
		printf("%.6f %.6f %.6f\n" ,x1,y1,R);
	else {
		double r = (sqrt(d)+R)/2-sqrt(d);
		double m = y2/x2;
		double a = y2/r;
		double b = x2/r;
		double x = m*b;
		double y = m*a;
		printf("%.9f %.9lf %.9f\n",x1+x,y1+y,r+sqrt(d));
	}
	return 0;
}
