/*As technologies develop, manufacturers are making the process of unlocking a phone as user-friendly as possible. To unlock its new phone, Arkady's pet dog Mu-mu has to bark the password once. The phone represents a password as a string of two lowercase English letters.

Mu-mu's enemy Kashtanka wants to unlock Mu-mu's phone to steal some sensible information, but it can only bark n distinct words, each of which can be represented as a string of two lowercase English letters. Kashtanka wants to bark several words (not necessarily distinct) one after another to pronounce a string containing the password as a substring. Tell if it's possible to unlock the phone in this way, or not.
Input

The first line contains two lowercase English letters — the password on the phone.

The second line contains single integer n (1 ≤ n ≤ 100) — the number of words Kashtanka knows.

The next n lines contain two lowercase English letters each, representing the words Kashtanka knows. The words are guaranteed to be distinct.
Output

Print "YES" if Kashtanka can bark several words in a line forming a string containing the password, and "NO" otherwise.

You can print each letter in arbitrary case (upper or lower).
Examples
Input
Copy

ya
4
ah
oy
to
ha

Output
Copy

YES

Input
Copy

hp
2
ht
tp

Output
Copy

NO

Input
Copy

ah
1
ha

Output
Copy

YES

Note

In the first example the password is "ya", and Kashtanka can bark "oy" and then "ah", and then "ha" to form the string "oyahha" which contains the password. So, the answer is "YES".

In the second example Kashtanka can't produce a string containing password as a substring. Note that it can bark "ht" and then "tp" producing "http", but it doesn't contain the password "hp" as a substring.

In the third example the string "hahahaha" contains "ah" as a substring.
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
	
	string p;   cin>>p;
	
	ll  n;  cin>>n;
	ll flag=0;
	vector<string> v;
	for(ll i=0;i<n;i++)
	{
	    string str; cin>>str;
	    if(str==p)
	        flag=1;
	    v.push_back(str);
	}
	
	if(flag==1)
	    cout<<"YES"<<endl;
    else
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                string s1=v[i];
                string s2=v[j];
                //cout<<s1<<" "<<s2<<endl;
                char c1=s1[0],c2=s2[1];
                //cout<<c1<<" "<<c2<<endl;
                string check="";
                check=check+c2;
                check=check+c1;
                //cout<<check<<endl;
                if(check==p)
                {
                    cout<<"YES";
                    return 0;
                }
            }
        }
        
        cout<<"NO"<<endl;
    }
	
	return 0;
}
