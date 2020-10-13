/*Vus the Cossack holds a programming competition, in which n people participate. He decided to award them all with pens and notebooks. It is known that Vus has exactly m pens and k

notebooks.

Determine whether the Cossack can reward all participants, giving each of them at least one pen and at least one notebook.
Input

The first line contains three integers n
, m, and k (1≤n,m,k≤100

) — the number of participants, the number of pens, and the number of notebooks respectively.
Output

Print "Yes" if it possible to reward all the participants. Otherwise, print "No".

You can print each letter in any case (upper or lower).
Examples
Input
Copy

5 8 6

Output
Copy

Yes

Input
Copy

3 9 3

Output
Copy

Yes

Input
Copy

8 5 20

Output
Copy

No

Note

In the first example, there are 5
participants. The Cossack has 8 pens and 6

notebooks. Therefore, he has enough pens and notebooks.

In the second example, there are 3
participants. The Cossack has 9 pens and 3

notebooks. He has more than enough pens but only the minimum needed number of notebooks.

In the third example, there are 8
participants but only 5 pens. Since the Cossack does not have enough pens, the answer is "No".
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
	
	ll n,m,k;	cin>>n>>m>>k;
	
	if(n<=min(m,k))
	    cout<<"Yes";
	else
	    cout<<"No";
	
	return 0;
}
