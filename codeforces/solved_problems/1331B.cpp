/*There was once young lass called Mary,
Whose jokes were occasionally scary.
On this April's Fool
Fixed limerick rules
Allowed her to trip the unwary.

Can she fill all the lines
To work at all times?
On juggling the words
Right around two-thirds
She nearly ran out of rhymes.
Input
The input contains a single integer a (4≤a≤998). Not every integer in the range is a valid input for the problem; you are guaranteed that the input will be a valid integer.

Output
Output a single number.

Examples
inputCopy
35
outputCopy
57
inputCopy
57
outputCopy
319
inputCopy
391
outputCopy
1723
*/

//Archit Singh
#include <bits/stdc++.h>
using namespace std;

#define 	ll 				long long int
#define 	ld 				long double
#define 	line 			cout<<"-------------"<<endl;
#define 	f 				first
#define 	s 				second
#define 	mp(a,b) 		make_pair(a,b)
#define 	p 				pair<ll,ll>
#define 	pp 				pair<pair<ll,ll>,ll>
#define 	v 				vector<ll>
#define 	vp 				vector<pair<ll,ll>>
#define 	vs 				vector<string>
#define 	vv 				vector<vector<ll>>
#define 	vvp 			vector<vector<pair<ll,ll>>>
#define 	pb 				push_back
#define 	pf 				push_front
#define 	pqb				priority_queue<ll>
#define 	pqs 			priority_queue<ll,V,greater<ll>>
#define 	FOR(i,a,b) 		for(ll i=a;i<b;i++)
#define 	setbits(x)		__builtin_popocount(x)
#define 	zrobits(x)		__builtin_ctzll(x)
#define 	mod				1000000007
#define 	inf				1e18
#define 	ps(x,y)			fixed<<setprecision(y)<<x
#define 	ma(arr,n,type)	type *arr=new type[n]
#define 	w(x)			ll x; cin>>x; while(x--)

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

int main()
{

	init();

	ll n; 	cin >> n;

	v factors(1000, 0);

	set<ll> s;

	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << i;
			cout << n / i;
			break;
		}
	}


	return 0;
}