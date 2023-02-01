#include <bits/stdc++.h>
using namespace std;
int n, L;
void standard(string temp)
{
    for (int i = temp.length(); i < L; i++)
        cout << 0;
    cout << temp;
    cout << endl;
}
int main()
{
    cin >> n >> L;
    string temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        standard(temp);
    }
    return 0;
}
