#include <bits/stdc++.h>

using namespace std;


void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printV(vector<int> & v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

void selectionSort (vector<int> & v)
{
    
    for (int i = 0; i < v.size(); i++)
    {
        int minimum = 1e6;
        int minInd;

        for (int j = i; j < v.size(); j++)
        {
            if (v[j] <= minimum)
            {
                minimum = v[j];
                minInd = j;
            }
        }
        // cout << i << " " << minInd << endl;
        swap(v[i], v[minInd]);

        // cout << i << " : ";
        // printV(v);
    }
}

vector<int> input()
{
    int n;
    cin >> n;
    vector<int> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    return v;
}

int main()
{
    vector<int> v = input();
    selectionSort(v);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}