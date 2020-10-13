/*Haiku is a genre of Japanese traditional poetry.

A haiku poem consists of 17 syllables split into three phrases, containing 5, 7 and 5 syllables correspondingly (the first phrase should contain exactly 5 syllables, the second phrase should contain exactly 7 syllables, and the third phrase should contain exactly 5 syllables). A haiku masterpiece contains a description of a moment in those three phrases. Every word is important in a small poem, which is why haiku are rich with symbols. Each word has a special meaning, a special role. The main principle of haiku is to say much using a few words.

To simplify the matter, in the given problem we will consider that the number of syllable in the phrase is equal to the number of vowel letters there. Only the following letters are regarded as vowel letters: "a", "e", "i", "o" and "u".

Three phases from a certain poem are given. Determine whether it is haiku or not.
Input

The input data consists of three lines. The length of each line is between 1 and 100, inclusive. The i-th line contains the i-th phrase of the poem. Each phrase consists of one or more words, which are separated by one or more spaces. A word is a non-empty sequence of lowercase Latin letters. Leading and/or trailing spaces in phrases are allowed. Every phrase has at least one non-space character. See the example for clarification.
Output

Print "YES" (without the quotes) if the poem is a haiku. Otherwise, print "NO" (also without the quotes).
Examples
Input
Copy

on  codeforces 
beta round is running
   a rustling of keys 

Output
Copy

YES

Input
Copy

how many gallons
of edo s rain did you drink
                                cuckoo

Output
Copy

NO
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
	
	vector<string> v(3);
	
	for(ll i=0;i<3;i++)
	{
	    string s;   getline(cin,s);
	    v[i]=s;
	}
	
	for(ll i=0;i<3;i++)
	{
	    ll count=0;
	    string str=v[i];
	    
	    for(ll j=0;j<str.size();j++)
	    {
	        if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u')
	            count++;
	    }
	    if(i==0 && count!=5)
	    {
	        cout<<"NO";
	        return 0;
	    }
	    else if(i==1 && count!=7)
	    {
	        cout<<"NO";
	        return 0;
	    }
	    else if(i==2 && count!=5)
	    {
	        cout<<"NO";
	        return 0;
	    }
	}
	
	cout<<"YES";
	
	
	return 0;
}

