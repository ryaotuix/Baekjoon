#include <bits/stdc++.h>


using namespace std;

struct fruit {
    int org;
    int cut = 1;

    // this is comparing the fruits (ex. curr weight = org/cut)
    // org1/cut1 < org2/cut2 ====> org1*cut2 < org2*cut1
    bool operator< (fruit& other) {return org*other.cut < other.org*cut;}
    bool operator== (fruit& other) {return (org==other.org) && (cut==other.cut);}
};


void print(auto * arr, int n)
{
    for (int i = 1; i <=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    string r; cin >> r;
    int ratio = stoi(r.substr(2));
    cout << ratio;
    int n; cin >> n;
    return 1;
    fruit fruits[n+1];

    // store weight information
    for (int i = 0; i <n; i++)
    {   
        cin >> fruits[i+1].org;
    }
    
    

    int res = 0;
    fruit ultmax;
    fruit ultmin;

    while (true)
    {
        ultmax = *max_element(fruits+1, fruits+n+1); // max fruit
        ultmin = *min_element(fruits+1, fruits+n+1); // min fruit
        int max = ultmax.org;
        int min = ultmin.org;
        //if (max * ratio  <= min) break;

        for (int i =1; i<= n; i++)
        {
            if (fruits[i] == ultmax) 
            {
                fruits[i].cut = fruits[i].cut + 1;
                res++;
            }
        }

        cout << max << " " << min << "\n";
        cout << "===================================\n"; 
    }
    cout << res << endl;
    
    
}