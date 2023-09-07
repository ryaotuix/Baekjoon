#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> location;     // location x and y
const int MAX = 5000 + 5;            // MAX Bus number

typedef struct Bus
{
    location begin;
    location finish;
    bool bIsVertical;       
}Bus;

Bus buses[MAX];                 // store all buses 
bool visited[MAX];              // visited 
int M, N;
int K;

location start;                 // start
location dest;                  // dest

bool CanDestination(Bus & bus)
{
    // bus is vertical
    if (bus.bIsVertical)
    {
        // check if destination's x is the same
        if (dest.first != bus.begin.first) return false;

        // check if destination's y is within the range of Bus
        if (dest.second <= bus.finish.second && dest.second >= bus.begin.second) return true;
        else return false;
    }
    // bus is horizontal
    else
    {
        // check if destination's y is same 
        if (dest.second != bus.begin.second) return false;

        // check if destination's x is within the range of Bus
        if (dest.first <= bus.finish.first && dest.first >= bus.begin.first) return true;
        else return false;
    }

    return true;
}



void Input()
{
    cin >> M >> N;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int bus_num, sx, sy, dx, dy; 
        cin >> bus_num >> sx >> sy >> dx >> dy;
        
        bool isVertical = (sx == dx) ? true : false;    // if x is the same, it is vertical 
        Bus bus = {{sx, sy}, {dx, dy}, isVertical};
        buses[bus_num] = bus;
    }

    cin >> start.first >> start.second >> dest.first >> dest.second;
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    
}