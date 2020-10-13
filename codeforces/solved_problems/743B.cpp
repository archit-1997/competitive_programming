/*Chloe, the same as Vladik, is a competitive programmer. She didn't have any problems to get to the olympiad like Vladik, but she was confused by the task proposed on the olympiad.

Let's consider the following algorithm of generating a sequence of integers. Initially we have a sequence consisting of a single element equal to 1. Then we perform (n - 1) steps. On each step we take the sequence we've got on the previous step, append it to the end of itself and insert in the middle the minimum positive integer we haven't used before. For example, we get the sequence [1, 2, 1] after the first step, the sequence [1, 2, 1, 3, 1, 2, 1] after the second step.

The task is to find the value of the element with index k (the elements are numbered from 1) in the obtained sequence, i. e. after (n - 1) steps.

Please help Chloe to solve the problem!
Input

The only line contains two integers n and k (1 ≤ n ≤ 50, 1 ≤ k ≤ 2n - 1).
Output

Print single integer — the integer at the k-th position in the obtained sequence.
Examples
Input
Copy

3 2

Output
Copy

2

Input
Copy

4 8

Output
Copy

4

Note

In the first sample the obtained sequence is [1, 2, 1, 3, 1, 2, 1]. The number on the second position is 2.

In the second sample the obtained sequence is [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1]. The number on the eighth position is 4.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second
#define P pair<ll,ll>
#define PP pair<pair<ll,ll>,ll>
#define V vector<ll>
#define VP vector<pair<ll,ll>>
#define VS vector<string>
#define VV vector<vector<ll>> 
#define VVP vector<vector<pair<ll,ll>>> 
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll,vector<ll>,greater<ll>>
#define FOR(i,a,b) for(ll i=a;i<b;i++)

int go(ll l, ll r, ll need, int alphSize)
{
    ll m = l + (r - l) / 2LL;
    if (need < m)
        return go(l, m - 1, need, alphSize - 1);
    else if (need > m)
        return go(m + 1, r, need, alphSize - 1);
    else
        return alphSize;
}

void solveABig()
{
    int n;
    ll k;

    cin >> n >> k;
    ll sz = 1;
    for (int i = 1; i < n; i++)
        sz = sz * 2LL + 1LL;
    
    cout << go(1, sz, k, n);
}

int main()
{

	solveABig();
	
	return 0;
}
