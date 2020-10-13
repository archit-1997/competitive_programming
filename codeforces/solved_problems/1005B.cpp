/*You are given two strings 𝑠 and 𝑡. In a single move, you can choose any of two strings and delete the first (that is, the leftmost) character. After a move, the length of the string decreases by 1

. You can't choose a string if it is empty.

For example:

    by applying a move to the string "where", the result is the string "here",
    by applying a move to the string "a", the result is an empty string "". 

You are required to make two given strings equal using the fewest number of moves. It is possible that, in the end, both strings will be equal to the empty string, and so, are equal to each other. In this case, the answer is obviously the sum of the lengths of the initial strings.

Write a program that finds the minimum number of moves to make two given strings 𝑠
and 𝑡

equal.
Input

The first line of the input contains 𝑠
. In the second line of the input contains 𝑡. Both strings consist only of lowercase Latin letters. The number of letters in each string is between 1 and 2⋅105

, inclusive.
Output

Output the fewest number of moves required. It is possible that, in the end, both strings will be equal to the empty string, and so, are equal to each other. In this case, the answer is obviously the sum of the lengths of the given strings.
Examples
Input
Copy

test
west

Output
Copy

2

Input
Copy

codeforces
yes

Output
Copy

9

Input
Copy

test
yes

Output
Copy

7

Input
Copy

b
ab

Output
Copy

1

Note

In the first example, you should apply the move once to the first string and apply the move once to the second string. As a result, both strings will be equal to "est".

In the second example, the move should be applied to the string "codeforces" 8
times. As a result, the string becomes "codeforces" → "es". The move should be applied to the string "yes" once. The result is the same string "yes" →

"es".

In the third example, you can make the strings equal only by completely deleting them. That is, in the end, both strings will be empty.

In the fourth example, the first character of the second string should be deleted.
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
	
	string s1,s2;   cin>>s1>>s2;
	
	ll l1=s1.size(),l2=s2.size();
	ll big=max(l1,l2);
	
	if(s1[l1-1]!=s2[l2-1])
	{
	    cout<<l1+l2;
	    return 0;
	}
	else
	{
	    ll count=0;
	    
	    ll n1=l1-1,n2=l2-1;
	    
	    while(n1>=0 && n2>=0)
	    {
	        if(s1[n1]!=s2[n2])
	        {
	            ll v1=l1-count,v2=l2-count;
	            cout<<v1+v2;
	            return 0;
	        }
	        else
	        {
	            n1--,n2--;
	            count++;
	        }
	    }
	    
	    ll v1=l1-count,v2=l2-count;
	    cout<<v1+v2;
	    return 0;
	}
	
	
	return 0;
}
