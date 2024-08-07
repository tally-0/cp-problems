#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, req[100001] = { 0 };
	cin >> n >> k;
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		req[a]++;
	}

	int load = 0;
	for(int i = 0; i <= 999; i++)
		load += req[i];
	int maxload = load;
	for(int i = 1000; i <= 100000; i++) {
		load += req[i] - req[i - 1000];
		maxload = max(maxload, load);
	}

	cout << (maxload + k - 1) / k;
		 

	return 0;
}