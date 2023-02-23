#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//     int i; cin >> i;
//     string s;
//     cin >> s;
//     int len = s.length();
//     int res = 0;
//     for (int i = 0; i< len; i++)
//     {
//         res += s[i] - '0';
//     }
//     cout << res;
// }

void printVec(vector<auto>& v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    string today = "2022.05.19";
    vector<string> terms = {"A 6", "B 12", "C 3"};
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};

    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(5,7));
    int todayDay = stoi(today.substr(8,today.length()));
    int todayTotal = todayDay + todayMonth*28 + todayYear*12*28;

    unordered_map<string, int> map;
    for (string s : terms)
    {
        string temp = s.substr(0,1);
        int value = stoi(s.substr(2,s.length()));
        //cout << temp << " " << value << endl;
        map.insert({temp, value*28});
    }

    int ind = 1;
    vector<int> answer;
    // printVec(answer);
    for (string s : privacies)
    {
        int yr = stoi(s.substr(0,4));
        int month = stoi(s.substr(5,7));
        int day = stoi(s.substr(8,10));
        int total = day + month*28 + yr*12*28;
        //cout << total << endl;

        string key = s.substr(11,s.length());
        int toAdd = map.find(key)->second;

        if(todayTotal > (total + toAdd-1)) 
        {
            //cout << todayTotal << " " << total + toAdd << endl;
            answer.push_back(ind);
        }
        ind++;
    }
    
    printVec(answer);
    
}