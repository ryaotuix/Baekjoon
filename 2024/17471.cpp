#include <bits/stdc++.h>

using namespace std;
const int MAX = 10 + 1;
typedef pair<int, int> area; // num, population

/*
    max num city is 10
    bfs and dfs will cost O(nm) which means 90
*/

int numCities;                                      // city 개수
vector<int> population(MAX);                        // city population
vector<int> adjList[MAX]; // adj List 로 표현
int totalPop;                                       // 총 인구수
int answer;                                         // 최종적으로 구해야될 선거구 인구수 차이
vector<bool> visited(MAX);                          // visited array
vector<bool> group(MAX);                            // group into two 

// void printADJ()
// {
//     for (int i = 1; i < MAX; i++)
//     {
//         for (auto c : adjList[i])
//             cout << c << " ";
//         cout << "\n";
//     }
// }

void init()
{
    // get number of cities
    cin >> numCities;

    // for each cities,
    for (int i = 1; i <= numCities; i++)
    {
        cin >> population[i];            // get population
        totalPop += population[i]; // add up to total population
    }

    // init answer to totalPop
    answer = totalPop;

    // for each city,
    for (int currCity = 1; currCity <= numCities; currCity++)
    {
        int num;
        cin >> num;
        // get adj cities
        while (num--)
        {
            int nextCity;
            cin >> nextCity;
            adjList[currCity].push_back(nextCity);
            adjList[nextCity].push_back(currCity);
        }
    }
}


// check if it is in same group 
bool isConnected(vector<int> &v, bool flag){
    
    for (int i = 0; i < MAX; i++)   visited[i] = false;
    queue<int> q;
    visited[v[0]] = true;
    q.push(v[0]);
    int cnt = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for (auto value: adjList[x]){ 

            // 같은 그룹이아니거나 이미 방문했으면 그냥 넘어가기
            if (group[value] != flag || visited[value]) continue;
            cnt++;
            visited[value] = true;	// 이미 갔던 노드는 못가도록 check표시
            q.push(value);
        }
    }

    if (v.size() == cnt) return true; // 탐색한 노드 개수랑, 구역의 노드 개수가 같다면 모두다 연결되어있다는 의미
    else return false;
}


// 힌트보고 얻음
bool isOK()
{
    // make it into two group
    vector<int> group1;
    vector<int> group2;


    // push cities into each group
    for (int i = 1; i <= numCities; i++)
    {   
        // if it is marked as true, go to group 1
        if (group[i])   group1.push_back(i);
        else            group2.push_back(i);
    }


    // need at least 1 city in each group
    if (group1.empty() || group2.empty()) return false;

    // if each group is not connected, is is false
    if (!isConnected(group1, true)) return false;
    if (!isConnected(group2, false)) return false;

    // cout << "gropu 1 has : ";
    // for (auto c : group1)
    // {
    //     cout << c << " ";
    // }

    // cout << "\ngroup 2 has : ";
    // for (auto c : group2)
    // {
    //     cout << c << " ";
    // } 
    // cout << "\n";
    return true;

}


void calcAns()
{
    int pop1 = 0;
    int pop2 = 0;

    for (int i = 1; i <= numCities; i++)
    {
        // if it is in group1
        if (group[i])   pop1 += population[i];
        else            pop2 += population[i];
    }

    // cout << "pop1 : " << pop1 << " pop2 : " << pop2 << "\n";
    answer = min(answer, abs(pop1 - pop2));
}

// dfs to brute force everry possibility of group
void dfs (int start, int depth)
{
    // check every time 
    if (depth >= 1)
    {
        if (isOK())
        {
            calcAns();
        }
    }

    for (int i = start; i <= numCities; i++)
    {
        if (group[start])   continue;
        group[i] = true;
        dfs(i + 1, depth + 1);
        group[i] = false;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    // printADJ();
    dfs(1, 0);
    if (answer == totalPop) 
    {
        cout << -1;
        return 0;
    }
    cout << answer;
}