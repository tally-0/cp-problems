#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h[6], a, b;
	for(int i = 0; i < 6; i++)
		cin >> h[i];
	cin >> a >> b;
	sort(h, h + 6);

	do {
		if (h[0] + h[1] + h[2] != a)
			continue;
		if (h[3] + h[4] + h[5] != b)
			continue; 
		if (!(h[0] > h[1] && h[1] > h[2]))
			continue;
		if (!(h[3] > h[4] && h[4] > h[5]))
			continue;
		break;
	} while(next_permutation(h, h + 6));

	for(const int &i : h)
		cout << i << " ";

	return 0;
}