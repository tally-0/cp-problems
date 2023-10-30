#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, rno = 0, rnc = 0, lno = 0, lnc = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if (a) lno++;
		else lnc++;
		cin >> a;
		if (a) rno++;
		else rnc++;
	}
	
	cout << n - max(rno, rnc) + n - max(lno, lnc);

	return 0;
}