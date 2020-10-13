/*Sonya decided that having her own hotel business is the best way of earning money because she can profit and rest wherever she wants.

The country where Sonya lives is an endless line. There is a city in each integer coordinate on this line. She has 𝑛
hotels, where the 𝑖-th hotel is located in the city with coordinate 𝑥𝑖

. Sonya is a smart girl, so she does not open two or more hotels in the same city.

Sonya understands that her business needs to be expanded by opening new hotels, so she decides to build one more. She wants to make the minimum distance from this hotel to all others to be equal to 𝑑

. The girl understands that there are many possible locations to construct such a hotel. Thus she wants to know the number of possible coordinates of the cities where she can build a new hotel.

Because Sonya is lounging in a jacuzzi in one of her hotels, she is asking you to find the number of cities where she can build a new hotel so that the minimum distance from the original 𝑛
hotels to the new one is equal to 𝑑

.
Input

The first line contains two integers 𝑛
and 𝑑 (1≤𝑛≤100, 1≤𝑑≤109

) — the number of Sonya's hotels and the needed minimum distance from a new hotel to all others.

The second line contains 𝑛
different integers in strictly increasing order 𝑥1,𝑥2,…,𝑥𝑛 (−109≤𝑥𝑖≤109

) — coordinates of Sonya's hotels.
Output

Print the number of cities where Sonya can build a new hotel so that the minimum distance from this hotel to all others is equal to 𝑑

.
Examples
Input
Copy

4 3
-3 2 9 16

Output
Copy

6

Input
Copy

5 2
4 8 11 18 19

Output
Copy

5

Note

In the first example, there are 6
possible cities where Sonya can build a hotel. These cities have coordinates −6, 5, 6, 12, 13, and 19

.

In the second example, there are 5
possible cities where Sonya can build a hotel. These cities have coordinates 2, 6, 13, 16, and 21.
*///Chochu Singh
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
	
	ll n,d;	cin>>n>>d;
	vector<ll> v;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		v.push_back(num);
	}
	
    ll ans=2;
    
    for(ll i=1;i<n;i++)
    {
        ll mid=v[i]-d;
        if((v[i-1]+d)==mid)
            ans+=1;
        else if((v[i-1]+d)<mid)
            ans+=2;
    }
	
	cout<<ans<<endl;
	
	return 0;
}

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
	
	ll n,d;	cin>>n>>d;
	vector<ll> v;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		v.push_back(num);
	}
	
    ll ans=2;
    
    for(ll i=1;i<n;i++)
    {
        ll mid=v[i]-d;
        if((v[i-1]+d)==mid)
            ans+=1;
        else if((v[i-1]+d)<mid)
            ans+=2;
    }
	
	cout<<ans<<endl;
	
	return 0;
}
