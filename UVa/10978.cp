#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		string arr[52], a, b;
		int pos = -1;
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			int len = b.length();
			while(len) {
				pos += 1;
				pos %= n;
				if (arr[pos] == "")
					len--;
			}
			arr[pos] = a;
		}
		for(int i = 0; i < n - 1; i++)
			cout << arr[i] + " ";
		cout << arr[n - 1] << endl;
	}

	return 0;
}