#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> substance;   // <lower bound, upper bound> in terms of temp
int n;
vector<substance> substances;

// Comparator for substance
bool compSub(substance & a, substance & b)
{
    // sort  rule 1. by upper bound
    if (a.second != b.second)
        return a.second < b.second;
    // sort rule 2. by lower bound
    else
        return a.first < b.first;

    return false;
}

void printSub()
{
    for (substance i : substances)
    {
        cout << i.first << " " << i.second << endl;
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int low, high;
        cin >> low >> high;
        substances.push_back({low, high});
    }

    // sort according to lower temp bound
    sort(substances.begin(), substances.end(), compSub);
    // printSub();
}

int getFridge()
{
    int cnt = 1;
    int low = substances[0].first;
    int high = substances[0].second;

    for (substance s : substances)
    {
        int currLow = s.first;
        int currHigh = s.second;

        // if this subsance is out of the range
        if (currLow > high)
        {
            cnt++;
            high = currHigh;
        }
    }

    return cnt;
}


int main()
{
    input();
    cout << getFridge();
}