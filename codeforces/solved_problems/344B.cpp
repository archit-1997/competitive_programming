/*Mad scientist Mike is busy carrying out experiments in chemistry. Today he will attempt to join three atoms into one molecule.

A molecule consists of atoms, with some pairs of atoms connected by atomic bonds. Each atom has a valence number — the number of bonds the atom must form with other atoms. An atom can form one or multiple bonds with any other atom, but it cannot form a bond with itself. The number of bonds of an atom in the molecule must be equal to its valence number.

Mike knows valence numbers of the three atoms. Find a molecule that can be built from these atoms according to the stated rules, or determine that it is impossible.
Input

The single line of the input contains three space-separated integers a, b and c (1 ≤ a, b, c ≤ 106) — the valence numbers of the given atoms.
Output

If such a molecule can be built, print three space-separated integers — the number of bonds between the 1-st and the 2-nd, the 2-nd and the 3-rd, the 3-rd and the 1-st atoms, correspondingly. If there are multiple solutions, output any of them. If there is no solution, print "Impossible" (without the quotes).
Examples
Input
Copy

1 1 2

Output
Copy

0 1 1

Input
Copy

3 4 5

Output
Copy

1 3 2

Input
Copy

4 1 1

Output
Copy

Impossible

Note

The first sample corresponds to the first figure. There are no bonds between atoms 1 and 2 in this case.

The second sample corresponds to the second figure. There is one or more bonds between each pair of atoms.

The third sample corresponds to the third figure. There is no solution, because an atom cannot form bonds with itself.

The configuration in the fourth figure is impossible as each atom must have at least one atomic bond.
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
	
	ll a,b,c;   cin>>a>>b>>c;
	
	ll sum=a+b+c;
	
	if(sum%2==1)
	    cout<<"Impossible";
	else
	{
	    ll x=(a+b-c);
	    ll y=(a-b+c);
	    ll z=(c-a+b);
	    
	    if(x<0 || y<0 || z<0)
	    {
	        cout<<"Impossible";
	        return 0;
	    }
	    else if(x%2==1 || y%2==1 || z%2==1)
	    {
	        cout<<"Impossible";
	        return 0;
	    }
	    else
	    {
	        cout<<x/2<<" "<<z/2<<" "<<y/2;
	    }
	}
	
	return 0;
}
