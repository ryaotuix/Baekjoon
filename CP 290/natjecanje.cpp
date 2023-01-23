#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, S, R;
    cin >> N >> S >> R;

    bool extras[N+1] = {0}; // set all of them as false

    // save damaged team in vector
    vector<int> damagedTeams;
    for (int i = 0; i < S; i++)
    {
        int team; 
        cin >> team;
        damagedTeams.push_back(team);
    }

    // set as True if the team has extra kayak
    for (int i = 0; i < R; i++)
    {
        int teamwReserved;
        cin >> teamwReserved;
        extras[teamwReserved] = true;
    }

    while(!damagedTeams.empty())
    {
        int teamToCheck = damagedTeams.back();
        damagedTeams.pop_back();
    }

}