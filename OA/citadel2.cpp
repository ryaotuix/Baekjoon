#include <bits/stdc++.h>

using namespace std;



void printADJ(vector<vector<int>> & adjList)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << "User " << i << ": {";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << ", ";
        }
        cout << "}\n";
    }
    cout << "===========================================\n";
}

// make adj list
vector<vector<int>> makeAdjList (vector<vector<int>> & v, int n)
{
    // init adj List with size n. n : # of user
    vector<vector<int>> adjList (n);

    for (vector<int> relationship : v)
    {
        adjList[relationship[0]].push_back(relationship[1]);
        adjList[relationship[1]].push_back(relationship[0]);
    }

    return adjList;
}


vector<vector<bool>> makeAdjMatrix(vector<vector<int>> & v, int n)
{
    // init adj Matrix with size n, n 
    vector<vector<bool>> adjMatrix (n, vector<bool>(n, false));

    for (vector<int> relationship : v)
    {
        adjMatrix[relationship[0]][relationship[1]] = true;
        adjMatrix[relationship[1]][relationship[0]] = true;
    }

    return adjMatrix;
}


void printAdjMatrix(vector<vector<bool>> & adjMatrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "User " << i << ": ";
        for (int j = 0; j < adjMatrix[i].size(); j++)
        {
            if (adjMatrix[i][j])
                cout << "friend, ";
            else
                cout << "not friend, ";
        }
        cout << endl;
    }
    cout << "====================\n";
}

// get friend recommendation
vector<int> recFriend(vector<vector<int>> & relationship, int n)
{
    // make adj list, adj Matrix
    vector<vector<int>> adjList = makeAdjList(relationship, n);
    vector<vector<bool>> adjMatrix = makeAdjMatrix(relationship, n);

    // rec init with -1
    vector<int> ans (n, -1);    

    // iterate over each user
    for (int user = 0; user < n; user++)
    {
        // init CNT for this user's FOF cnt
        vector<int> cnt (n, 0);

        // variables to store user's recommendation
        int rec = n+1;
        int maxCnt = 0;
        bool found = false;


        // i. go to each user's direct friend
        for (int dirFriend : adjList[user])
        {
            // go to friend's friend FOF
            for (int fof : adjList[dirFriend])
            {
                cout << "user : " << user << " fof : " << fof << endl;
                // skip user
                if (fof == user)
                    continue;
                
                // Check if fof and user is friend          don't recommend this person
                if (adjMatrix[fof][user])
                {
                    continue;
                }

                // increment friend's friend cnt
                cnt[fof]++;
                if (cnt[fof] >= maxCnt)
                {
                    found = true;
                    maxCnt = cnt[fof];
                    rec = min(rec, fof);            // if they have to same cnt, choose the minimum # user
                    cout << " we will recommend " << rec << " for user " << user << endl;
                }
            }
            // break 1 comes here
        }

        ans[user] = (found) ? rec : -1;
        cout << "user " << user << " was recommended with " << ans[user] << endl;
    }

    return ans;
}


int main()
{
    int n = 6;
    vector<vector<int>> relationship = {{0,1}, {0,5}, {0,3}, {1,2}, {2,3}, {3,4}, {1,5}};
    
    vector<vector<int>> adjList = makeAdjList(relationship, n);    
    printADJ(adjList);
    vector<vector<bool>> adjMatrix = makeAdjMatrix(relationship, n);
    printAdjMatrix(adjMatrix, n);


    vector<int> res = recFriend(relationship, n);
    cout << "{";
    for (int n : res)
        cout << n << ", ";
    cout << "}\n";
}