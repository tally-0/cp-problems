#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b, c;
	while(cin >> c) {
		a = b = "";
		for(int i = 0; i < 6; i++)
			a += c[i];
		for(int i = 6; i < 12; i++)
			b += c[i];

		bool f = false;
		for(int i = 0; i < 5 && !f; i++) {
			for(int j = 0; j < 5 && !f; j++) {
				for(int k = 0; k < 5 && !f; k++) {
					f = (a == b);
					char tmp = a[0];
					a[0] = a[4];
					a[4] = a[5];
					a[5] = a[1];
					a[1] = tmp;
				}
				char tmp = a[0];
				a[0] = a[3];
				a[3] = a[5];
				a[5] = a[2];
				a[2] = tmp;
			}
			char tmp = a[1];
			a[1] = a[2];
			a[2] = a[4];
			a[4] = a[3];
			a[3] = tmp;
		}

		cout << (f ? "TRUE" : "FALSE") << endl;
	}

	return 0;
}