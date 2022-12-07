#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_group; cin >> num_group;

    for (int i = 0; i < num_group; i++)
    {
        int num_gnomes; cin >> num_gnomes;
        vector<int> gnomes;

        int kingpos;
        for (int j = 0; j < num_gnomes; j++)
        {
            int id; cin >> id;
            gnomes.push_back(id);
            
            int len = gnomes.size();

            // if last index of gnome we just put is not before +1 
            if (j>1 && gnomes[len-1] != gnomes[len-2]+1)
            {
                kingpos = len-1;
            }
        }

        cout << kingpos << "\n";

        // Printing gnomes
        // cout << "gnomes are :";
        // for (int j = 0; j < gnomes.size(); j++)
        // {
        //     cout << gnomes[j] << " ";
        // }
        // cout << "\n\n";



        // for (int j = 0; j <gnomes.size() - 1; j++)
        // {
        //     if (gnomes[j+1] !=  gnomes[j] + 1)
        //     {
        //         // cout << j << j+1 << "\n";
        //         //cout << "gnome j is " << gnomes[j] << " gnome j+1 is " << gnomes[j+1] << "\n";
        //         cout << j+2 << "\n";
        //         break;
        //     }
        // }
    }

    return 0;
}
