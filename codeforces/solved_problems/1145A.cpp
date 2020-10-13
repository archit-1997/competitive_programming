/*Thanos sort is a supervillain sorting algorithm, which works as follows: if the array is not sorted, snap your fingers* to remove the first or the second half of the items, and repeat the process.

Given an input array, what is the size of the longest sorted array you can obtain from it using Thanos sort?

*Infinity Gauntlet required.

Input
The first line of input contains a single number n (1≤n≤16) — the size of the array. n is guaranteed to be a power of 2.

The second line of input contains n space-separated integers ai (1≤ai≤100) — the elements of the array.

Output
Return the maximal length of a sorted array you can obtain using Thanos sort. The elements of the array have to be sorted in non-decreasing order.

Examples
inputCopy
4
1 2 2 4
outputCopy
4
inputCopy
8
11 12 1 2 13 14 3 4
outputCopy
2
inputCopy
4
7 6 5 4
outputCopy
1
Note
In the first example the array is already sorted, so no finger snaps are required.

In the second example the array actually has a subarray of 4 sorted elements, but you can not remove elements from different sides of the array in one finger snap. Each time you have to remove either the whole first half or the whole second half, so you'll have to snap your fingers twice to get to a 2-element sorted array.

In the third example the array is sorted in decreasing order, so you can only save one element from the ultimate destruction.*/

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

ll thanos(v &V, ll start, ll end, ll &ans)
{
	if (end - start <= 1)
		return 1;

	//Check in this start-end

	ll flag = 0;

	FOR(i, start, end)
	{
		if (V[i] > V[i + 1])
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0)
		ans = max(ans, end - start);

	ll mid = start + (end - start) / 2;

	ll left = thanos(V, start, mid, ans);
	ll right = thanos(V, mid, end, ans);

	return max(ans, max(left, right));


}

int main()
{

	init();

	ll n;	cin >> n;

	v V(n);

	FOR(i, 0, n)
	cin >> V[i];

	ll inc = 0;

	//Check for increasing
	FOR(i, 0, n - 1)
	{
		if (V[i] > V[i + 1])
		{
			inc = 1;
			break;
		}
	}

	if (inc == 0)
	{
		cout << n;
		return 0;
	}

	//Otherwise
	ll ans = 1;

	ll left = thanos(V, 0, n / 2, ans);

	ll right = thanos(V, n / 2, n, ans);

	cout << max(left, right);

	return 0;
}