#include <bits/stdc++.h>
#include <string>

using namespace std;

#define MAX 100001
int track = 1;

class UF{
    public:
        int root[MAX];
        int size[MAX];                  // size of each index
        unordered_map<string, int> nameToInd;     // Name (string) as integer

        UF(int n)
        {
            for(int i=0; i<n; i++) {
                size[i]=1;
                root[i]=i;
            }
        }

        // int nToInd (string name)
        // {
        //     // if not exist
        //     if (nameToInd.find(name) == nameToInd.end())
        //     {
        //         nameToInd.insert((name, track++));
        //     }
            
        //     return nameToInd.find(name);
        // }

        // recursively find the root value
        int find(int ind)
        {
            if (root[ind] != ind)
            {
                root[ind] = find(root[ind]);
            }
            return root[ind];
        }

        void merge(int a, int b)
        {
            int rootA = find(a);
            int rootB = find(b);

            // if they have the same root
            if (rootA == rootB)
                return;
            
            // if root A is bigger than B,
            if (size[rootA] > size[rootB])
            {
                // make the root value of set B as rootA
                root[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            else
            {
                root[rootA] = rootB;
                size[rootB] += size[rootA];
            }
        }

};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        UF uf(MAX);
        int n;
        cin >> n;
        unordered_map<string, int> nameToInd;

        string name1, name2;
        for (int i = 0; i <n; ++i)
        {
            cin >> name1 >> name2;

            if (nameToInd.count(name1) == 0)    // if name doesn't exist
                nameToInd[name1] = nameToInd.size();    // assign Fred - 0
            if (nameToInd.count(name2) == 0)
                nameToInd[name2] = nameToInd.size();

            uf.merge(nameToInd[name1], nameToInd[name2]);

            cout << uf.size[uf.find(nameToInd[name1])] << endl;
        }
        
    }
}