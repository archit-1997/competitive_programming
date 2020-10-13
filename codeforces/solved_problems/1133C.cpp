/*You are a coach at your local university. There are n students under your supervision, the programming skill of the i-th student is ai

.

You have to create a team for a new programming competition. As you know, the more students some team has the more probable its victory is! So you have to create a team with the maximum number of students. But you also know that a team should be balanced. It means that the programming skill of each pair of students in a created team should differ by no more than 5

.

Your task is to report the maximum possible number of students in a balanced team.
Input

The first line of the input contains one integer n
(1≤n≤2⋅105

) — the number of students.

The second line of the input contains n
integers a1,a2,…,an (1≤ai≤109), where ai is a programming skill of the i

-th student.
Output

Print one integer — the maximum possible number of students in a balanced team.
Examples
Input
Copy

6
1 10 17 12 15 2

Output
Copy

3

Input
Copy

10
1337 1337 1337 1337 1337 1337 1337 1337 1337 1337

Output
Copy

10

Input
Copy

6
1 1000 10000 10 100 1000000000

Output
Copy

1

Note

In the first example you can create a team with skills [12,17,15]

.

In the second example you can take all students in a team because their programming skills are equal.

In the third example you can create a team consisting of a single student (and you cannot create a team consisting of at least two students).
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
	V v;
	
	FOR(i,0,n)
	{
		ll num;	cin>>num;
		v.pb(num);
	}
	
	sort(v.begin(),v.end());
	
	ll ans=INT_MIN;
	
	FOR(i,0,n)
	{
	    ll limit=v[i]+5;
	    
	    ll val=upper_bound(v.begin(),v.end(),limit)-(v.begin()+i);
	    
	    ans=max(ans,val);
	}
	
	cout<<ans;
	
	return 0;
}
