/*You are given a string 𝑠, consisting of 𝑛

lowercase Latin letters.

A substring of string 𝑠
is a continuous segment of letters from 𝑠

. For example, "defor" is a substring of "codeforces" and "fors" is not.

The length of the substring is the number of letters in it.

Let's call some string of length 𝑛
diverse if and only if there is no letter to appear strictly more than 𝑛2

times. For example, strings "abc" and "iltlml" are diverse and strings "aab" and "zz" are not.

Your task is to find any diverse substring of string 𝑠

or report that there is none. Note that it is not required to maximize or minimize the length of the resulting substring.
Input

The first line contains a single integer 𝑛
(1≤𝑛≤1000) — the length of string 𝑠

.

The second line is the string 𝑠
, consisting of exactly 𝑛

lowercase Latin letters.
Output

Print "NO" if there is no diverse substring in the string 𝑠

.

Otherwise the first line should contain "YES". The second line should contain any diverse substring of string 𝑠

.
Examples
Input
Copy

10
codeforces

Output
Copy

YES
code

Input
Copy

5
aaaaa

Output
Copy

NO

Note

The first example has lots of correct answers.

Please, restrain yourself from asking if some specific answer is correct for some specific test or not, these questions always lead to "No comments" answer.
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

	string s;   cin>>s;
    
    ll flag=0;
    
    if(n==1)
        cout<<"NO";
    else
    {
        ll flag=0;
        char ch=s[0];
        
        for(ll i=1;i<n;i++)
        {
            if(s[i]!=ch)
            {
                flag=1;
                break;
            }
        }
        
        if(flag)
        {
            cout<<"YES"<<endl;
            string ans;
            
            for(ll i=0;i<n-1;i++)
            {
                if(s[i]!=s[i+1])
                {
                    ans=ans+s[i]+s[i+1];
                    break;
                }
            }
            cout<<ans;
        }
        else
            cout<<"NO";
    }
	
	return 0;
}
