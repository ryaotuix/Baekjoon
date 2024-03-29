#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;

vector<pair<int, int> > graph[100001]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[100001]; // 최단 거리 테이블 만들기

void dijkstra(int start)
{
    priority_queue<pair<int,int>>pq; //  노드 인덱스, 거리
    
    pq.push({0,start}); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
    d[start]=0;
    
    while(!pq.empty())
    {
        int dist = -pq.top().first; //현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();
        
        cout << "curr node : " << now << " distance : " << dist << "\n";
        
        if(d[now]<dist) // 이미 최단경로를 체크한 노드인 경우 패스
        {
            cout << "최단경로 체크됨\n";
           continue;
        }

        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = dist+graph[now][i].second; // 거쳐서 가는 노드의 비용을 계산
            cout << "node " << graph[now][i].first << " has the current cost of " << d[graph[now][i].first] << "\n";
            cout << "node " << graph[now][i].first << " has the potential cost of " << cost << "\n";

                                                  // 현재노드까지 비용 + 다음 노드 비용
            if(cost<d[graph[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[graph[now][i].first]=cost;
                cout << "node " << graph[now][i].first << " has the updated cost of " << d[graph[now][i].first] << "\n";
                pq.push(make_pair(-cost,graph[now][i].first));
            }
        }
        cout << endl;
    }
}

int main()
{
    n = 4;
    m = 5;
    start = 0;

    for (int i = 0 ; i < n ; i++)
    {
        d[i] = INF;
    }
    d[start] = 0;

    graph[0].push_back({1, 6});
    graph[0].push_back({2, 4});
    graph[0].push_back({3, 2});
    graph[1].push_back({2, -8});
    graph[2].push_back({3, 3});
    dijkstra(start);

    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 0; i < n; i++)
    {
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << d[i] << '\n';
        }
    }
}