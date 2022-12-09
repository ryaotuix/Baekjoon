#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>v)
{
    if (v.empty()) {
        cout << "vecor is empty\n";
        return;
    }

    for (int i = 0; i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int col, row; 
    cin >> col >> row;

    string arr[col+1];

    for (int i = 1; i<= col; i++)
        cin >> arr[i];
    
    int start, end; cin >> start >> end;
    // UNTIL HERE INPUT ///////////////////////////////


    int res = 0;

    vector<int> indexes;

    // loop each lines
    for (int i = start; i < end; i++)
    {
        string str = arr[i];
        //cout << "line number " << i << endl;
        //cout << str << endl;
       

        // if vector is empty, 
        if (indexes.empty())
        {
            // fill it with index that has 'O'
            for (int j = 0; j< str.length(); j++)
            {
                if (str[j] == 'O') indexes.push_back(j);
            }

            //if still empty
            if (indexes.empty())
            {
                cout << -1;
                return 0;
            }
        }
        else // if vector already has indexes of 'O's
        {
            for (int j = 0; j < indexes.size(); j++)
            {
                int index_to_check = indexes[j];
                if (index_to_check == -1) continue;

                // if next index of 'O' is not 'O'
                if (str[index_to_check] != 'O')
                {
                    // replace it to -1
                    indexes[j] = -1;
                }
            }


            // if the vector is all '-1', clear
            bool toClear = true;
            for (int j = 0; j < indexes.size(); j++)
            {
                if (indexes[j] != -1) {
                    toClear = false;
                    break;
                }
            }
            if (toClear) indexes.clear();


            // if not continuous,
            if (indexes.empty())
            {
                res++; // we must change room

                // and refill the index of 'O'
                for (int k = 0; k < str.length(); k++)
                {
                    if (str[k] == 'O')  indexes.push_back(k);
                }
                // if this line doesn't have room
                if (indexes.empty())
                {
                    cout << -1;
                    return 0;
                }
            }
        }
        //printVector(indexes);

    }
    cout << res;
    return 0;
}

