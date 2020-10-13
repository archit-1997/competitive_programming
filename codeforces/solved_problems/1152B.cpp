/*Cat Furrier Transform is a popular algorithm among cat programmers to create longcats. As one of the greatest cat programmers ever exist, Neko wants to utilize this algorithm to create the perfect longcat.

Assume that we have a cat with a number x
. A perfect longcat is a cat with a number equal 2m−1 for some non-negative integer m. For example, the numbers 0, 1, 3, 7, 15

and so on are suitable for the perfect longcats.

In the Cat Furrier Transform, the following operations can be performed on x

:

    (Operation A): you select any non-negative integer n

and replace x with x⊕(2n−1), with ⊕
being a bitwise XOR operator.
(Operation B): replace x
with x+1

    . 

The first applied operation must be of type A, the second of type B, the third of type A again, and so on. Formally, if we number operations from one in the order they are executed, then odd-numbered operations must be of type A and the even-numbered operations must be of type B.

Neko wants to produce perfect longcats at industrial scale, thus for each cat Neko only wants to perform at most 40

operations. Can you help Neko writing a transformation plan?

Note that it is not required to minimize the number of operations. You just need to use no more than 40

operations.
Input

The only line contains a single integer x
(1≤x≤106

).
Output

The first line should contain a single integer t
(0≤t≤40

) — the number of operations to apply.

Then for each odd-numbered operation print the corresponding number ni
in it. That is, print ⌈t2⌉ integers ni (0≤ni≤30), denoting the replacement x with x⊕(2ni−1)

in the corresponding step.

If there are multiple possible answers, you can print any of them. It is possible to show, that there is at least one answer in the constraints of this problem.
Examples
Input
Copy

39

Output
Copy

4
5 3 

Input
Copy

1

Output
Copy

0

Input
Copy

7

Output
Copy

0

Note

In the first test, one of the transforms might be as follows: 39→56→57→62→63

. Or more precisely:

    Pick n=5

. x is transformed into 39⊕31, or 56
.
Increase x
by 1, changing its value to 57
.
Pick n=3
. x is transformed into 57⊕7, or 62
.
Increase x
by 1, changing its value to 63=26−1

    . 

In the second and third test, the number already satisfies the goal requirement.
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

string binary(ll n)
{
    string ans;
    
    while(n!=0)
    {
        ans=ans+to_string(n%2);
        n/=2;
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}

int main()
{
	FAST;
	
	ll n;	cin>>n;
	
	if((n&(n+1))==0)
	{
	    cout<<0;
	    return 0;
	}
	
	if(__builtin_popcount(n)==1)
	{
	    string s=binary(n);
	    ll len=s.size();
	    ll pos;
	    FOR(i,0,len)
	    {
	        if(s[i]=='0')
	        {
	            pos=i;
	            break;
	        }
	    }
	    
	    pos=len-pos;
	    cout<<1<<endl;
	    cout<<pos;
	    return 0;
	}
	else
	{
	    ll ans=0;
	    V v;
	    while(1)
	    {
	        if((n&(n+1))==0)    
	            break;
	        
	        if(__builtin_popcount(n)==1)
	        {
	            string s=binary(n);
	            ll len=s.size();
	            ll pos;
	            FOR(i,0,len)
	            {
	                if(s[i]=='0')
	                {
	                    pos=i;
	                    break;
	                }
	            }
	    
	            pos=len-pos;
	            v.pb(pos);
	            ans++;
	            break;
	        }
	        else
	        {
	            string s=binary(n);
	            ll len=s.size();
	            ll pos;
	            FOR(i,0,len)
	            {
	                if(s[i]=='1')
	                {
	                    pos=i;
	                    break;
	                }
	            }
	    
	            pos=len-pos;
	            ll num=pow(2,pos);
	            num--;
	            n=n^num;
	            ans++;
	            v.pb(pos);
	            if((n&(n+1))==0)    
	                break;
	            else
	            {
	                n++;
	                ans++;
	            }
	        }
	    }
	    
	    cout<<ans<<endl;
	    
	    for(ll i=0;i<v.size();i++)
	        cout<<v[i]<<" ";
	}
	
	return 0;
}
