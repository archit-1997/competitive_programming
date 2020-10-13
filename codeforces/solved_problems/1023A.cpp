/*You are given two strings 𝑠 and 𝑡. The string 𝑠 consists of lowercase Latin letters and at most one wildcard character '*', the string 𝑡 consists only of lowercase Latin letters. The length of the string 𝑠 equals 𝑛, the length of the string 𝑡 equals 𝑚

.

The wildcard character '*' in the string 𝑠
(if any) can be replaced with an arbitrary sequence (possibly empty) of lowercase Latin letters. No other character of 𝑠 can be replaced with anything. If it is possible to replace a wildcard character '*' in 𝑠 to obtain a string 𝑡, then the string 𝑡 matches the pattern 𝑠

.

For example, if 𝑠=

"aba*aba" then the following strings match it "abaaba", "abacaba" and "abazzzaba", but the following strings do not match: "ababa", "abcaaba", "codeforces", "aba1aba", "aba?aba".

If the given string 𝑡
matches the given string 𝑠

, print "YES", otherwise print "NO".
Input

The first line contains two integers 𝑛
and 𝑚 (1≤𝑛,𝑚≤2⋅105) — the length of the string 𝑠 and the length of the string 𝑡

, respectively.

The second line contains string 𝑠
of length 𝑛

, which consists of lowercase Latin letters and at most one wildcard character '*'.

The third line contains string 𝑡
of length 𝑚

, which consists only of lowercase Latin letters.
Output

Print "YES" (without quotes), if you can obtain the string 𝑡
from the string 𝑠

. Otherwise print "NO" (without quotes).
Examples
Input
Copy

6 10
code*s
codeforces

Output
Copy

YES

Input
Copy

6 5
vk*cup
vkcup

Output
Copy

YES

Input
Copy

1 1
v
k

Output
Copy

NO

Input
Copy

9 6
gfgf*gfgf
gfgfgf

Output
Copy

NO

Note

In the first example a wildcard character '*' can be replaced with a string "force". So the string 𝑠

after this replacement is "codeforces" and the answer is "YES".

In the second example a wildcard character '*' can be replaced with an empty string. So the string 𝑠

after this replacement is "vkcup" and the answer is "YES".

There is no wildcard character '*' in the third example and the strings "v" and "k" are different so the answer is "NO".

In the fourth example there is no such replacement of a wildcard character '*' that you can obtain the string 𝑡
so the answer is "NO".
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
	
	ll ls,lt;   cin>>ls>>lt;
	string s,t; cin>>s>>t;
	
	if(s==t)
	    cout<<"YES";
	else
	{
	    ll i;
	   for(i=0;i<ls;i++)
	   {
	       if(s[i]=='*')
	        break;
	       
	       if(s[i]!=t[i])
	       {
	           cout<<"NO";
	           return 0;
	       }
	   }
	       
	       if(i==ls-1)
	       {
	           cout<<"YES";
	           return 0;
	       }
	       
	       ll index=i;
	       //cout<<"index-->"<<index<<endl;
	       
	       lt--;
	       ls--;
	       //cout<<"ls"<<ls<<"lt"<<lt<<endl;
	       while(ls>index && lt>=index)
	       {
	           if(s[ls]!=t[lt])
	           {
	               cout<<"NO";
	               return 0;
	           }
	           ls--;
	           lt--;
	       }
	       
	       if(ls==index)
	        cout<<"YES";
	       else
	        cout<<"NO";
	       
	}
	
	return 0;
}
