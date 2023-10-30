#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#define vi vector<int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout << setprecision(5);
	
	int C, S, tcase = 1 ;
	double avg, imbalance;
	while(cin >> C >> S) {
		avg = 0;
		vi s(2*C, 0);
		for(int i = 0; i < S; i++) {
			cin >> s[i];
			avg += double(s[i]);
		}

		avg /= double(C);
		sort(s.begin(), s.end());

		imbalance = 0;
		cout << "Set #" << tcase << endl;
		for(int i = 0; i < C; i++) {
			cout << " " << i << ":";
			if (s[i]) cout << " " << s[i];
			if (s[2*C-i-1]) cout << " " << s[2*C-i-1];
			cout << endl;
			imbalance += abs(avg - double(s[2*C-i-1] + s[i]));
		}
		cout << "IMBALANCE = " << imbalance << endl << endl;

		tcase++;
	}
	return 0;
}

