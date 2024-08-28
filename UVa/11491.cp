#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	while(cin >> n >> d && n + d) {
		string a, b;
		cin >> a;
		int m = n - d;

		for(const char& c : a) {
			while(!b.empty() && d && b.back() < c) {
				b.pop_back();
				d--;
			}
			b.push_back(c);
		}

		cout << b.substr(0, m) << endl;
	}

	return 0;
}