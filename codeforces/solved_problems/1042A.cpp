/*There are 𝑛 benches in the Berland Central park. It is known that 𝑎𝑖 people are currently sitting on the 𝑖-th bench. Another 𝑚 people are coming to the park and each of them is going to have a seat on some bench out of 𝑛

available.

Let 𝑘
be the maximum number of people sitting on one bench after additional 𝑚 people came to the park. Calculate the minimum possible 𝑘 and the maximum possible 𝑘

.

Nobody leaves the taken seat during the whole process.
Input

The first line contains a single integer 𝑛
(1≤𝑛≤100)

— the number of benches in the park.

The second line contains a single integer 𝑚
(1≤𝑚≤10000)

— the number of people additionally coming to the park.

Each of the next 𝑛
lines contains a single integer 𝑎𝑖 (1≤𝑎𝑖≤100) — the initial number of people on the 𝑖

-th bench.
Output

Print the minimum possible 𝑘
and the maximum possible 𝑘, where 𝑘 is the maximum number of people sitting on one bench after additional 𝑚

people came to the park.
Examples
Input
Copy

4
6
1
1
1
1

Output
Copy

3 7

Input
Copy

1
10
5

Output
Copy

15 15

Input
Copy

3
6
1
6
5

Output
Copy

6 12

Input
Copy

3
7
1
6
5

Output
Copy

7 13

Note

In the first example, each of four benches is occupied by a single person. The minimum 𝑘
is 3. For example, it is possible to achieve if two newcomers occupy the first bench, one occupies the second bench, one occupies the third bench, and two remaining — the fourth bench. The maximum 𝑘 is 7

. That requires all six new people to occupy the same bench.

The second example has its minimum 𝑘
equal to 15 and maximum 𝑘 equal to 15, as there is just a single bench in the park and all 10 people will occupy it.
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
	
	ll n,m;	cin>>n>>m;
	vector<ll> v;
	
	priority_queue<ll,vector<ll> ,greater<ll>> pq;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		pq.push(num);
		v.push_back(num);
	}
	
	ll big=*max_element(v.begin(),v.end());
	
	big+=m;
	
	for(ll i=0;i<m;i++)
	{
	    ll num=pq.top();
	    pq.pop();
	    num++;
	    pq.push(num);
	}
	
	ll small=0;
	
	while(!pq.empty())
	{
	    small=pq.top();
	    pq.pop();
	}
	
	cout<<small<<" "<<big;
	
	
	return 0;
}
