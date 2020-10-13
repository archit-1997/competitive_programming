/*Vanya has a table consisting of 100 rows, each row contains 100 cells. The rows are numbered by integers from 1 to 100 from bottom to top, the columns are numbered from 1 to 100 from left to right.

In this table, Vanya chose n rectangles with sides that go along borders of squares (some rectangles probably occur multiple times). After that for each cell of the table he counted the number of rectangles it belongs to and wrote this number into it. Now he wants to find the sum of values in all cells of the table and as the table is too large, he asks you to help him find the result.
Input

The first line contains integer n (1 ≤ n ≤ 100) — the number of rectangles.

Each of the following n lines contains four integers x1, y1, x2, y2 (1 ≤ x1 ≤ x2 ≤ 100, 1 ≤ y1 ≤ y2 ≤ 100), where x1 and y1 are the number of the column and row of the lower left cell and x2 and y2 are the number of the column and row of the upper right cell of a rectangle.
Output

In a single line print the sum of all values in the cells of the table.
Examples
Input
Copy

2
1 1 2 3
2 2 3 3

Output
Copy

10

Input
Copy

2
1 1 3 3
1 1 3 3

Output
Copy

18

Note

Note to the first sample test:

Values of the table in the first three rows and columns will be as follows:

121

121

110

So, the sum of values will be equal to 10.

Note to the second sample test:

Values of the table in the first three rows and columns will be as follows:

222

222

222

So, the sum of values will be equal to 18.
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
	
	VV rec(101,V (101,0));
	
	ll n;   cin>>n;
	
	while(n--)
	{
	    ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	    
	    for(ll i=x1;i<=x2;i++)
	    {
	        for( ll j=y1;j<=y2;j++)
	        {
	            rec[i][j]++;
	        }
	    }
	    
	    
	}
	
	ll ans=0;
	    
	    FOR(i,1,101)
	    {
	        FOR(j,1,101)
	            ans+=rec[i][j];
	    }
	    
	    cout<<ans<<endl;
	
	return 0;
}
