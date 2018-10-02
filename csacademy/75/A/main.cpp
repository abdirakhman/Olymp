#include <iostream>
#include <cstdio>
 
using namespace std;
int main()
{
	int a, b, t, h,z=0,i=1;
	cin >> h >> t >> a >> b;
	while(z <= h){
		z += a;
		if (z >= h){
    		cout<<i;
    		return 0 ;
		}
		if (i % t == 0)
		z-=b;
		i++;
	}
	return 0;
}