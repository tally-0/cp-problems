/*
O(n^2) bottom-up dp

#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, len[10000];
	pii blocks[10000];
	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			cin >> blocks[i].first >> blocks[i].second;
		blocks[n++] = { INT_MAX, INT_MAX };
		sort(blocks, blocks + n);

		for(int i = 0; i < n; i++)
			len[i] = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < i; j++)
				if (blocks[j].second <= blocks[i].second)
					len[i] = max(len[i], len[j] + 1);

		cout << len[n - 1] - 1 << endl;
	}
	cout << "*" << endl;

	return 0;
}*/


#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, mem[10000];
	pii blocks[10000];
	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			cin >> blocks[i].first >> blocks[i].second;
		sort(blocks, blocks + n);
		
		int len = 0;
		for(int i = 0; i < n; i++) {
			int j = upper_bound(mem, mem + len, blocks[i].second) - mem;
			mem[j] = blocks[i].second;
			if (j == len)
				len++;
		}

		cout << len << endl;
	}
	cout << "*\n";

	return 0;
}