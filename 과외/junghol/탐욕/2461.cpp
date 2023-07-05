#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> flower;          // blossom date, withering date

// sorting by blossom date
bool compByBlossom(flower & a, flower & b)
{
    // if the starting date is the same, sort ascending by withering date
    if (a.first == b.first)
        return a.second < b.second;

    // sort it by blossoming date in ascending order
    return a.first < b.first;
}


// materials
int n;
vector<flower> flowers;
int start = 3*100 + 1;
int endDate = 11 * 100 + 30;
int ans = 0;

void printFlower(flower &f)
{
    int startMonth = f.first/100;
    int endMonth = f.second/100;
    cout << "Start : " << startMonth << "/" << f.first - (startMonth*100) << endl;
    cout << "End : " << endMonth << "/" << f.second - (endMonth * 100) << endl;
}

void printAll(vector<flower> & flowers)
{
    for (flower f : flowers)
    {
        printFlower(f);
        cout << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int bMonth, bDate, wMonth, wDate;
        cin >> bMonth >> bDate >> wMonth >> wDate;
        
        int blossom = bMonth * 100 + bDate;
        int wither = wMonth * 100 + wDate;

        flowers.push_back({blossom, wither});
    }

    // sort by blossom date
    sort(flowers.begin(), flowers.end(), compByBlossom);

    // printAll(flowers);

    
}