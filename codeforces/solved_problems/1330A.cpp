/*
Dreamoon is a big fan of the Codeforces contests.

One day, he claimed that he will collect all the places from 1 to 54 after two more rated contests. It's amazing!

Based on this, you come up with the following problem:

There is a person who participated in n Codeforces rounds. His place in the first round is a1, his place in the second round is a2, ..., his place in the n-th round is an.

You are given a positive non-zero integer x.

Please, find the largest v such that this person can collect all the places from 1 to v after x more rated contests.

In other words, you need to find the largest v, such that it is possible, that after x more rated contests, for each 1≤i≤v, there will exist a contest where this person took the i-th place.

For example, if n=6, x=2 and a=[3,1,1,5,7,10] then answer is v=5, because if on the next two contest he will take places 2 and 4, then he will collect all places from 1 to 5, so it is possible to get v=5.

Input
The first line contains an integer t (1≤t≤5) denoting the number of test cases in the input.

Each test case contains two lines. The first line contains two integers n,x (1≤n,x≤100). The second line contains n positive non-zero integers a1,a2,…,an (1≤ai≤100).

Output
For each test case print one line containing the largest v, such that it is possible that after x other contests, for each 1≤i≤v, there will exist a contest where this person took the i-th place.

Example
inputCopy
5
6 2
3 1 1 5 7 10
1 100
100
11 1
1 1 1 1 1 1 1 1 1 1 1
1 1
1
4 57
80 60 40 20
outputCopy
5
101
2
2
60
Note
The first test case is described in the statement.

In the second test case, the person has one hundred future contests, so he can take place 1,2,…,99 and place 101 on them in some order, to collect places 1,2,…,101.
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
#define 	FOR(i,a,b) 		for(ll i=a;i<=b;i++)
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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{

	init();

	w(x)
	{
		ll n, x;	cin >> n >> x;

		v V(201, 0);

		FOR(i, 1, n)
		{
			ll num;	cin >> num;
			if (V[num] == 0)
				V[num] = 1;
		}

		ll count = 1;

		while (x != 0 && count < 201)
		{
			if (V[count] == 0)
			{
				V[count] = 1;
				x--;
			}
			count++;
		}

		ll ans = 1;

		FOR(i, 1, 200)
		{
			if (V[i] == 0)
			{
				ans = i - 1;
				break;
			}

		}

		if (n == 0)
			cout << 0 << endl;
		else if (count == 201)
			cout << count - 1 << endl;
		else
			cout << ans << endl;
	}



	return 0;
}
