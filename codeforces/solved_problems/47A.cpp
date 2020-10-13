/*A triangular number is the number of dots in an equilateral triangle uniformly filled with dots. For example, three dots can be arranged in a triangle; thus three is a triangular number. The n-th triangular number is the number of dots in a triangle with n dots on a side. . You can learn more about these numbers from Wikipedia (http://en.wikipedia.org/wiki/Triangular_number).

Your task is to find out if a given integer is a triangular number.
Input

The first line contains the single number n (1 ≤ n ≤ 500) — the given integer.
Output

If the given integer is a triangular number output YES, otherwise output NO.
Examples
Input
Copy

1

Output
Copy

YES

Input
Copy

2

Output
Copy

NO

Input
Copy

3

Output
Copy

YES
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
	
	unordered_map<ll,ll> hash;
	
	ll num=1;
	
	ll val=2;
	
	while(num<=500)
	{
	    hash[num]=1;
	    num+=val;
	    val++;
	}
	
	ll n;	cin>>n;
	
	if(hash[n])
	    cout<<"YES";
	else
	    cout<<"NO";
	
	return 0;
}
