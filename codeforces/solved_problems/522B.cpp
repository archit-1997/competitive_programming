/*One day n friends met at a party, they hadn't seen each other for a long time and so they decided to make a group photo together.

Simply speaking, the process of taking photos can be described as follows. On the photo, each photographed friend occupies a rectangle of pixels: the i-th of them occupies the rectangle of width wi pixels and height hi pixels. On the group photo everybody stands in a line, thus the minimum pixel size of the photo including all the photographed friends, is W × H, where W is the total sum of all widths and H is the maximum height of all the photographed friends.

As is usually the case, the friends made n photos — the j-th (1 ≤ j ≤ n) photo had everybody except for the j-th friend as he was the photographer.

Print the minimum size of each made photo in pixels.
Input

The first line contains integer n (2 ≤ n ≤ 200 000) — the number of friends.

Then n lines follow: the i-th line contains information about the i-th friend. The line contains a pair of integers wi, hi (1 ≤ wi ≤ 10, 1 ≤ hi ≤ 1000) — the width and height in pixels of the corresponding rectangle.
Output

Print n space-separated numbers b1, b2, ..., bn, where bi — the total number of pixels on the minimum photo containing all friends expect for the i-th one.
Examples
Input
Copy

3
1 10
5 5
10 1

Output
Copy

75 110 60 

Input
Copy

3
2 1
1 2
2 1

Output
Copy

6 4 6 
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
	
	ll n;	cin>>n;
	vector<pair<ll,ll>> v;
	ll ws=0;
	
	//max--second max
	ll h1=INT_MIN,h2=INT_MIN;

	for(ll i=0;i<n;i++)
	{
		ll a,b; cin>>a>>b;
		ws+=a;
		if(b>h1)
		{
		    h2=h1;
		    h1=b;
		}
		else if(b>h2)
		    h2=b;
		
		v.push_back({a,b});
	}
	
	for(ll i=0;i<n;i++)
	{
	    ll ans=0;
	    if(v[i].second==h1)
	        ans=(ws-v[i].first)*h2;
	    else
	        ans=(ws-v[i].first)*h1;
	   
	    cout<<ans<<endl;
	}
	
	
	
	return 0;
}
