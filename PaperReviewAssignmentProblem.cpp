#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, m, b;
int maxload = INT_MAX;
int can_review[MAX][MAX]; // can_review [i][j] nguoi i co the revew bai j
int review[MAX][MAX];     // nguoi i review bai j
int load[MAX];
int reviewed[MAX];                                                                              // bai i da duoc bao nhieu nguoi review
bool UCV(int i, int k) { return (can_review[i][k] && !review[i][k] && load[i] + 1 < maxload); } // UCV(i,k) returns true if person i can review paper k and has not already done so and the load of person i is less than maxload.

void TRY(int k)
{
    for (int i = 1; i <= m; i++)
    {
        if (UCV(i, k))
        {
            review[i][k] = 1;
            load[i]++;
            reviewed[k]++;
            if (reviewed[k] == b)
            {
                if (k < n)
                    TRY(k + 1);
                else
                {
                    int maxtemp = 0;
                    for (int j = 1; j <= m; j++)
                        maxtemp = max(maxtemp, load[j]);
                    maxload = min(maxload, maxtemp);
                }
            }
            else
                TRY(k);
            review[i][k] = 0;
            load[i]--;
            reviewed[k]--;
        }
    }
}

int main()
{
    cin >> n >> m >> b;
    int temp1, temp2;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp1;
        for (int j = 1; j <= temp1; j++)
        {
            cin >> temp2;
            can_review[temp2][i] = 1;
        }
    }
    TRY(1);
    cout << maxload;
}