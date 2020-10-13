/*Mahmoud wants to send a message to his friend Ehab. Their language consists of n words numbered from 1 to n. Some words have the same meaning so there are k groups of words such that all the words in some group have the same meaning.

Mahmoud knows that the i-th word can be sent with cost ai. For each word in his message, Mahmoud can either replace it with another word of the same meaning or leave it as it is. Can you help Mahmoud determine the minimum cost of sending the message?

The cost of sending the message is the sum of the costs of sending every word in it.
Input

The first line of input contains integers n, k and m (1 ≤ k ≤ n ≤ 105, 1 ≤ m ≤ 105) — the number of words in their language, the number of groups of words, and the number of words in Mahmoud's message respectively.

The second line contains n strings consisting of lowercase English letters of length not exceeding 20 which represent the words. It's guaranteed that the words are distinct.

The third line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109) where ai is the cost of sending the i-th word.

The next k lines describe the groups of words of same meaning. The next k lines each start with an integer x (1 ≤ x ≤ n) which means that there are x words in this group, followed by x integers which represent the indices of words in this group. It's guaranteed that each word appears in exactly one group.

The next line contains m space-separated words which represent Mahmoud's message. Each of these words appears in the list of language's words.
Output

The only line should contain the minimum cost to send the message after replacing some words (maybe none) with some words of the same meaning.
Examples
Input
Copy

5 4 4
i loser am the second
100 1 1 5 10
1 1
1 3
2 2 5
1 4
i am the second

Output
Copy

107

Input
Copy

5 4 4
i loser am the second
100 20 1 5 10
1 1
1 3
2 2 5
1 4
i am the second

Output
Copy

116

Note

In the first sample, Mahmoud should replace the word "second" with the word "loser" because it has less cost so the cost will be 100+1+5+1=107.

In the second sample, Mahmoud shouldn't do any replacement so the cost will be 100+1+5+10=116.
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

void Union(V &par,V &cost,ll a,ll b)
{
	ll ra=root(par,a),rb=root(par,b);

	if(ra==rb)
		return;

	if(cost[ra]<cost[rb])
		par[rb]=ra;
	else
		par[ra]=rb;
}

int main()
{
	FAST;
	
	ll n,k,m;	cin>>n>>k>>m;

	map<string,ll> hash;

	FOR(i,1,n+1)
	{
		string s;	cin>>s;
		hash[s]=i;
	}

	V cost(n+1);

	V par(n+1);
	FOR(i,1,n+1)
		par[i]=i;


	FOR(i,1,n+1)
		cin>>cost[i];

	FOR(i,0,k)
	{
		ll x;	cin>>x;

		V dost(x);

		FOR(j,0,x)
			cin>>dost[j];

		if(x>=2)
		{
			FOR(j,1,x)
				Union(par,cost,dost[j-1],dost[j]);
		}	
	}

	ll ans=0;

	FOR(i,0,m)
	{
		string s;	cin>>s;
		ll val=hash[s];

		ll papa=root(par,val);

		ans+=cost[papa];
	}

	cout<<ans;
	
	return 0;
}
