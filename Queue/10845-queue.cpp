// #include <iostream>
// #include <queue>
// #include <string>

// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int n; cin >> n;

//     queue<int> q;
//     int num;

//     for (int i = 0; i < n; i++)
//     {
//         string str; cin >> str;

//         if (str == "push")
//         {
//             int topush; cin >> topush;
//             q.push(topush);
//         }
//         else if (str == "pop")
//         {   
//             // if q is empty
//             if (q.empty()) {
//                 num = -1;
//             } else {
//                 num = q.front();
//                 q.pop();
//             }
//             cout << num << endl;
//         }
//         else if (str == "size")
//         {
//             cout << q.size() << endl;
//         }
//         else if (str == "empty")
//         {
//             if (q.empty()) num = 1;
//             else num = 0;
//             cout << num << endl;
//         }
//         else if (str == "front")
//         {
//             if (q.empty()) num = -1;
//             else num = q.front();
//             cout << num << endl;
//         }
//         else if (str == "back")
//         {
//             if (q.empty()) num = -1;
//             else num = q.back();
//             cout << num << endl;
//         }
//     }
//     return 0;
// }


// -------------- MAKE MY OWN QUEUE CLASS --------------------------------



#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

const int INF = 1e9;

class Queue
{
    int * arr;      // array to store queue elements
    int capacity;   // capacity of queue elements
    int head;       // front element of the queue (starting index 0)
    int tail;       // back element of the queue (index)
    int count;      // current number of elements 

public:
    Queue(int size = INF);  // constructor
    ~Queue();               // destructor

    // Functions
    int pop();              // dequeues elements in the front and print it (if not, print -1)
    void push(int x);       // add element to queue           
    int size();             // get current size of queue
    int empty();            // check if queue is empty (print 1 true, 0 false)
    int front();            // print head element (-1 if empty)
    int back();             // print tail element (-1 if empty)
};  


// Constructor
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    head = 0; 
    tail = -1;
    count = 0;
}

// Destructor   free memory allocated
Queue::~Queue()
{
    delete[] arr;
}

int Queue::empty() // check if queue is empty (print 1 true, 0 false)
{
    if (count == 0) {
        //cout << 1 << endl;
        return 1;
    }
    //cout << 0 << endl;
    return 0;
} 

// pop 앞에있는걸 지우기
int Queue::pop()
{
    // 비어있다면 -1 프린트
    if(empty()) {
        cout << -1 << endl; // underflow
        return -1; // stdlib 에 저장되어있는 이름 (exit 1) 과 같다
    }

    // 비어있지 않다면 head 프린트
    int x = arr[head];
    cout << x << endl;

    // 나머지 일처리들
    head = (head+1)%capacity;
    count--;

    return x;
}

// push 뒤에 넣기
void Queue::push(int x)
{
    // if stack is full
    if (count >= capacity)
    {
        cout << "Queue is full" << endl;
        return;
    }
    
    // otherwise
    tail = (tail+1)%capacity;
    arr[tail] = x;
    count++;
}

// size
int Queue::size()
{
    cout << count << endl;
    return count;
}


// front element 구하기
int Queue::front() 
{
    if (empty())
    {
        cout << "-1" << endl;
        return -1;
    }
    cout << arr[head] << endl;
    return arr[head];
}

// back element 구하기
int Queue::back()
{
    if (empty())
    {
        cout << "-1" << endl;
        return -1;
    }
    cout << arr[tail] << endl;
    return arr[tail];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    Queue q(n); // create a queue of capacity n
    int num;

    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;

        if (str == "push")
        {
            int topush; cin >> topush;
            q.push(topush);
        }
        else if (str == "pop")
        {   
            q.pop();
        }
        else if (str == "size")
        {
            q.size();
        }
        else if (str == "empty")
        {
            int isEmpty = q.empty();
            if (isEmpty == 1) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (str == "front")
        {
            q.front();
        }
        else if (str == "back")
        {
            q.back();
        }
    }
    return 0;
}
