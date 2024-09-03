#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, h;
	cin >> t;
	while(t--) {
		cin >> n >> h;
		
		string s;
		for(int i = 0; i < n - h; i++)
			s += '0';
		for(int i = 0; i < h; i++)
			s += '1';
		do
			cout << s << endl;
		while(next_permutation(begin(s), end(s)));
		if (t)
			cout << endl;
	}

	return 0;
}