#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		int a = 0;
		int b = 0;
		int i = 1;
		for(int j = 0; j < 31; j++)
			if (n & (1 << j))
				if (i++ % 2)
					a |= 1 << j;
				else
					b |= 1 << j;
		cout << a << " " << b << endl;
	}

	return 0;
}