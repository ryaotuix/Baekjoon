#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> meeting; // <start, end>
int n;                          // number of meetings

// comparator functioin to Sort by Ending time of the meeting
bool compMeeting(meeting & a, meeting & b)
{
    // IMPORTANT
    if (a.second == b.second)
        return a.first < b.first;
    return (a.second < b.second);
}

// print meeting function
void printMeeting(vector<meeting> & meetings)
{
    int i = 0;
    for (meeting m : meetings)
    {
        cout << i << ": " << m.first << " " << m.second << endl;
    }
}

// GREEDY APPROACH
/*
sort by ending time
and then starting time
*/
int getMaxMeeting(vector<meeting> & meetings)
{
    int lastEnd = -1;

    int numMeeting = 0;
    for (meeting m : meetings)
    {
        int currStart = m.first;
        int currEnd = m.second;

        // if we start after the last end
        if (currStart >= lastEnd)
        {
            numMeeting++;               // we can have this meeting 
            lastEnd = currEnd;
        }
    }

    return numMeeting;
}


int main()
{
    // 0. INPUT DONE
    cin >> n;
    vector<meeting> meetingList;    // meeting list

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        meeting currM = make_pair(start, end);
        meetingList.push_back(currM);
    }

    // 1. Sort by the ending time
    sort(meetingList.begin(), meetingList.end(), compMeeting);
    // printMeeting(meetingList);

    cout << getMaxMeeting(meetingList);
    
}