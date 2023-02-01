#include <bits/stdc++.h>
using namespace std;
string P;
string T;
int dem(string P, string T)
{
    int dem1 = 0;
    int start;
    do
    {
        start = T.find(P);
        if (start > T.size())
            break;
        else
        {
            dem1++;
            T.replace(start, P.size(), " ");
        }
    } while (1);
    return dem1;
}

int main()
{
    getline(cin, P);
    getline(cin, T);
    cout << dem(P, T);
    return 0;
}