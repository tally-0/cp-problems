#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mi = -1, mp = -1;
	for(int i = 1; i <= 5; i++) {
		int s = 0, a;
		for(int j = 0; j < 4; j++) {
			cin >> a;
			s += a;
		}
		if (s > mp) {
			mi = i;
			mp = s;
		}
	}

	return 0;
}