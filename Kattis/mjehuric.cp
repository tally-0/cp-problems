#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int arr[5];
	for(int i = 0; i < 5; i++)
		cin >> arr[i];
	
	bool sorted;
	do {
		sorted = true;
		for(int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				sorted = false;

				int swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				
				for(int j = 0; j < 4; j++)
					cout << arr[j] << " ";
				cout << arr[4] << endl;
			}
		}
	} while (!sorted);
				

	return 0;
}