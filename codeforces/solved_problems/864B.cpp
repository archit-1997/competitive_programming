/*Polycarp loves lowercase letters and dislikes uppercase ones. Once he got a string s consisting only of lowercase and uppercase Latin letters.

Let A be a set of positions in the string. Let's call it pretty if following conditions are met:

    letters on positions from A in the string are all distinct and lowercase;
    there are no uppercase letters in the string which are situated between positions from A (i.e. there is no such j that s[j] is an uppercase letter, and a1 < j < a2 for some a1 and a2 from A). 

Write a program that will determine the maximum number of elements in a pretty set of positions.
Input

The first line contains a single integer n (1 ≤ n ≤ 200) — length of string s.

The second line contains a string s consisting of lowercase and uppercase Latin letters.
Output

Print maximum number of elements in pretty set of positions for string s.
Examples
Input
Copy

11
aaaaBaabAbA

Output
Copy

2

Input
Copy

12
zACaAbbaazzC

Output
Copy

3

Input
Copy

3
ABC

Output
Copy

0

Note

In the first example the desired positions might be 6 and 8 or 7 and 8. Positions 6 and 7 contain letters 'a', position 8 contains letter 'b'. The pair of positions 1 and 8 is not suitable because there is an uppercase letter 'B' between these position.

In the second example desired positions can be 7, 8 and 11. There are other ways to choose pretty set consisting of three elements.

In the third example the given string s does not contain any lowercase letters, so the answer is 0.
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
	
	string s;   cin>>s;
	
	ll ans=0;
	
	FOR(i,0,n)
	{
	    if(s[i]>='A' && s[i]<='Z')
	        continue;
	    else
	    {
	        ll count=0;
	        unordered_map<char,ll> hash;
	        
	        while(i<n)
	        {
	            if(s[i]>='A' && s[i]<='Z')
	                break;
	            if(hash[s[i]]==0)
	            {
	                count++;
	                hash[s[i]]=1;
	            }
	            i++;
	        }
	        ans=max(ans,count);
	        //i++;
	    }
	}
	
	cout<<ans;
	
	return 0;
}
