#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, prev, cur;
	while(cin >> n) {
		bool arr[3000] = { false }, valid = true;
		cin >> prev;
		for(int i = 1; i < n; i++) {
			cin >> cur;
			if (abs(cur - prev) >= n)
				valid = false;
			if (arr[abs(cur - prev)])
				valid = false;
			arr[abs(cur - prev)] = true;
			prev = cur;
		}
		if (valid)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}

	return 0;
}