/*You are given two very long integers a, b (leading zeroes are allowed). You should check what number a or b is greater or determine that they are equal.

The input size is very large so don't use the reading of symbols one by one. Instead of that use the reading of a whole line or token.

As input/output can reach huge size it is recommended to use fast input/output methods: for example, prefer to use scanf/printf instead of cin/cout in C++, prefer to use BufferedReader/PrintWriter instead of Scanner/System.out in Java. Don't use the function input() in Python2 instead of it use the function raw_input().
Input

The first line contains a non-negative integer a.

The second line contains a non-negative integer b.

The numbers a, b may contain leading zeroes. Each of them contains no more than 106 digits.
Output

Print the symbol "<" if a < b and the symbol ">" if a > b. If the numbers are equal print the symbol "=".
Examples
Input
Copy

9
10

Output
Copy

<

Input
Copy

11
10

Output
Copy

>

Input
Copy

00012345
12345

Output
Copy

=

Input
Copy

0123
9

Output
Copy

>

Input
Copy

0123
111

Output
Copy

>
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
	
	string a,b; cin>>a>>b;
	
	ll i=0,j=0;
	
	ll la=a.size(),lb=b.size();
	
	while(i<la && a[i]=='0')
	    i++;
	    
	while(j<lb && b[j]=='0')
	    j++;
	    
	if(i==la && j==lb)
	    cout<<"=";
	else if(i==la)
	    cout<<"<";
	else if(j==lb)
	    cout<<">";
	else
	{
	    ll lena=la-i;
	    ll lenb=lb-j;
	    
	    if(lena>lenb)
	        cout<<">";
	    else if(lena<lenb)
	        cout<<"<";
	    else
	    {
	        while(i<la && j<lb)
	        {
	            ll num1=a[i]-'0';
	            ll num2=b[j]-'0';
	            
	            if(num1>num2)
	            {
	                cout<<">";
	                return 0;
	            }
	            else if(num1<num2)
	            {
	                cout<<"<";
	                return 0;
	            }
	            else
	            {
	                i++;
	                j++;
	            }
	        }
	        
	        cout<<"=";
	    }
	}
	
	return 0;
}
