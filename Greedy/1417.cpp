#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int candidates; cin >> candidates;
    int me; cin >> me;

    if (candidates == 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> votes;
    for (int i = 0; i < candidates - 1; i++)
    {
        int thisvote; cin >> thisvote;
        votes.push_back(thisvote);
    }
    sort(votes.begin(), votes.end(), greater<int>());

    for (int i = 0; i < votes.size(); i++)
        cout << votes[i] << " ";
    cout << endl; 


}