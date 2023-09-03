#include <bits/stdc++.h>

using namespace std;

typedef struct station
{
    string s;
    int bus;
}station;

string start, destination;
unordered_map<string, bool> visited;
queue<station> Q;

bool isPrime(string s)
{
    int num = stoi(s);
    for (int i = 2; i <= sqrt(num) + 1; i++)
    {
        // if num is divisible by something -> not prime
        if (num % i == 0)   return false;
    }

    return true;
}


void input()
{
    cin >> start >> destination;
}

void bfs()
{
    // mark start visited
    visited[start] = true;  // start is visited
    Q.push({start, 0});     // push start into queue

    while(!Q.empty())
    {
        string curr = Q.front().s;
        int bus = Q.front().bus;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 && j == 0) continue;     // first digit can't be 0

                // next station with one different character
                string next = curr;
                next[i] = j + '0';

                // if next is destination, end
                if (next == destination)
                {
                    cout << bus + 1;
                    return;
                }

                // if not prime, continue
                if (!isPrime(next)) continue;

                // if prime, and not visited
                if (!visited[next])
                {
                    visited[next] = true;
                    Q.push({next, bus + 1});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs();
}