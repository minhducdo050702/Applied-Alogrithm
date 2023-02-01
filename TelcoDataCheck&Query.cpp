#include <bits/stdc++.h>
using namespace std;
string fnumber;
string tnumber;
string ftime;
string ttime;
string date;
map<string, int> callcount;
map<string, int> timecount;
bool checkvalid(string number)
{
    if (number.length() != 10)
        return false;
    else
        for (int i = 0; i < 10; i++)
            if (number[i] < '0' || number[i] > '9')
                return false;
    return true;
}
int converttime(string time)
{
    return (time[7] - 48) + 10 * (time[6] - 48) + 60 * (time[4] - 48) + 600 * (time[3] - 48) + 3600 * (time[1] - 48) + 36000 * (time[0] - 48);
}
int counttime(string ftime, string ttime)
{
    return converttime(ttime) - converttime(ftime);
}
int main()
{
    bool valid = true;
    int totalcall = 0;
    string sign;
    do
    {
        cin >> sign;
        if (sign == "#")
            break;
        cin >> fnumber >> tnumber >> date >> ftime >> ttime;
        valid = checkvalid(fnumber);
        valid = checkvalid(tnumber);
        callcount[fnumber]++;
        timecount[fnumber] += counttime(ftime, ttime);
        totalcall++;
    } while (1);
    do
    {
        cin >> sign;
        if (sign == "#")
            break;
        else if (sign == "?check_phone_number")
        {
            cout << valid << endl;
        }
        else if (sign == "?number_calls_from")
        {
            cin >> sign;
            cout << callcount[sign] << endl;
        }
        else if (sign == "?number_total_calls")
        {
            cout << totalcall << endl;
        }
        else if (sign == "?count_time_calls_from")
        {
            cin >> sign;
            cout << timecount[sign] << endl;
        }
    } while (1);
    return 0;
}
