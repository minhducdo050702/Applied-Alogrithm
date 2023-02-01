#include <bits/stdc++.h>
using namespace std;
string P1;
string P2;
string T;
string replace1(string P1, string P2, string T)
{

    do
    {
        int start = T.find(P1);
        if (start > T.size())
            break;
        T.replace(start, P1.size(), P2);
    } while (1);
    return T;
}

int main()
{
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);
    cout << replace1(P1, P2, T);
    return 0;
}
