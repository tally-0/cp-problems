#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, d, i;
	cin >> l;
	while(l--) {
		cin >> d >> i;

		int curd = 0, nn = 1;
		while(curd++ < d) {
			if (i % 2) {
				i = (i+1) / 2;
				nn *= 2;
			} else {
				i /= 2;
				nn = nn * 2 + 1;
			}
		}

		cout << nn / 2 << endl;
	}	

	return 0;
}