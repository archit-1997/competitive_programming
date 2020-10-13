/*You are given a ternary string (it is a string which consists only of characters '0', '1' and '2').

You can swap any two adjacent (consecutive) characters '0' and '1' (i.e. replace "01" with "10" or vice versa) or any two adjacent (consecutive) characters '1' and '2' (i.e. replace "12" with "21" or vice versa).

For example, for string "010210" we can perform the following moves:

    "010210" →

"100210";
"010210" →
"001210";
"010210" →
"010120";
"010210" →

    "010201". 

Note than you cannot swap "02" →

"20" and vice versa. You cannot perform any other operations with the given string excluding described above.

You task is to obtain the minimum possible (lexicographically) string by using these swaps arbitrary number of times (possibly, zero).

String a
is lexicographically less than string b (if strings a and b have the same length) if there exists some position i (1≤i≤|a|, where |s| is the length of the string s) such that for every j<i holds aj=bj, and ai<bi

.
Input

The first line of the input contains the string s
consisting only of characters '0', '1' and '2', its length is between 1 and 105

(inclusive).
Output

Print a single string — the minimum possible (lexicographically) string you can obtain by using the swaps described above arbitrary number of times (possibly, zero).
Examples
Input
Copy

100210

Output
Copy

001120

Input
Copy

11222121

Output
Copy

11112222

Input
Copy

20

Output
Copy

20
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
	
	string s;   cin>>s;
	ll c=0,n=s.size();
	string ans;
	FOR(i,0,n)
	{
	    if(s[i]!='1')
	        ans=ans+s[i];
	    else
	        c++;
	}
	
	ll i=0;
	n=ans.size();
	while(ans[i]=='0' && i<n)
	{
	    cout<<0;
	    i++;
	}
	while(c--)
	    cout<<1;
	while(i<n)
	{
	    cout<<ans[i];
	    i++;
	}
	
	
	return 0;
}
