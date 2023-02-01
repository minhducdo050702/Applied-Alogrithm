#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;

int S0[MAX];
int S1[MAX];
int N, K1, K2;
void process()
{
    memset(S0, 0, sizeof(S0));
    memset(S1, 0, sizeof(S1));
    S0[1] = 1;
    S1[K1] = 1;
    S0[0] = 1;
    for (int i = K1 + 1; i <= N; i++)
    {
        for (int j = K1; j <= K2; j++)
            if (i - j >= 0)
                S1[i] += S0[i - j];
        S0[i] = S1[i - 1];
    }
}
int main()
{
    cin >> N >> K1 >> K2;
    process();
    cout << S1[N - 1] + S1[N];
    return 0;
}