#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> a;
			if (a) {
				cout << abs(x-2)+abs(y-2) << endl;
				return 0;
			}
		}
	}

	return 0;
}