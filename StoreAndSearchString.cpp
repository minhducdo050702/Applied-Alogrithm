#include <bits/stdc++.h>
using namespace std;
set<string> s;
int FIND(string k)
{
    set<string>::iterator it = s.find(k);
    if (it == s.end())
        return 0;
    return 1;
}
int INSERT(string k)
{
    int size_before = s.size();
    s.insert(k);
    int size_after = s.size();
    if (size_before == size_after)
        return 0;
    return 1;
}
int main()
{
    string temp;
    cin >> temp;
    while (temp != "*")
    {
        s.insert(temp);
        cin >> temp;
    }
    cin >> temp;
    while (temp != "***")
    {
        if (temp == "find")
        {
            cin >> temp;
            cout << FIND(temp) << endl;
        }
        if (temp == "insert")
        {
            cin >> temp;
            cout << INSERT(temp) << endl;
        }
        cin >> temp;
    }
    return 0;
}