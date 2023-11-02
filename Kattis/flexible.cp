#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, p, walls[100], pos[100];
	cin >> w >> p;
	for(int i = 0; i < p; i++)
		cin >> walls[i];

	memset(pos, false, sizeof(pos));
	for(int i = 0; i < p; i++)
		pos[walls[i]] = pos[w - walls[i]] = true;
	for(int i = 0; i < p - 1; i++)
		for(int j = i + 1; j < p; j++)
			pos[walls[j] - walls[i]] = true;

	for(int i = 1; i < w; i++)
		if (pos[i])
			cout << i << " ";
	cout << w;

	return 0;
}