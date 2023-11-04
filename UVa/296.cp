#include <cstdio>
#include <string>

using namespace std;

int main() {

    int n, g, cor[10], mis[10];
    char gue[10][4];
	scanf("%d", &n);
    while(n--) {
        scanf("%d", &g);
        for(int i = 0; i < g; i++)
            scanf("%s %d/%d", gue[i], &cor[i], &mis[i]);

        int cnt = 0, ans;
        char s[4];
        for(int i = 0; i <= 9999 && cnt < 2; i++) {
            s[0] = '0' + i / 1000;
            s[1] = '0' + (i / 100) % 10;
            s[2] = '0' + (i / 10) % 10;
            s[3] = '0' + i % 10;
            bool f = true;
            for(int j = 0; j < g && f; j++) {
                int app[10] = { 0 }, a = 0, b = 0;
                for(int k = 0; k < 4; k++)
                    app[gue[j][k]-'0']++;
                for(int k = 0; k < 4; k++) {
                    if(app[s[k]-'0'] > 0) {
                        b++;
                        app[s[k]-'0']--;
                    }
                }
                for(int k = 0; k < 4; k++) {
                    if(s[k] == gue[j][k]) {
                        a++;
                        b--;
                    }
                }
                f = (cor[j] == a && mis[j] == b);
            }
            if(f) {
                cnt++;
                ans = i;
            }
        }

        if(cnt == 1)
            printf("%04d\n", ans);
        else if(cnt == 0)
            printf("impossible\n");
        else
            printf("indeterminate\n");
    }

    return 0;
}