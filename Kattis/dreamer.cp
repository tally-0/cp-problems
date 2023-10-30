#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

#define endl '\n'

bool leap(int y) {
	if(!(y % 400))
		return true;
    if(!(y % 100))
		return false;
    if(!(y % 4))
		return true;
    return false;
}

int main() {
	int t, digs[8];
	string in;
	cin >> t;
	cin.ignore();
	while(t--) {
		getline(cin, in);
		int n = 0;
		for(int i = 0; i < 10; i++)
			if (i != 2 && i != 5)
				digs[n++] = in[i]-'0';

		sort(digs, digs + 8);
		int mind = 31, minm = 12, miny = 9876, numd = 0;
		do {
			int d = digs[0] * 10 + digs[1];
			int m = digs[2] * 10 + digs[3];
			int y = digs[4] * 1000 + digs[5] * 100 + digs[6] * 10 + digs[7];
			if (y < 2000)
				continue;
			if (m < 1 || m > 12)
				continue;
			if (d < 1)
				continue;
			if (m == 2) {
				if (d > (28 + leap(y)))
					continue;
			} else if (m <= 7) {
				if (d > (30 + (m % 2)))
					continue;
			} else {
				if (d > (31 - (m % 2)))
					continue;
			}
			numd++;
			if ((y < miny) || (y == miny && m < minm) || (y == miny && m == minm && d < mind)) {
				miny = y;
				minm = m;
				mind = d;
			}
		} while(next_permutation(digs, digs + 8));

		if (numd)
			printf("%d %02d %02d %d\n", numd, mind, minm, miny);
		else
			printf("0\n");
	}

	return 0;
}