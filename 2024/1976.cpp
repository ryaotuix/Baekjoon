#include <bits/stdc++.h>

using namespace std;

const int MAX = 200 + 1;
int adjMatrix[MAX][MAX];

int parent[MAX];

int N, M;

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

    if (a > b)
        swap(a, b);
    
    // b 의 부모가 a랑 같게함
    parent[b] = a;
}

void input()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j] == 1)
            {
                _union(i, j);
            }
        }
    }


    int root;
	for(int i=0; i<M; i++){
		int x;
		cin >> x;
		if(i == 0) root = find(x);
		else{
			if(find(root) != find(x)){
				cout << "NO";
				return;
			}
		}
	}
	cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}