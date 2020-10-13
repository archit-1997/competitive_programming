/*Kefa wants to celebrate his first big salary by going to restaurant. However, he needs company.

Kefa has n friends, each friend will agree to go to the restaurant if Kefa asks. Each friend is characterized by the amount of money he has and the friendship factor in respect to Kefa. The parrot doesn't want any friend to feel poor compared to somebody else in the company (Kefa doesn't count). A friend feels poor if in the company there is someone who has at least d units of money more than he does. Also, Kefa wants the total friendship factor of the members of the company to be maximum. Help him invite an optimal company!
Input

The first line of the input contains two space-separated integers, n and d (1 ≤ n ≤ 105, ) — the number of Kefa's friends and the minimum difference between the amount of money in order to feel poor, respectively.

Next n lines contain the descriptions of Kefa's friends, the (i + 1)-th line contains the description of the i-th friend of type mi, si (0 ≤ mi, si ≤ 109) — the amount of money and the friendship factor, respectively.
Output

Print the maximum total friendship factir that can be reached.
Examples
Input
Copy

4 5
75 5
0 100
150 20
75 1

Output
Copy

100

Input
Copy

5 100
0 7
11 32
99 10
46 8
87 54

Output
Copy

111

Note

In the first sample test the most profitable strategy is to form a company from only the second friend. At all other variants the total degree of friendship will be worse.

In the second sample test we can take all the friends.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;

int compare(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first<b.first;
}

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,d;	cin>>n>>d;
	vector<pair<ll,ll>> v;
	
	for(ll i=0;i<n;i++)
	{
		ll a,b; cin>>a>>b;
		v.push_back({a,b});
	}
	
	sort(v.begin(),v.end(),compare);
	
	ll ans=INT_MIN,sum=0,i=0,j=0;
	
	for(ll i=0;i<n;i++)
	{
	    if((v[i].first-v[j].first)<d)
	    {
	        sum+=v[i].second;
	        ans=max(ans,sum);
	    }
	    else
	    {
	        sum-=v[j].second;
	        j++;
	        i--;
	    }
	}

    cout<<ans<<endl;
    
	
	return 0;
}
