#include <bits/stdc++.h>

using namespace std;

int num;
int totalCows;
int numCows;

vector<int> arr;    // 외양간 위치
vector<int> dist;   // distance vector

int totalDist;
int minimum = 20000;
int maximum = -1;

int input()
{
    cin >> num >> totalCows >> numCows;

    for (int i = 0; i < numCows; i++)
    {
        int cow; cin >> cow;

        // update minimum and maximum
        if (cow < minimum)
            minimum = cow;
        if (cow > maximum)
            maximum = cow;

        arr.push_back(cow);
    }

    // sort arr in ascending order
    sort(arr.begin(), arr.end());

    // total distance is inclusive
    totalDist = maximum - minimum + 1;


    // Fill out distances
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int prev = arr[i];
        int next = arr[i+1];
        int currDist = next - prev - 1;
        dist.push_back(currDist);
    }

    // sort distance array in descending order
    sort(dist.begin(), dist.end(), greater<int>());

    int missingDist = 0;

    for (int i = 0; i < num-1; i++)
    {
        missingDist += dist[i];
    }

    return totalDist - missingDist;
}


int main()
{
    cout << input();
}