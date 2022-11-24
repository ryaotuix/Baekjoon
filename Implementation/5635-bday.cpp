#include <iostream>
#include <vector>

using namespace std;

typedef struct Person {
    public:
        int year;
        int month;
        int day;
        string name;
}Person;



void swap(Person & a, Person & b)
{
    Person temp = a;
    a = b;
    b = temp;
}

void printPeople(Person * people, int size);

void sortByBirthday(Person * people, int size)
{
    int i, j;
    for (i=0; i<size-1; i++)
    {
        for (j=0; j<size-i-1; j++)
        {
            if (people[j].year > people[j+1].year)
            {
                swap(people[j], people[j+1]);
                continue;
            }
            if ((people[j].year == people[j+1].year) && (people[j].month > people[j+1].month))
            {
                swap(people[j], people[j+1]);
                continue;
            }
            if ((people[j].year == people[j+1].year) && (people[j].month == people[j+1].month) && (people[j].day > people[j+1].day))
            {
                swap(people[j], people[j+1]);
            }
            // printPeople(people,size);
            // cout << "\n\n";
        }
    }
}

void printPeople(Person * people, int size)
{
    for (int i=0; i<size; i++)
    {
        cout << "Name : " << people[i].name << endl;
        cout << "Birtyday : " << people[i].year << "/" << people[i].month << "/" << people[i].day << endl;
        cout << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    Person people[n];

    for (int i = 0; i < n; ++i)
    {
        string name;
        int day, month, year;
        cin >> name >> day >> month >> year;
        Person p {year, month, day, name};
        people[i] = p;
    }    
    sortByBirthday(people, n);
    //printPeople(people,n);

    cout << people[n-1].name << endl;
    cout << people[0].name << endl;
    return 0;
}