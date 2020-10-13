/*Some country is populated by wizards. They want to organize a demonstration.

There are n people living in the city, x of them are the wizards who will surely go to the demonstration. Other city people (n - x people) do not support the wizards and aren't going to go to the demonstration. We know that the city administration will react only to the demonstration involving at least y percent of the city people. Having considered the matter, the wizards decided to create clone puppets which can substitute the city people on the demonstration.

So all in all, the demonstration will involve only the wizards and their puppets. The city administration cannot tell the difference between a puppet and a person, so, as they calculate the percentage, the administration will consider the city to be consisting of only n people and not containing any clone puppets.

Help the wizards and find the minimum number of clones to create to that the demonstration had no less than y percent of the city people.
Input

The first line contains three space-separated integers, n, x, y (1 ≤ n, x, y ≤ 104, x ≤ n) — the number of citizens in the city, the number of wizards and the percentage the administration needs, correspondingly.

Please note that y can exceed 100 percent, that is, the administration wants to see on a demonstration more people that actually live in the city ( > n).
Output

Print a single integer — the answer to the problem, the minimum number of clones to create, so that the demonstration involved no less than y percent of n (the real total city population).
Examples
Input
Copy

10 1 14

Output
Copy

1

Input
Copy

20 10 50

Output
Copy

0

Input
Copy

1000 352 146

Output
Copy

1108

Note

In the first sample it is necessary that at least 14% of 10 people came to the demonstration. As the number of people should be integer, then at least two people should come. There is only one wizard living in the city and he is going to come. That isn't enough, so he needs to create one clone.

In the second sample 10 people should come to the demonstration. The city has 10 wizards. They will all come to the demonstration, so nobody has to create any clones.
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
	
	ll n,x,y;   cin>>n>>x>>y;
	
	ll pro=n*y;
	
	ll flag=pro%100;
	
	ll y_per=(n*y)/100;
	
	if(flag!=0)
	    y_per+=1;
	
	if(x>=y_per)
	    cout<<0;
	else
	    cout<<(y_per-x);
	
	return 0;
}
