#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


char arr[101][31];
int rooms, days;
int start, leave;

int greedy(int ind)
{
    int max = 0;
    // Loops through rooms (rows first ->->->)
    for (int i = 1; i <= rooms; i++)
    {
        //cout << " This col is" << i <<"\n";
        int continuousDay = 0;
        // Loops through days (column vvvv)
        for (int j = ind; j <= leave; j++)
        {
            //cout << arr[j][i] << endl;;
            if (arr[j][i] == 'O') continuousDay++;
            else {
                //cout << max << " " <<  continuousDay << endl;
                break;
            }
        }
        //cout <<"\n";
        if (max < continuousDay) max = continuousDay;
    }
    return max;
}

int main()
{
    // INPUT RECEIVING
    // scanf("%d%d", &days, &rooms);
    cin >> days >> rooms;
	
	for (int i = 1; i <= days; i++)
    {
        for (int j = 1; j <= rooms; j++)
        {
            cin >> arr[i][j];
        }
    }
	
	// scanf("%d%d", &start, &leave);
    cin >> start >> leave;
	
    // // PRINT ARRAY
   	// for (int i = 1; i <= days; i++)
    // {
    //     for (int j = 1; j <= rooms; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
	// INPUT END

    int res = -1;
    for (int i = start; i<leave;) // exclud 'leave'
    {
        res++;
        // if can't book
        int contDays = greedy(i); 
        //cout << "total is : " << res << endl;
        if(contDays == 0)
        {
            res = -1;
            break;
        }

        // greedy function returns the day
        i += contDays;
    }

    cout << res;

}



/*
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

void leaveContinuousIndex (string str, vector<int> &indexes)
{   
    // iterate through vector (that has index values)
    for (int i = 0; i < indexes.size(); i++)
    {
        int ind = indexes[i];
        if (ind == -1) continue; // if index is -1 (out of range) continue

        // if next string[index] is not 'O', change that index to -1 (out of range)
        if (str[ind] != 'O') indexes[i] = -1;
    }
}

void clearIfNeeded (vector<int> &indexes)
{
    bool toClear = true;
    for (int j = 0; j < indexes.size(); j++)
    {
        if (indexes[j] != -1) {
            toClear = false;
            break;
            }
        }
    if (toClear) indexes.clear();
}

void terminateIfNeeded (vector<int> indexes)
{
    if (indexes.empty())
    {
        cout << -1;
        exit(0);
    }
}


void addIndex (vector<int> &indexes, string str)
{
    for (int i = 0; i < str.length(); i++)
    {
       if (str[i] == 'O') indexes.push_back(i);
    }
}

int main()
{
    int col, row; 
    cin >> col >> row;

    string arr[col+1];

    for (int i = 1; i<= col; i++)
        cin >> arr[i];
    
    int start, end; cin >> start >> end;
    ///////////////////////////// UNTIL HERE INPUT ///////////////////////////////

    int res = 0;

    vector<int> indexes;

    // loop each lines
    for (int i = start; i < end; i++)
    {
        string str = arr[i];

        // if vector is empty, 
        if (indexes.empty())
        {
            // fill it with index that has 'O'
            addIndex(indexes, str);

            // if No room (if vector is empty after trying to fill with index)
            terminateIfNeeded(indexes);
        }
                
        else // if vector already has indexes of 'O's
        {
            // change all non-continuous indexes to -1
            leaveContinuousIndex(str, indexes);

            // if the vector is all '-1', clear
            clearIfNeeded(indexes);

            // if not continuous,
            if (indexes.empty())
            {
                res++; // we must change room

                // and refill the index of 'O'
                addIndex(indexes, str);

                // if No room (if vector is empty after trying to fill with index)
                terminateIfNeeded(indexes);
            }
        }
        //printVector(indexes);

    }
    cout << res;
    return 0;
}
*/
