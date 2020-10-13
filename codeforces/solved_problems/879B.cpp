/*n people are standing in a line to play table tennis. At first, the first two players in the line play a game. Then the loser goes to the end of the line, and the winner plays with the next person from the line, and so on. They play until someone wins k games in a row. This player becomes the winner.

For each of the participants, you know the power to play table tennis, and for all players these values are different. In a game the player with greater power always wins. Determine who will be the winner.
Input

The first line contains two integers: n and k (2 ≤ n ≤ 500, 2 ≤ k ≤ 1012) — the number of people and the number of wins.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ n) — powers of the player. It's guaranteed that this line contains a valid permutation, i.e. all ai are distinct.
Output

Output a single integer — power of the winner.
Examples
Input
Copy

2 2
1 2

Output
Copy

2 

Input
Copy

4 2
3 1 2 4

Output
Copy

3 

Input
Copy

6 2
6 5 3 1 2 4

Output
Copy

6 

Input
Copy

2 10000000000
2 1

Output
Copy

2

Note

Games in the second sample:

3 plays with 1. 3 wins. 1 goes to the end of the line.

3 plays with 2. 3 wins. He wins twice in a row. He becomes the winner.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,k;	cin>>n>>k;
	if(k>n)
	    k=n;
	
	queue<ll> q;
	
	for(ll i=0;i<n;i++)
	{
	    ll num; cin>>num;
	    q.push(num);
	}
	
	ll p1=q.front();
	q.pop();
	ll p2=q.front();
	q.pop();
	ll win=max(p1,p2);
	if(win==p1)
	    q.push(p2);
	else
	    q.push(p1);
	ll count=1;
	
	while(1)
	{
	    ll t=q.front();
	    q.pop();
	    if(win>t)
	    {
	        count++;
	        if(count==k)
	        {
	            cout<<win;
	            return 0;
	        }
	        q.push(t);
	    }
	    else
	    {
	        ll tmp=win;
	        win=t;
	        count=1;
	        q.push(tmp);
	    }
	}
	
	
	return 0;
}
