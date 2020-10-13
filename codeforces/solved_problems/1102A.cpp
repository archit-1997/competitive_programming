/*You are given an integer sequence 1,2,…,n. You have to divide it into two sets A and B in such a way that each element belongs to exactly one set and |sum(A)−sum(B)|

is minimum possible.

The value |x|
is the absolute value of x and sum(S) is the sum of elements of the set S

.
Input

The first line of the input contains one integer n
(1≤n≤2⋅109

).
Output

Print one integer — the minimum possible value of |sum(A)−sum(B)|
if you divide the initial sequence 1,2,…,n into two sets A and B

.
Examples
Input
Copy

3

Output
Copy

0

Input
Copy

5

Output
Copy

1

Input
Copy

6

Output
Copy

1

Note

Some (not all) possible answers to examples:

In the first example you can divide the initial sequence into sets A={1,2}
and B={3} so the answer is 0

.

In the second example you can divide the initial sequence into sets A={1,3,4}
and B={2,5} so the answer is 1

.

In the third example you can divide the initial sequence into sets A={1,4,5}
and B={2,3,6} so the answer is 1.
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
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	FAST;
	
	ll n;	cin>>n;
	
	ll sum=((n)*(n+1))/2;
	
	cout<<sum%2;
	
	return 0;
}
