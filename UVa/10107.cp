#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int arr[10000];
	int i = 0;
	while(cin >> arr[i++]) {
		nth_element(arr, arr + i / 2, arr + i);
		
		if (i % 2)
			cout << *(arr + i / 2) << endl;
		else {
			nth_element(arr, arr + i / 2 - 1, arr + i);
			cout << (*(arr + i / 2) + *(arr + i / 2 - 1)) / 2 << endl;
		}
	}

	return 0;
}