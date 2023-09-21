#include <bits/stdc++.h>

using namespace std;

typedef struct bus
{
    int x1, y1;
    int x2, y2;
    bool isVertical;
}bus;

bool isOverlap(bus & a, bus & b)
{
    // When a and b have same direction
    if (a.isVertical == b.isVertical)
    {
        // a is vertical and two xs are the same
        if (a.isVertical == true && a.x1 == b.x1)
        {
            if (a.y2 < b.y1 || b.y2 < a.y1)
                return false;
            else
                return true;
        }
    }
    // if case 2
    if (a.isVertical == false && a.y1 == b.y1)
    {

    }
}

void input()
{
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}