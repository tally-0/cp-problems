#include<iostream>
#include<climits>

using namespace std;

#define endl '\n'
#define fi first
#define se second
typedef pair<string,pair<int,int>> sii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	string m[3] = {
		"single",
		"double",
		"triple"
	};
	for(int i = 1; i <= 20; i++) {
		for(int a = 1; a <= 3; a++) {
			if (t == a * i) {
				cout << m[a-1] << " " << i;
				return 0;
			}
			for(int j = 1; j <= 20; j++) {
				for(int b = 1; b <= 3; b++) {
					if (t == (a * i + b * j)) {
						cout << m[a-1] << " " << i << endl << m[b-1] << " " << j;
						return 0;
					}
					for(int k = 1; k <= 20; k++) {
						for(int c = 1; c <= 3; c++) {
							if (t == (a * i + b * j + c * k)) {
								cout << m[a-1] << " " << i << endl << m[b-1] << " " << j << endl << m[c-1] << " " << k;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "impossible";

	return 0;
}