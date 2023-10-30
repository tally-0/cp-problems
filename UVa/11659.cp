#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i, a, arr[21][2];
	while(cin >> i >> a && i + a) {
		memset(arr, 0, sizeof(arr));
		for(int j = 0, x, y; j < a; j++) {
			cin >> x >> y;
			x--;
			if (y > 0)
				arr[x][0] |= (1 << (y - 1));
			else
				arr[x][1] |= (1 << (-y - 1));
		}
		int maxnr = 0;
		for(int j = 0; j < (1 << i); j++) {
			int f = true, nr = 0;
			for(int k = 0; k < i; k++) {
				if (j & (1 << k)) {
					if (((~j & ((1 << i) - 1)) & arr[k][1]) != arr[k][1] || (j & arr[k][0]) != arr[k][0]) {
						f = false;
						break;
					}
					nr++;
				}
			}
			if (f)
				maxnr = max(maxnr, nr);
		}
		
		cout << maxnr << endl;
	}	
							
	return 0;
}