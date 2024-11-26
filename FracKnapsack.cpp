#include <iostream>
using namespace std;

int n = 5;
int p[] = {3, 3, 2, 5, 1};
int w[] = {10, 15, 10, 12, 8};
int W = 10;

int main() {
    int cur_w=W;
    float tot_v=0;
    int maxi;
    int used[n]={0};

    while (cur_w > 0) {
        maxi = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0 && (maxi == -1 || (float) w[i] / p[i] > (float) w[maxi] / p[maxi])) {
                maxi = i;
            }
        }
        used[maxi] = 1;
        cur_w -= p[maxi];
        tot_v +=w[maxi];

        if ( cur_w < 0) {
            tot_v -= w[maxi];
            tot_v += (1 + (float) cur_w / p[maxi])*w[maxi];
        }
    }

    cout << "Maximum total value obtained: " << tot_v << endl;

    return 0;
}