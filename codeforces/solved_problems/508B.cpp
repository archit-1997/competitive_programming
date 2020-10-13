/*Berland, 2016. The exchange rate of currency you all know against the burle has increased so much that to simplify the calculations, its fractional part was neglected and the exchange rate is now assumed to be an integer.

Reliable sources have informed the financier Anton of some information about the exchange rate of currency you all know against the burle for tomorrow. Now Anton knows that tomorrow the exchange rate will be an even number, which can be obtained from the present rate by swapping exactly two distinct digits in it. Of all the possible values that meet these conditions, the exchange rate for tomorrow will be the maximum possible. It is guaranteed that today the exchange rate is an odd positive integer n. Help Anton to determine the exchange rate of currency you all know for tomorrow!
Input

The first line contains an odd positive integer n — the exchange rate of currency you all know for today. The length of number n's representation is within range from 2 to 105, inclusive. The representation of n doesn't contain any leading zeroes.
Output

If the information about tomorrow's exchange rate is inconsistent, that is, there is no integer that meets the condition, print  - 1.

Otherwise, print the exchange rate of currency you all know against the burle for tomorrow. This should be the maximum possible number of those that are even and that are obtained from today's exchange rate by swapping exactly two digits. Exchange rate representation should not contain leading zeroes.
Examples
Input
Copy

527

Output
Copy

572

Input
Copy

4573

Output
Copy

3574

Input
Copy

1357997531

Output
Copy

-1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;   cin>>s;
    ll n=s.size()-1;
    ll last=s[n],index=-1;
    
    ll flag=0;
    
    for(ll i=0;i<n;i++)
    {
        ll num=s[i]-'0';
        
        if(num%2==0)
        {
            if(index==-1)
            {
                flag=1;
                index=i;
            }
            else if(last<s[index])
                index=i;
        }
    }
    
    swap(s[index],s[n]);
    
    if(!flag)
        cout<<-1;
    else
        cout<<s;
    
    return 0;
}
