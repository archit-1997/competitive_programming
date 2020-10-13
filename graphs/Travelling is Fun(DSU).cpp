/*There are cities numbered from to . Two cities, and , are connected by a bidirectional road if and only if , where is the greatest common divisor of and . Julia is planning a long vacation and wants to know whether a path exists from city to city

.

Complete the

function; it has four parameters:
Name 	Type 	Description
n 	integer 	The number of cities.
g 	integer 	Cities
and are connected if and only if
.
originCities 	integer array 	Each index
(where ) describes for the
pair of cities.
destinationCities 	integer array 	Each index
(where ) describes for the
pair of cities.

The function must return an array of
integers where the value at each index (where ) is if a path exists from city to city ; otherwise, it's

instead.

Input Format

The code to read the inputs from stdin and to pass it to the function

is provided for you. The below is documentation in case you need to create custom testcases.

    The first line contains an integer denoting 

.
The second line contains an integer denoting
.
The third line contains an integer,
, denoting the total number of elements in
.
Each line
of subsequent lines (where ) contains an integer describing
.
The next line contains an integer,
, denoting the total number of elements in
.
Each line
of subsequent lines (where ) contains an integer describing

    .

Constraints

where where

Output Format

Return an array of
integers where the value at each index (where ) is if a path exists from city to city ; otherwise, it's

instead.

Sample Input 0

6
0
4
1
4
3
6
4
3
6
2
5

Sample Output 0

1
1
1
1

Explanation 0

image

There are
cities and, given , we know that two cities and are connected if and only if

. Julia wants to know whether any path exists from:

    City 1 to city 3
    City 4 to city 6
    City 3 to city 2
    City 6 to city 5

Let the return array be

, then:

because a path exists from city 1 to city 3. Julia can follow path 1 → 3.
because a path exists from city 4 to city 6. Julia can follow path 4 → 6.
because a path exists from city 3 to city 2. Julia can follow path 3 → 2.

    because a path exists from city 6 to city 5. Julia can follow path 6 → 5.

Thus, we return

as our answer.

Sample Input 1

6
1
4
1
2
4
6
4
3
3
3
4

Sample Output 1

0
1
1
1

Explanation 1

image

There are
cities and, given , we know that two cities and are connected if and only if

. Julia wants to know whether any path exists from:

    City 1 to city 3
    City 2 to city 3
    City 4 to city 3
    City 6 to city 4

Let the return array be

, then:

because it's impossible to reach any city from city 1.
because a path exists from city 2 to city 3. Julia can follow path 2 → 6 → 3.
because a path exists from city 4 to city 3. Julia can follow path 4 → 6 → 3.

    because a path exists from city 6 to city 4. Julia can follow path 6 → 4.

Thus, we return

as our answer.

Sample Input 2

10
1
4
10
4
3
6
4
3
6
2
9

Sample Output 2

1
1
1
1
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

ll root(V &par,ll i)
{
    while(par[i]!=i)
    {
        par[i]=par[par[i]];
        i=par[i];
    }
    
    return i;
}

ll find(V &par,ll a,ll b)
{
    ll ra=root(par,a);
    ll rb=root(par,b);
    
    return (ra==rb);
}

void Union(V &par,ll a,ll b)
{
    ll ra=root(par,a);
    ll rb=root(par,b);
    
    par[ra]=rb;
}

int main()
{
	FAST;
	
	ll n,g;	cin>>n>>g;
	
	ll q;
	
	V origin,dest;
	
	cin>>q;
	
	FOR(i,0,q)
	{
		ll num;	cin>>num;
		origin.pb(num);
	}
	
	cin>>q;
	
	FOR(i,0,q)
	{
		ll num;	cin>>num;
		dest.pb(num);
	}
	
	//Making the graph
	
	V par(n+1);
	
	FOR(i,1,n+1)
	    par[i]=i;
	    
	for(ll i=g+1;i<=n;i++)
	{
	    for(ll j=2*i;j<=n;j+=i)
	    {
	        ll ra=root(par,j),rb=root(par,i);
	        
	        if(ra==rb)
	            continue;
	        else
	            Union(par,j,i);
	        
	    }
	}
	    
	//Finding the answer
	
	V ans(q,0);
	
	FOR(i,0,q)
	{
	    ll a=origin[i],b=dest[i];
	    
	    ll ra=root(par,a),rb=root(par,b);
	    
	    if(ra==rb)
	        ans[i]=1;
	}
	
	FOR(i,0,q)
	    cout<<ans[i]<<endl;
	
	
}
