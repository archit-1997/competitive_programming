/*You are given a string 𝑠 consisting of 𝑛 lowercase Latin letters. 𝑛

is even.

For each position 𝑖
(1≤𝑖≤𝑛) in string 𝑠

you are required to change the letter on this position either to the previous letter in alphabetic order or to the next one (letters 'a' and 'z' have only one of these options). Letter in every position must be changed exactly once.

For example, letter 'p' should be changed either to 'o' or to 'q', letter 'a' should be changed to 'b' and letter 'z' should be changed to 'y'.

That way string "codeforces", for example, can be changed to "dpedepqbft" ('c' →
'd', 'o' → 'p', 'd' → 'e', 'e' → 'd', 'f' → 'e', 'o' → 'p', 'r' → 'q', 'c' → 'b', 'e' → 'f', 's' →

't').

String 𝑠

is called a palindrome if it reads the same from left to right and from right to left. For example, strings "abba" and "zz" are palindromes and strings "abca" and "zy" are not.

Your goal is to check if it's possible to make string 𝑠
a palindrome by applying the aforementioned changes to every position. Print "YES" if string 𝑠

can be transformed to a palindrome and "NO" otherwise.

Each testcase contains several strings, for each of them you are required to solve the problem separately.
Input

The first line contains a single integer 𝑇
(1≤𝑇≤50

) — the number of strings in a testcase.

Then 2𝑇
lines follow — lines (2𝑖−1) and 2𝑖 of them describe the 𝑖-th string. The first line of the pair contains a single integer 𝑛 (2≤𝑛≤100, 𝑛 is even) — the length of the corresponding string. The second line of the pair contains a string 𝑠, consisting of 𝑛

lowercase Latin letters.
Output

Print 𝑇
lines. The 𝑖-th line should contain the answer to the 𝑖-th string of the input. Print "YES" if it's possible to make the 𝑖

-th string a palindrome by applying the aforementioned changes to every position. Print "NO" otherwise.
Example
Input
Copy

5
6
abccba
2
cf
4
adfa
8
abaazaba
2
ml

Output
Copy

YES
NO
YES
NO
NO

Note

The first string of the example can be changed to "bcbbcb", two leftmost letters and two rightmost letters got changed to the next letters, two middle letters got changed to the previous letters.

The second string can be changed to "be", "bg", "de", "dg", but none of these resulting strings are palindromes.

The third string can be changed to "beeb" which is a palindrome.

The fifth string can be changed to "lk", "lm", "nk", "nm", but none of these resulting strings are palindromes. Also note that no letter can remain the same, so you can't obtain strings "ll" or "mm".
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
	
	ll t;   cin>>t;
	
	while(t--)
	{
	
	ll n;   cin>>n;
	string s;   cin>>s;
	
	vector<ll> ans(n);
	
	for(ll i=0;i<n;i++)
	{
	    int num=(int)s[i];
	    num=num-96;
	    ans[i]=num;
	}
	
	ll l=0,r=n-1,flag=0;
	while(l<r)
	{
	    if(ans[l]==ans[r])
	    {
	        l++;
	        r--;
	    }
	    else
	    {
	        ll n1=ans[l]-'0',n2=ans[r]-'0';
	        if(abs(n1-n2)!=2)
	        {
	            flag=1;
	            cout<<"NO"<<endl;
	            break;
	        }
	        else
	        {
	            l++,r--;
	        }
	    }
	}
	if(!flag)
	cout<<"YES"<<endl;
	}
	
	
	
	return 0;
}
