#include <bits/stdc++.h>

using namespace std;

typedef struct box
{
    int num;
    int from;
    int to;
};

bool compByTo(box & a, box & b)
{
    // if (a.to == b.to)
    //     return a.from < b.from;
    // sort in ascending order
    return a.to < b.to;
}

int available[2000 + 10];       // truck availability for each town {default : 0}
int ans = 0;
int N;                          // # of town
int C;                          // Capacity of a truck

void printBox(vector<box> & boxes)
{
    for (box i : boxes)
        cout << i.from << " " << i.to << " " << i.num << "// ";
    cout << endl;
}
int main()
{
    // INPUT 
    vector<box> boxes;
    cin >> N >> C;
    int nBox; cin >> nBox;
    for (int i = 0; i < nBox; i++)
    {
        box temp;
        int from, to, num;
        cin >> from >> to >> num;
        temp.from = from;
        temp.to = to;
        temp.num = num;
        boxes.push_back(temp);
    }

    // sort by Town To
    sort(boxes.begin(), boxes.end(), compByTo);
    // printBox(boxes);


    
    for (box curr : boxes)
    {
        int from = curr.from;
        int to = curr.to;
        int num = curr.num;

        // get the maximum (60 - availability) [start, end) ** start inclusive, end exclusive
        int maxi = 0;
        for (int i = from; i < to; i++)
        {
            maxi = max(maxi, available[i]);
        }

        maxi = min(num, C - maxi);
        // cout << "max ; " << maxi << endl;

        // add up that amount back
        for (int i = from; i < to; i++)
        {
            available[i] += maxi;
        }

        ans += maxi;
    }
    
    cout << ans;
}