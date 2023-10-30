/*
Brute-Force as per hint in Halim's Competitive Programming
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int digs[6];
	string in;
	getline(cin, in);

	int n;
	for(const char &c : in)
		digs[n++] = c - '0';
	int x = 0, mult = 1;
	for(int i = 1; i <= n; i++) {
		x += digs[n - i] * mult;
		mult *= 10;
	}
	sort(digs, digs + n);

	int mindiff = INT_MAX, ans = 0;
	do {
		int num = 0;
		mult = 1;
		for(int i = 1; i <= n; i++) {
			num += digs[n - i] * mult;
			mult *= 10;
		}
		if (num > x && ((num - x) < mindiff)) {
			ans = num;
			mindiff = num - x;
		}
	} while(next_permutation(digs, digs + n));

	cout << ans;

	return 0;
}
*/

// Optimized
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



int main() {
    string s, t;
    cin >> s;
    t = s;

    next_permutation(t.begin(), t.end());

    if(t <= s) {
        cout << "0" << endl;
    }
    else {
        cout << t << endl;
    }
}