/*A magic island Geraldion, where Gerald lives, has its own currency system. It uses banknotes of several values. But the problem is, the system is not perfect and sometimes it happens that Geraldionians cannot express a certain sum of money with any set of banknotes. Of course, they can use any number of banknotes of each value. Such sum is called unfortunate. Gerald wondered: what is the minimum unfortunate sum?
Input

The first line contains number n (1 ≤ n ≤ 1000) — the number of values of the banknotes that used in Geraldion.

The second line contains n distinct space-separated numbers a1, a2, ..., an (1 ≤ ai ≤ 106) — the values of the banknotes.
Output

Print a single line — the minimum unfortunate sum. If there are no unfortunate sums, print  - 1.
Examples
Input
Copy

5
1 2 3 4 5

Output
Copy

-1
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;

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
	
	//if one present then every sum can be expressed
	if(find(v.begin(),v.end(),1)!=v.end())
    {
        cout<<-1<<endl;
        return 0;
    }
    else
        cout<<1<<endl;
    
	
	
	return 0;
}
