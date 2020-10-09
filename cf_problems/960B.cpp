/*You are given two arrays A and B, each of size n. The error, E, between these two arrays is defined . You have to perform exactly k1 operations on array A and exactly k2 operations on array B. In one operation, you have to choose one element of the array and increase or decrease it by 1.

Output the minimum possible value of error after k1 operations on array A and k2 operations on array B have been performed.
Input

The first line contains three space-separated integers n (1 ≤ n ≤ 103), k1 and k2 (0 ≤ k1 + k2 ≤ 103, k1 and k2 are non-negative) — size of arrays and number of operations to perform on A and B respectively.

Second line contains n space separated integers a1, a2, ..., an ( - 106 ≤ ai ≤ 106) — array A.

Third line contains n space separated integers b1, b2, ..., bn ( - 106 ≤ bi ≤ 106)— array B.
Output

Output a single integer — the minimum possible value of after doing exactly k1 operations on array A and exactly k2 operations on array B.
Examples
Input
Copy

2 0 0
1 2
2 3

Output
Copy

2

Input
Copy

2 1 0
1 2
2 2

Output
Copy

0

Input
Copy

2 5 7
3 4
14 4

Output
Copy

1

Note

In the first sample case, we cannot perform any operations on A or B. Therefore the minimum possible error E = (1 - 2)2 + (2 - 3)2 = 2.

In the second sample case, we are required to perform exactly one operation on A. In order to minimize error, we increment the first element of A by 1. Now, A = [2, 2]. The error is now E = (2 - 2)2 + (2 - 2)2 = 0. This is the minimum possible error obtainable.

In the third sample case, we can increase the first element of A to 8, using the all of the 5 moves available to us. Also, the first element of B can be reduced to 8 using the 6 of the 7 available moves. Now A = [8, 4] and B = [8, 4]. The error is now E = (8 - 8)2 + (4 - 4)2 = 0, but we are still left with 1 move for array B. Increasing the second element of B to 5 using the left move, we get B = [8, 5] and E = (8 - 8)2 + (4 - 5)2 = 1.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll> pq;

int main(){
    int n, k1, k2, k;
    cin>>n>>k1>>k2;
    k = k1+k2;
    vector<ll> a(n), b(n), arr(n);
    for(int i=0 ; i<n ; ++i)
        cin>>a[i];
    for(int i=0 ; i<n ; ++i){
        cin>>b[i];
        arr[i] = abs(a[i]-b[i]);
        pq.push(arr[i]);
    }
    while(k>0){
        ll curr = pq.top();
        pq.pop();
        pq.push(abs(curr-1));
        k--;
    }
    ll ans = 0;
    while(!pq.empty()){
        ll curr = pq.top();
        ans += (curr*curr);
        pq.pop();
    }
    cout<<ans;
}
