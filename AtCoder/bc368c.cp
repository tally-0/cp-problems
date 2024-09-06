#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, h;
	cin >> n;
	ll t = 0;
	while(n--) {
		cin >> h;
		t += 3 * (h / 5);
		h %= 5;
		while(h > 0) {
			t++;
			if (t % 3)
				h--;
			else
				h -= 3;
		} 
	}
	cout << t;

	return 0;
}