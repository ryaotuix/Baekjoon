#include <bits/stdc++.h>

using namespace std;

int getIndex(stack<int> & st, int curr, vector<int> & temperatures, vector<int> & ans)
{
    int dist = 0;

    // until st is empty or temp [st.top] > temp [curr]
    while (!st.empty() && temperatures[st.top()] <= temperatures[curr])
    {
        dist += ans[st.top()];                     // add top counts
        st.pop();
    }

    st.push(curr);

    // didn't find the bigger element -> curr is the only one in stack -> return 0
    if (st.size() == 1)
        return 0;
    else
        return dist + 1;
}


// vector<int> dailyTemperatures(vector<int> & temperatures)
// {
//     int len = temperatures.size();
//     vector<int> res (len);

//     // last one is 0, and put it into stack
//     stack<int> st;
//     res[len-1] = 0;
//     st.push(len - 1);

//     // iterater from the second last
//     for (int i = len - 2; i >= 0; i--)
//     {
//         int dist = getIndex(st, i, temperatures, res);
//         res[i] = dist;
//     }

//     for (int a : res)
//         cout << a << " ";
//     cout << endl;

//     return res;
// }

vector<int> dailyTemperatures(vector<int> & temperatures)
{
    int n = temperatures.size();
    vector<int> nge (n, 0);                     // next greater element 
    stack<int> st;                              // store index

    for (int i = n -1; i >= 0; i--)
    {
        // pop until we found the next greater element 
        while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();

        // if there is a greate element, dist = that - i        
        if (!st.empty())
            nge[i] = st.top() - i;  

        st.push(i);
    }

    for (auto i : nge)
        cout << i << " ";
    cout << endl;
    
    return nge;
}

int main()
{
    vector<int> arr = {30,40,50,60};
    vector<int> res = dailyTemperatures(arr);
}