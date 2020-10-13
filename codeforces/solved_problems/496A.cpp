/*Mike is trying rock climbing but he is awful at it.

There are n holds on the wall, i-th hold is at height ai off the ground. Besides, let the sequence ai increase, that is, ai < ai + 1 for all i from 1 to n - 1; we will call such sequence a track. Mike thinks that the track a1, ..., an has difficulty . In other words, difficulty equals the maximum distance between two holds that are adjacent in height.

Today Mike decided to cover the track with holds hanging on heights a1, ..., an. To make the problem harder, Mike decided to remove one hold, that is, remove one element of the sequence (for example, if we take the sequence (1, 2, 3, 4, 5) and remove the third element from it, we obtain the sequence (1, 2, 4, 5)). However, as Mike is awful at climbing, he wants the final difficulty (i.e. the maximum difference of heights between adjacent holds after removing the hold) to be as small as possible among all possible options of removing a hold. The first and last holds must stay at their positions.

Help Mike determine the minimum difficulty of the track after removing one hold.
Input

The first line contains a single integer n (3 ≤ n ≤ 100) — the number of holds.

The next line contains n space-separated integers ai (1 ≤ ai ≤ 1000), where ai is the height where the hold number i hangs. The sequence ai is increasing (i.e. each element except for the first one is strictly larger than the previous one).
Output

Print a single number — the minimum difficulty of the track after removing a single hold.
Examples
Input
Copy

3
1 4 6

Output
Copy

5

Input
Copy

5
1 2 3 4 5

Output
Copy

2

Input
Copy

5
1 2 3 7 8

Output
Copy

4

Note

In the first sample you can remove only the second hold, then the sequence looks like (1, 6), the maximum difference of the neighboring elements equals 5.

In the second test after removing every hold the difficulty equals 2.

In the third test you can obtain sequences (1, 3, 7, 8), (1, 2, 7, 8), (1, 2, 3, 8), for which the difficulty is 4, 5 and 5, respectively. Thus, after removing the second element we obtain the optimal answer — 4.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;	cin>>n;
	vector<ll> v;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		v.push_back(num);
	}
	
// 	if(n==3)
// 	{
// 	    ll d=v[2]-v[0];
// 	    cout<<d;
// 	}
// 	else
// 	{
	    ll val=INT_MAX,index=0;
	    
	    for(ll i=1;i<=n-2;i++)
	    {
	        ll num=v[i+1]-v[i-1];
	        if(num<val)
	        {
	            val=num;
	            index=i;
	        }
	    }
	    
	    v.erase(v.begin()+index);
	    
	   ll ans=INT_MIN;
	    
	   for(ll i=0;i<=v.size()-2;i++)
	        ans=max(ans,(v[i+1]-v[i]));
	        
	   cout<<ans;
	//}
	
	
	return 0;
}
