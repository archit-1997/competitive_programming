Mr. Kitayuta has kindly given you a string s consisting of lowercase English letters. You are asked to insert exactly one lowercase English letter into s to make it a palindrome. A palindrome is a string that reads the same forward and backward. For example, "noon", "testset" and "a" are all palindromes, while "test" and "kitayuta" are not.

You can choose any lowercase English letter, and insert it to any position of s, possibly to the beginning or the end of s. You have to insert a letter even if the given string is already a palindrome.

If it is possible to insert one lowercase English letter into s so that the resulting string will be a palindrome, print the string after the insertion. Otherwise, print "NA" (without quotes, case-sensitive). In case there is more than one palindrome that can be obtained, you are allowed to print any of them.
Input

The only line of the input contains a string s (1 ≤ |s| ≤ 10). Each character in s is a lowercase English letter.
Output

/*If it is possible to turn s into a palindrome by inserting one lowercase English letter, print the resulting string in a single line. Otherwise, print "NA" (without quotes, case-sensitive). In case there is more than one solution, any of them will be accepted.
Examples
Input
Copy

revive

Output
Copy

reviver

Input
Copy

ee

Output
Copy

eye

Input
Copy

kitayuta

Output
Copy

NA

Note

For the first sample, insert 'r' to the end of "revive" to obtain a palindrome "reviver".

For the second sample, there is more than one solution. For example, "eve" will also be accepted.

For the third sample, it is not possible to turn "kitayuta" into a palindrome by just inserting one letter.
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
	
	string s;   cin>>s;
	
	ll n=s.size();
	
	for(ll i=0;i<=n;i++)
	{
	    for(ll j=0;j<=25;j++)
	    {
	        char ch='a'+j;
	        
	        string ins(1,ch);
	        
	        string f=s,b=s;
	        f.insert(i,ins);
	        b.insert(i,ins);
	        
	        reverse(b.begin(),b.end());
	        
	        if(f==b)
	        {
	            cout<<b;
	            return 0;
	        }
	    }
	}
	
	cout<<"NA";
	
	return 0;
}
