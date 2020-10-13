/*A string is a palindrome if it reads the same from the left to the right and from the right to the left. For example, the strings "kek", "abacaba", "r" and "papicipap" are palindromes, while the strings "abb" and "iq" are not.

A substring s[l…r]
(1 ≤ l ≤ r ≤ |s|) of a string s = s1s2…s|s| is the string slsl + 1…sr

.

Anna does not like palindromes, so she makes her friends call her Ann. She also changes all the words she reads in a similar way. Namely, each word s
is changed into its longest substring that is not a palindrome. If all the substrings of s

are palindromes, she skips the word at all.

Some time ago Ann read the word s

. What is the word she changed it into?
Input

The first line contains a non-empty string s
with length at most 50

characters, containing lowercase English letters only.
Output

If there is such a substring in s
that is not a palindrome, print the maximum length of such a substring. Otherwise print 0

.

Note that there can be multiple longest substrings that are not palindromes, but their length is unique.
Examples
Input
Copy

mew

Output
Copy

3

Input
Copy

wuffuw

Output
Copy

5

Input
Copy

qqqqqqqq

Output
Copy

0

Note

"mew" is not a palindrome, so the longest substring of it that is not a palindrome, is the string "mew" itself. Thus, the answer for the first example is 3

.

The string "uffuw" is one of the longest non-palindrome substrings (of length 5
) of the string "wuffuw", so the answer for the second example is 5

.

All substrings of the string "qqqqqqqq" consist of equal characters so they are palindromes. This way, there are no non-palindrome substrings. Thus, the answer for the third example is 0

*/

//Archit Singh
//20168018
//Bachelor Of Technology
//Information Technology
//Motilal Nehru National Institute Of Technology

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll ispal(string s)
{
    ll l=0,r=s.size()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
            return 0;
        l++,r--;
    }
    
    return 1;
}

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    string s;   cin>>s;
    ll l=s.size();
    int ans=INT_MIN;
    for(ll i=0;i<l;i++)
    {
        for(int len =1;len<=l-i;len++)
        {
            string str=s.substr(i,len);
            if(!ispal(str))
            {
                //cout<<str<<endl;
                ans=max(ans,len);
            }
        }
            
    }
    
    if(ans==INT_MIN)
        cout<<0<<endl;
    else
        cout<<ans<<endl;
	
	return 0;
}
.
