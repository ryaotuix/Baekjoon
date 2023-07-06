#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> flower; // start date, end date


// can sort by ascending order of start date. If start date is the same, sort by end date in ascending order
bool compByEnd(flower & a, flower & b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int N;
vector<flower> flowers;
int minStart = 1300;
int maxEnd = 0;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int startMonth, startDate, endMonth, endDate;

        cin >> startMonth >> startDate >> endMonth >> endDate;

        int startN = startMonth * 100 + startDate;
        int endN = endMonth * 100 + endDate;

        minStart = min(minStart, startN);
        maxEnd = max(maxEnd, endN);

        flowers.push_back({startN, endN});
    }   

    // sort by ascending order
    sort(flowers.begin(), flowers.end(), compByEnd);
}


int main()
{
    input();

    // in case where we don't cover the end
    if (minStart > 301 || maxEnd <= 1130){
        cout << 0;
        return 0;
    }

    // find the first index, that covers 3/1 but ends the latest
    int startInd = 0;
    int currEndDate = 0;
    for (int i = 0; i < flowers.size(); i++)
    {
        // update start index where it has the latest end date
        if (flowers[i].first <= 301 && flowers[i].second > currEndDate)
        {
            startInd = i;
            currEndDate = flowers[i].second; 
        }

        if (flowers[i].first > 301)
            break;
    }

    int cnt = 1;

    while (true)
    {
        // if current flower we are looking covers entirely
        if (flowers[startInd].second > 1130)
        {
            break;
        }

        int latestInd = -1; // index that represents the flower with the latest withering date
        int dieNum = -1;
        for (int j = startInd + 1; j < N; j++)
        {
            // find a flower that blooms before the current flower dies
            if (flowers[j].first <= flowers[startInd].second)
            {
                // find a flower that dies the latest among those
                if (flowers[j].second > dieNum)
                {
                    latestInd = j;
                    dieNum = flowers[j].second;
                }
            }
        }

        startInd = latestInd; // new flower!

        // if we didn't find a new flower
        if (dieNum == -1)
        {
            cout << 0;
            return 0;
        }
        cnt++;
    }

    cout <<cnt;
}