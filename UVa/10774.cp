#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n;

		int s = n, c = -1;
		do {
			c++;
			n = s;
			s &= ~(1 << (31 - __builtin_clz(n)));
			s <<= 1;
            s++;
		} while(s != n);
		
		cout << "Case " << t << ": " << c << " " << s << endl;
	}

	return 0;
}