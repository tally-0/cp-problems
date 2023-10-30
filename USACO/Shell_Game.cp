#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ifstream cin("shell.in");
	ofstream cout("shell.out");

	int n;
	cin >> n;
	
	int pp1 = 0, pp2 = 0, pp3 = 0;
	int p1 = 1; int p2 = 2; int p3 = 3;
	for(int i = 0; i < n; i++) {
		int a, b, g;
		cin >> a >> b >> g;
		auto swap = [=] (int &pos) mutable {
			if (pos == a) {pos = b;}
			else if (pos == b) {pos = a;}
		};
		swap(p1); swap(p2); swap(p3);
		if (g == p1) pp1++;
		if (g == p2) pp2++;
		if (g == p3) pp3++;
	}

	cout << int(max(max(pp1, pp2), pp3));
	return 0;
}