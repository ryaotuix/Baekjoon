#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Materials
int arr [100 + 5];              // arr to store 2nd row
int visited [100 + 5];          // stores # of times visited
int n;                          // set n as global variable


void init()
{
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
}

void rec(int ind, vector<int> & v)
{
    // Base case
    if (visited[ind] == 2)                  // when find infinite loop (visit twice)
    {
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 2)
                v.push_back(i);           // into the vector v, add first row (i) value
        }
        return;
    }

    // Otherwise
    visited[ind]++;                         // increment visit count
    rec(arr[ind], v);                       // recursion happens
}


int main()
{
    vector<int> v;               // store the indices that are visited twice (will have overlap) 
    vector<int> answers;         // store the ultimate answers
    int i;

    cin >> n;

    for (i = 1; i <= n; i++)  // fill the array 
        cin >> arr[i];
    
    for (i = 1; i <= n; i++)
    {
        init();
        rec(i, v);
    }

    // // print and check
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << " ";

    // HERE, there are overlaps. 
    // Two ways to handle it
    /*
        1) bool used array of size n
        2) sort and use temp variable to see 
        Let's do 2.
    */

    sort(v.begin(), v.end());       // sort v by ascending order
    
    // push first value of v into answers
    int temp = v[0];
    answers.push_back(temp);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == temp)           // if repeated value,
            continue;
        
        temp = v[i];
        answers.push_back(temp);
    }

    cout << answers.size() << "\n";
    for (i = 0; i < answers.size(); i++)
        cout << answers[i] << "\n";
}