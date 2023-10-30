#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc = 1, p, a, l[8];
	pii ap[8];
	while(cin >> p && p) {
		for(int i = 0; i < p; i++)
			cin >> l[i];
		sort(l, l + p);
		cin >> a;
		for(int i = 0; i < a; i++)
			cin >> ap[i].second >> ap[i].first;
		sort(ap, ap + a);

		int best[5], besto[8];
		for(int i = 0; i < 5; i++)
			best[i] = INT_MAX;
		do {
			int miss[5] = { 0 }, i = 0, t = 0;
			for(int j = 0; j < a; j++) {
				while(i < p && ap[j].first >= t + l[i])
					t += l[i++];
				int lomi = ap[j].first - t;
				int himi = i < p ? t + l[i] - ap[j].first : INT_MAX;
				miss[ap[j].second - 1] += min(lomi, himi);
			}
			for(int j = 0; j < 5; j++) {
				if (miss[j] > best[j])
					break;
				if (miss[j] < best[j]) {
					for(int k = 0; k < 5; k++)
						best[k] = miss[k];
					for(int k = 0; k < p; k++)
						besto[k] = l[k];
					break;
				}
			}
		} while (next_permutation(l, l + p));
		int s = 0;
		for(int i = 0; i < 5; i++)
			s += best[i];

		cout << "Data set " << tc << endl;
		cout << "Order:";
		for(int i = 0; i < p; i++)
			cout << " " << besto[i];
		cout << endl << "Error: " << s << endl;
		tc++;
	}

	return 0;
}