// #include <bits/stdc++.h>

// using namespace std;

// unordered_map<int, int> um;

// int N, M;


// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> N;
//     for (int i = 0; i < N; i++)
//     {
//         int temp; cin >> temp;
//         um[temp]++;
//     }

//     cin >> M;
//     for (int i = 0 ; i < M; i++)
//     {
//         int temp; cin >> temp;
//         if (um[temp])
//         {
//             cout << 1;
//         }
//         else
//         {
//             cout << 0;
//         }

//         cout << "\n";
//     }
// }



#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int N, M;

bool binarySearch(int target)
{
    int low = 0;
    int high = N-1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) return true;

        if (arr[mid] > target) 
            high = mid - 1;
        else
        {
            low = mid + 1;
        }
    }

    return false;
}   

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp; 
        cin >> temp;
        if (binarySearch(temp))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }

        cout << "\n";
    }

}