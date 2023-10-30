//#include<iostream>
#include<cmath>
#include<stdio.h>
//#include<iomanip>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout << setprecision(2);*/

	int a, b, c, d;
	ll e, f;
	for(a = 1; 4 * a <= 2000; a++) {
		for(b = a; a + 3*b <= 2000; b++) {
			for(c = b; a + b + c + c <= 2000; c++) {
				e = (ll) a * b * c;
				f = a + b + c;
				if (e <= 1000000) continue;
				if ((f * 1000000) % (e - 1000000)) continue;
				d = (f * 1000000) / (e - 1000000);
				f += d;
				if (f > 2000 || d < c) continue;
				//cout << a/100 << "." << a%100 << " " << b/100  << "." << b%100 << " " << c/100 << "." << c%100 << " " << d/100 << "." << d%100 << endl;
				printf("%d.%02d %d.%02d ", a/100, a%100, b/100, b%100);
        		printf("%d.%02d %d.%02d\n", c/100, c%100, d/100, d%100);
			}
		}
	}

	return 0;
}