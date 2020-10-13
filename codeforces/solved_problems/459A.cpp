/*Pashmak has fallen in love with an attractive girl called Parmida since one year ago...

Today, Pashmak set up a meeting with his partner in a romantic garden. Unfortunately, Pashmak has forgotten where the garden is. But he remembers that the garden looks like a square with sides parallel to the coordinate axes. He also remembers that there is exactly one tree on each vertex of the square. Now, Pashmak knows the position of only two of the trees. Help him to find the position of two remaining ones.
Input

The first line contains four space-separated x1, y1, x2, y2 ( - 100 ≤ x1, y1, x2, y2 ≤ 100) integers, where x1 and y1 are coordinates of the first tree and x2 and y2 are coordinates of the second tree. It's guaranteed that the given points are distinct.
Output

If there is no solution to the problem, print -1. Otherwise print four space-separated integers x3, y3, x4, y4 that correspond to the coordinates of the two other trees. If there are several solutions you can output any of them.

Note that x3, y3, x4, y4 must be in the range ( - 1000 ≤ x3, y3, x4, y4 ≤ 1000).
Examples
Input
Copy

0 0 0 1

Output
Copy

1 0 1 1

Input
Copy

0 0 1 1

Output
Copy

0 1 1 0

Input
Copy

0 0 1 2

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
	
	ll x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
	
	ll dx=abs(x1-x2),dy=abs(y1-y2);
	
	if(x1==x2 || y1==y2 || dx==dy)
	{
	    if(x1==x2)
	        cout<<x1+dy<<" "<<y1<<" "<<x2+dy<<" "<<y2;
	    else if(y1==y2)
	        cout<<x1<<" "<<y1+dx<<" "<<x2<<" "<<y2+dx;
	    else
	    {
	        if(y1<y2)
	        {
	            if(x1<x2)
	                cout<<x1+dx<<" "<<y1<<" "<<x2-dx<<" "<<y2;
	            else
	                cout<<x1-dx<<" "<<y1<<" "<<x2+dx<<" "<<y2;
	        }
	        else
	        {
	            if(x1<x2)
	                cout<<x2-dx<<" "<<y2<<" "<<x1+dx<<" "<<y1;
	            else
	                cout<<x2+dx<<" "<<y2<<" "<<x1-dx<<" "<<y1;
	        }
	    }
	}
	else
	    cout<<-1;
	
	return 0;
}
