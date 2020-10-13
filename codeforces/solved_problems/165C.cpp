/*A string is binary, if it consists only of characters "0" and "1".

String v is a substring of string w if it has a non-zero length and can be read starting from some position in string w. For example, string "010" has six substrings: "0", "1", "0", "01", "10", "010". Two substrings are considered different if their positions of occurrence are different. So, if some string occurs multiple times, we should consider it the number of times it occurs.

You are given a binary string s. Your task is to find the number of its substrings, containing exactly k characters "1".
Input

The first line contains the single integer k (0 ≤ k ≤ 106). The second line contains a non-empty binary string s. The length of s does not exceed 106 characters.
Output

Print the single number — the number of substrings of the given string, containing exactly k characters "1".

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.
Examples
Input
Copy

1
1010

Output
Copy

6

Input
Copy

2
01010

Output
Copy

4

Input
Copy

100
01010

Output
Copy

0

Note

In the first sample the sought substrings are: "1", "1", "10", "01", "10", "010".

In the second sample the sought substrings are: "101", "0101", "1010", "01010".
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
	
	ll k;   cin>>k;
	string s;   cin>>s;
	
	ll n=s.size(),ans=0;
	
	unordered_map<ll,ll> m;
	
	ll sum=0;
	
	for(ll i=0;i<n;i++)
	{
	    sum+=s[i]-'0';
	    if(sum==k)
	        ans++;
	    if(m.find(sum-k)!=m.end())
	        ans+=m[sum-k];
	    m[sum]++;
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}
