/*DZY loves collecting special strings which only contain lowercase letters. For each lowercase letter c DZY knows its value wc. For each special string s = s1s2... s|s| (|s| is the length of the string) he represents its value with a function f(s), where

Now DZY has a string s. He wants to insert k lowercase letters into this string in order to get the largest possible value of the resulting string. Can you help him calculate the largest possible value he could get?
Input

The first line contains a single string s (1 ≤ |s| ≤ 103).

The second line contains a single integer k (0 ≤ k ≤ 103).

The third line contains twenty-six integers from wa to wz. Each such number is non-negative and doesn't exceed 1000.
Output

Print a single integer — the largest possible value of the resulting string DZY could get.
Examples
Input
Copy

abc
3
1 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Output
Copy

41

Note

In the test sample DZY can obtain "abcbbc", value = 1·1 + 2·2 + 3·2 + 4·2 + 5·2 + 6·2 = 41.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;   cin>>s;
	ll k;   cin>>k;
	ll max=INT_MIN;
	
	vector<ll>v;
	
	for(ll i=0;i<26;i++)
	{
	    ll num; cin>>num;
	    if(num>max)
	        max=num;
	    v.push_back(num);
	}
	
	//cout<<max<<endl;
	
    ll mul=1;
    ll ans=0;
    
    for(ll i=0;i<s.size();i++)
    {
        ll index=(s[i]-'a');
        //cout<<index<<" ";
        ans=ans+(mul*v[index]);
        mul++;
    }
    //cout<<endl;
    //cout<<ans<<endl;
    
    while(k!=0)
    {
        ans=ans+(mul*max);
        mul++;
        k--;
    }
    
    cout<<ans;
    
    
    return 0;
}
