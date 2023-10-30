#include<iostream>

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int a = 6; a <= 200; a++) {
        int A = a * a * a;
        for(int b = 2; b < a; b++) {
            int B = b * b * b;
            for(int c = b; c < a; c++) {
                int C = c * c * c;
                if (A < B + C)
                    break;
                for(int d = c; d < a; d++) {
                    if (A < B + C + D)
                        break;
                    if (A == B + C + D)
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                }
            }
        }
    }

    return 0;
}
