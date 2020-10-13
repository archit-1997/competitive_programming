/*The records are expressed as a string s

of characters '0', '1' and '.', where '0' denotes a low tide, '1' denotes a high tide, and '.' denotes an unknown one (either high or low).

You are to help Mino determine whether it's possible that after replacing each '.' independently with '0' or '1', a given integer p

is not a period of the resulting string. In case the answer is yes, please also show such a replacement to Mino.

In this problem, a positive integer p
is considered a period of string s, if for all 1≤i≤|s|−p, the i-th and (i+p)-th characters of s are the same. Here |s| is the length of s

.
Input

The first line contains two space-separated integers n
and p (1≤p≤n≤2000

) — the length of the given string and the supposed period, respectively.

The second line contains a string s
of n characters — Mino's records. s

only contains characters '0', '1' and '.', and contains at least one '.' character.
Output

Output one line — if it's possible that p

is not a period of the resulting string, output any one of such strings; otherwise output "No" (without quotes, you can print letters in any case (upper or lower)).
Examples
Input
Copy

10 7
1.0.1.0.1.

Output
Copy

1000100010

Input
Copy

10 6
1.0.1.1000

Output
Copy

1001101000

Input
Copy

10 9
1........1

Output
Copy

No

Note

In the first example, 7
is not a period of the resulting string because the 1-st and 8

-th characters of it are different.

In the second example, 6
is not a period of the resulting string because the 4-th and 10

-th characters of it are different.

In the third example, 9

is always a period because the only constraint that the first and last characters are the same is already satisfied.

Note that there are multiple acceptable answers for the first two examples, you can print any of them.*/

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
	
	ll n,p;	cin>>n>>p;
	
	string s;   cin>>s;
	
	if(p>n)
	    cout<<"No";
	else
	{
	    ll flag=0,d=n-p;
	    
	    FOR(i,0,d)
	    {
	        if(s[i]=='.' && s[i+p]=='.')
	        {
	            flag=1;
	            s[i]='0',s[i+p]='1';
	        }
	        else if(s[i]=='.' || s[i+p]=='.')
	        {
	            flag=1;
	            if(s[i]=='.')
	            {
	                ll num=s[i+p]-'0';
	                s[i]=(1-num)+'0';
	            }
	            else
	            {
	                ll num=s[i]-'0';
	                s[i+p]=(1-num)+'0';
	            }
	        }
	        else if(s[i]!=s[i+p])
	            flag=1;
	        
	    }
	    
	    if(flag==0)
	        cout<<"No";
	    else
	    {
	        FOR(i,d,n)
	        {
	            if(s[i]=='.')
	                s[i]='0';
	        }
	        cout<<s<<endl;
	    }
	}
	
	
	return 0;
}
