#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int no = 0, ne = 0;
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		if (a % 2)
			no++;
		else
			ne++;
	}
	
	while(no > ne) {
		no -= 2;
		ne += 1;
	}
	while(ne - no > 1)
		ne--;

	cout << 2 * no + (ne > no);

	return 0;
}