// Following Problem Description this should be valid solution, no?
/*
#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, m, solved[101][12] = { false }, last[12] = { -1 }, seen;
	cin >> n >> t >> m;

	int time, id;
	string ver;
	char prob;
	while(m--) {
		cin >> time >> id >> prob >> ver;
		seen |= (1 << (prob - 'A'));
		if (ver == "No" || solved[id][prob - 'A'])
			continue;
		solved[id][prob - 'A'] = time;
		last[prob - 'A'] = id;
	}

	for(int i = 0; i < 12; i++)
		if (seen & (1 << i))
			if (last[i] == -1)
				cout << (char)('A' + i) << " - -" << endl;
			else
				cout << (char)('A' + i) << " " << solved[last[i]][i] << " " << last[i] << endl;

	return 0;
}
*/
#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, m, solved[101][12] = { false }, last[12];
	memset(last, -1, sizeof last);
	cin >> n >> t >> m;

	int time, id;
	string ver;
	char prob;
	while(m--) {
		cin >> time >> id >> prob >> ver;
		if (ver[0] == 'N' || solved[id][prob - 'A'])
			continue;
		solved[id][prob - 'A'] = time;
		last[prob - 'A'] = id;
	}

	for(int i = 0; i < n; i++)
		if (last[i] == -1)
			cout << (char)('A' + i) << " - -" << endl;
		else
			cout << (char)('A' + i) << " " << solved[last[i]][i] << " " << last[i] << endl;

	return 0;
}