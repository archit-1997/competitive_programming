/*There exists an island called Arpa’s land, some beautiful girls live there, as ugly ones do.

Mehrdad wants to become minister of Arpa’s land. Arpa has prepared an exam. Exam has only one question, given n, print the last digit of 1378n.

Mehrdad has become quite confused and wants you to help him. Please help, although it's a naive cheat.
Input

The single line of input contains one integer n (0  ≤  n  ≤  109).
Output

Print single integer — the last digit of 1378n.
Examples
Input
Copy

1

Output
Copy

8

Input
Copy

2

Output
Copy

4

Note

In the first example, last digit of 13781 = 1378 is 8.

In the second example, last digit of 13782 = 1378·1378 = 1898884 is 4.
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
	
	if(n==0)
	{
	    cout<<1;
	    return 0;
	}
	
	n=n%4;
	
	if(n==0)
	    cout<<6;
	else if(n==1)
	    cout<<8;
	else if(n==2)
	    cout<<4;
	else 
	    cout<<2;
	
	return 0;
}
