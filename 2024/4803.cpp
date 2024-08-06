#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX = 500 + 1;
int parent[MAX];
bool isParent[MAX];
bool isCycle[MAX];

/*
    로직 : 모든 union 연결,
        : union 하면서 isParent, parent 업데이트
        : cycle 발생시 그 union 의 parent의 isCycle 마크
        마지막에 모든 노드를 돌면서 (parent 이면서 cycle 이 아닌 경우에만 트리 갯수 추가)
*/

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        parent[i] = 0;
        isParent[i] = false;
        isCycle[i] = false;
    }
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

void _union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
    {
        isCycle[a] = true;
    }

    if (a > b)
    {
        swap(a, b);
    }

    isParent[b] = false;
    parent[b] = a;

    // must update Cycle
    isCycle[a] = isCycle[b];
}

void print(int treeCnt)
{
    if (treeCnt == 0)
        cout << "No trees.";
    else if (treeCnt == 1)
        cout << "There is one tree.";
    else    
        cout << "A forest of " << treeCnt << " trees.";
    
    cout << "\n";
}

void input()
{
    cin >> n >> m;
    int tCase = 1;
    // finish when both n and m are 0
    while(n != 0 || m != 0)
    {
        /*  logic : 
            1. make parent of a nodes as itself
            2. mark is parent
            3. remove isParent while making unions
        */
        init();
        int a, b;

        // 1 and 2
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            isParent[i] = true;
        }

        // 3
        while(m--)
        {
            cin >> a >> b;
            _union(a, b);
        }

        /*
            logic :
            4. iterate each node, see if they are parent, if not parent (for each parent, treeCnt is ++)
        */

        // 4
        int treeCnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isParent[i] && !isCycle[i])
            {
                treeCnt++;
            }
        }

        cout << "Case " << tCase++ << ": ";
        print(treeCnt);

        cin >> n >> m;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}