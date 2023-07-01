// // <<<<<<< HEAD
// // #include<bits/stdc++.h>

// // using namespace std;

// /*
// string removeDuplicates(string s, int k)
// {
//     string res = "";

//     int totalcnt = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         // cout << "i is at " << i << endl;
//         int cnt = 0;
//         int j;

//         // see how many consecutive characters there are
//         for (j = 0; i+j < s.length(); j++)
//         {
//             if (s[i+j] != s[i] || cnt == k)
//                 break;
//             if (s[i+j] == s[i])
//                 cnt ++;
//         }

//         // more than 3 consecutive characters, 
//         if (cnt >= k)
//         {
//             i = i+j-1;            // jump index
//             totalcnt++;         // total cnt
//         }
//         // less than 3 consecutive characters,
//         else
//         {
//             res += s[i];         // add the char to res
//             // cout << "insert " << s[i] << endl;
//         }
//     }

//     // cout << res << endl;
//     // cout << endl;

//     // if totalcnt is 0
//     if (totalcnt == 0)
//     {
//         return res;
//     }
//     // otherwise, which means there might be more consecutive characters
//     else
//     {
//         return removeDuplicates(res, k);
//     }
// }
// */



// #include <bits/stdc++.h>

// using namespace std;

// string removeDuplicates(string s, int k) {
//     stack<int> counts;
//     for (int i = 0; i < s.size(); ++i) {
//         // cout << s[i] << " ";
//         if (i == 0 || s[i] != s[i - 1]) {
//             counts.push(1);
//         } else if (++counts.top() == k) {
//             // cout << counts.top();
//             counts.pop();
//             s.erase(i - k + 1, k);
//             i = i - k;
//         }
//         // cout << counts.top();
//         // cout << endl;
//     }
//     return s;
// }

// int main()
// {
//     string s = "pbbcggttciiippooaais";
//     int k = 2;

//     cout << removeDuplicates(s, k) << endl;

//     // string s = "deeedbbcccbdaa";
//     // int k = 3;

//     // removeDuplicates(s, k);
// }