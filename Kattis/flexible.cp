#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, p, l[100];
	cin >> w >> p;
	for(int i = 0; i < p; i++)
		cin >> l[i];
	
	bool ans[101] = { false };
	ans[w] = true;
	for(int i = 0; i < p; i++)
		ans[l[i]] = true;
	for(int i = 0; i < p - 1; i++)
		for(int j = i + 1; j < p; j++)
			ans[l[j] - l[i]] = true;

	for(int i = 0; i < 101; i++)
		if (ans[i])
			cout << i << " ";

	return 0;
}