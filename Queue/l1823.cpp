#include <bits/stdc++.h>

using namespace std;

typedef struct person {
    int num = 0;
    person *next = NULL;
    person *prev = NULL;
}person;

void printFriend(person *v)
{
    cout << "{\n";
    cout << "NUM : " << v->num << endl;
    cout << "NEXT : " << v->next->num << endl;
    cout << "PREV : " << v->prev->num << endl;
    cout << "}\n\n";
}

int findTheWinner(int n, int k)
{
    // Create a DLL
    person *start = new person();
    start->num = 1;

    person *temp = start;
    for (int i = 2; i <= n; i++)
    {
        person *f = new person();
        f->num = i;

        f->prev = temp;
        temp->next = f;
        temp = f;
    }

    temp->next = start;
    start->prev = temp;


    // Get read if it
    temp = start;
    while(temp -> next != temp)
    {
        // go to k - 1 steps
        for (int i = 0; i < k-1; i++)
            temp = temp -> next;
        
        // temp is to be removed
        person * previous = temp -> prev;
        person * nextP = temp -> next;

        // change links
        previous->next = nextP;
        nextP -> prev = previous;
        free(temp);
        temp = nextP;
    }

    
    return temp->num;
}


int main()
{
    int n = 5;
    int k = 2;
    int res = findTheWinner(n, k);
    cout << res;
}