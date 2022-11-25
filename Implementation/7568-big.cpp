#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

typedef pair<int,int> pii; // <weight, height>

void printArray(int * grades, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << grades[i] << endl;
    }
}

bool compare(pii a, pii b)
{
    if (a.first < b.first && a.second < b.second)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    pii people[n]; // make an array of people with input size
    int grades[n]; // way to initialize grades to all 0
    fill_n(grades, n, 1);

    //memset(grades, 1, sizeof(grades));
    //printArray(grades,n);

    // put it in array
    for (int i = 0; i < n; i++)
    {
        int weight, height;
        cin >> weight >> height;
        pii person (weight, height); // the way to initialize the code
        people[i] = person;
    }

    // increment grades
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (compare(people[i], people[j]))
                grades[i]++;
        }
    }

    for (int i = 0; i< n; i++)
        cout << grades[i] << " ";


    return 0;
}

