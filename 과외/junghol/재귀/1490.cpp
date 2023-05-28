/*
문자열로 모든 경우의 수 저장
vector<vector<int>> res;
1. 전역변수로 빈 vector<int> temp ""

재귀를 돌면서
rec (int x)
{
    1. temp 의 길이 == k
        temp 를 res 에 저장
        temp 
    
    2. 재귀 스텝
        for (1~n)
        1. used[i] 안썼다면
        {
            temp[x] = i
            used[i] = true  썼다
            rec (x + 1) 재귀 돌기
            used[i] = false 안썼다
        }
}
*/

/*
#include <bits/stdc++.h>

using namespace std;

int n, k;   // n : possible numbers   k: size of set
vector<int> temp; // stores possible comb
vector<vector<int>> res;  // stores all res
bool used [10 + 5]; //flag array


void rec(int x)
{
    // store it to result
    if (x == k)
    {
        res.push_back(temp);
        return;
    }

    int start = (x == 0) ? 1 : temp[x-1];

    for (int i = start; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            temp[x] = i;
            
            rec(x + 1);
            used[i] = false;
        }
    }
}

void printRes()
{
    for (auto v : res)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

bool compVec(vector<int> & a, vector<int> & b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

int main()
{
    cin >> n >> k;
    temp.resize(k); // 사이즈 분배
    temp[0] = 1;

    rec(0);
    // printRes();

    vector<int> toComp;
    for (int i = 0; i < k; i++)
    {
        int temp; cin >> temp;
        toComp.push_back(temp);
    }

    int cnt = 0;
    for (vector<int> v : res)
    {
        if (compVec(toComp, v) == false)
        {
            cnt++;
        }
        else
            break;
    }

    // cnt represents index
    if (cnt == res.size() - 1)
        cout << "NONE";
    else
    {
        for (int i : res[cnt+1])
            cout << i << " ";
    }
}
*/

