/*Two bored soldiers are playing card war. Their card deck consists of exactly n cards, numbered from 1 to n, all values are different. They divide cards between them in some manner, it's possible that they have different number of cards. Then they play a "war"-like card game.

The rules are following. On each turn a fight happens. Each of them picks card from the top of his stack and puts on the table. The one whose card value is bigger wins this fight and takes both cards from the table to the bottom of his stack. More precisely, he first takes his opponent's card and puts to the bottom of his stack, and then he puts his card to the bottom of his stack. If after some turn one of the player's stack becomes empty, he loses and the other one wins.

You have to calculate how many fights will happen and who will win the game, or state that game won't end.
Input

First line contains a single integer n (2 ≤ n ≤ 10), the number of cards.

Second line contains integer k1 (1 ≤ k1 ≤ n - 1), the number of the first soldier's cards. Then follow k1 integers that are the values on the first soldier's cards, from top to bottom of his stack.

Third line contains integer k2 (k1 + k2 = n), the number of the second soldier's cards. Then follow k2 integers that are the values on the second soldier's cards, from top to bottom of his stack.

All card values are different.
Output

If somebody wins in this game, print 2 integers where the first one stands for the number of fights before end of game and the second one is 1 or 2 showing which player has won.

If the game won't end and will continue forever output  - 1.
Examples
Input
Copy

4
2 1 3
2 4 2

Output
Copy

6 2

Input
Copy

3
1 2
2 1 3

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
	
	ll n;	cin>>n;
	
	ll k1,k2;   cin>>k1;
	
	queue<ll> q1,q2;
	
	FOR(i,0,k1)
	{
	    ll num; cin>>num;
	    q1.push(num);
	}
	
	cin>>k2;
	
	FOR(i,0,k2)
	{
	    ll num; cin>>num;
	    q2.push(num);
	}
	
	ll count=0;
	
	while(!q1.empty() && !q2.empty())
	{
	    if(q1.front()>q2.front())
	    {
	        ll t1=q1.front(),t2=q2.front();
	        q1.pop(),q2.pop();
	        q1.push(t2);
	        q1.push(t1);
	    }
	    else
	    {
	        ll t1=q1.front(),t2=q2.front();
	        q1.pop(),q2.pop();
	        q2.push(t1);
	        q2.push(t2);
	    }
	    
	    count++;
	    
	    if(count>3628800) //10!
	    {
	        cout<<-1;
	        return 0;
	    }
	}
	
	if(q1.empty())
	    cout<<count<<" 2";
	else
	    cout<<count<<" 1";
	
	return 0;
}
