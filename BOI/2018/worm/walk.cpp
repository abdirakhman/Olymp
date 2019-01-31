#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int n, m, k, maxq;

int value(int x, int y, int z){
	if(x <= 0 || x > n ||
	   y <= 0 || y > m ||
	   z <= 0 || z > k) return 0;

	cout << "? " << x << ' ' << y << ' ' << z << endl;
	int ans;
	cin >> ans;
	if (ans == -1) exit(0);
	return ans;
}

int value(int x){
	if(x <= 0 || x > n) return 0;

	cout << "? " << x << " 1 1" << endl;

	int ans;
	cin >> ans;
	if(ans == -1) exit(0);

	return ans;
}

double phi = (1 + sqrt(5)) / 2;


int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};


int goldenmean(int from, int to){
	int ans = from + (to - from + 1) / phi;
	return ans;
}


int gss(int from, int to, int x, int fx){
	if(to==from) return x;

	int y = goldenmean(from, to);

	if(2*x > from+to) y = from+to - y;
	if(x == y){
		++y;
	}
	int fy = value(y);
	if(x > y){
		swap(x, y);
		swap(fx, fy);
	}
	if( fx <= fy ) return gss( x+1, to, y, fy);
	else           return gss(from, y-1, x, fx);
}



int main(){
	srand(561);

	cin >> n >> m >> k >> maxq;
	if (k > 1) {
    	int samples = maxq/2; // I'm feeling lucky 

    	int record = 0;
    	int x, y, z;
    	for(int i=0; i<samples; ++i){
            
            int a = 1+rand()%n,
                b = 1+rand()%m,
                c = 1+rand()%k;
            
            int res = value(a, b, c);
            if(res > record){
                record = res;
                x = a, y = b, z = c;
            }
    	}
    	
    	vector<bool> tried(6, false);
    	foo:

    	int left = 0;
    	for(int i=0; i<6; ++i)
            left += (int)!tried[i];

    	if(left == 0){
            cout << "! " << x << ' ' << y << ' ' << z << endl;
            return 0;
    	}
    	
    	int r = rand() % left;

    	for(int i=0; i<6; ++i) if(!tried[i]){
            if(r == 0){
                int x1 = x + dx[i],
                    y1 = y + dy[i],
                    z1 = z + dz[i];

                int res = value(x1, y1, z1);

                if(res > record){
                    record = res;
                    x = x1;
                    y = y1;
                    z = z1;
                    for(int j=0; j<6; ++j)
                        tried[j] = false;
                    tried[i ^ 1] = true;
                    goto foo;
                } else {
                    tried[i] = true;
                    goto foo;
                }
            }
            --r;
    	}
	} else if (m > 1) {
		
	} else {
		int x = goldenmean(1, n);
		int res = gss(1, n, x, value(x));
		cout << "! " << res << ' ' << 1 << ' ' << 1 << endl;
				
	}
}