#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int A[9][9];
int markH[9][10];    // markH[i][j] nghia la hang i da chua so j
int markC[9][10];    // markC[i][j] nghia la cot i da chua so j
int markV[3][3][10]; // markV[i][j][k] nghia la o vuong thu i j da chua cot k
bool UCV(int i, int k, int p)
{
    if ((markH[k][i] == 1) || (markC[p][i] == 1) || (markV[k / 3][p / 3][i] == 1))
        return false;
    if (A[k][p] != 0 && i != A[k][p])
        return false;
    return true;
}
void TRY(int k, int p)
{
    for (int i = 1; i <= 9; i++)
    {
        if (UCV(i, k, p))
        {
            markH[k][i] = 1;
            markC[p][i] = 1;
            markV[k / 3][p / 3][i] = 1;
            if (k == 8 && p == 8)
                cnt++;
            else
            {
                if (p < 8)
                    TRY(k, p + 1);
                else
                    TRY(k + 1, 0);
            }
            markH[k][i] = 0;
            markC[p][i] = 0;
            markV[k / 3][p / 3][i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 8; j++)
        {
            cin >> A[i][j];
        }
    TRY(0, 0);
    cout << cnt;
    return 0;
}