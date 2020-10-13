/*Igor has fallen in love with Tanya. Now Igor wants to show his feelings and write a number on the fence opposite to Tanya's house. Igor thinks that the larger the number is, the more chance to win Tanya's heart he has.

Unfortunately, Igor could only get v liters of paint. He did the math and concluded that digit d requires ad liters of paint. Besides, Igor heard that Tanya doesn't like zeroes. That's why Igor won't use them in his number.

Help Igor find the maximum number he can write on the fence.
Input

The first line contains a positive integer v (0 ≤ v ≤ 106). The second line contains nine positive integers a1, a2, ..., a9 (1 ≤ ai ≤ 105).
Output

Print the maximum number Igor can write on the fence. If he has too little paint for any digit (so, he cannot write anything), print -1.
Examples
Input
Copy

5
5 4 3 2 1 2 3 4 5

Output
Copy

55555

Input
Copy

2
9 11 1 12 5 8 9 10 6

Output
Copy

33

Input
Copy

0
1 1 1 1 1 1 1 1 1

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
    
    ll n;   cin>>n;
    vector<ll> v;

    for(ll i=0;i<9;i++)
    {
        ll num;cin>>num;
        v.push_back(num);
    }
    
    ll small=*min_element(v.begin(),v.end());
    //cout<<small<<endl;
    
    ll len=n/small;
    
    if(len==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    while(len--)
    {
        for(ll i=8;i>=0;i--)
        {
            if((n-v[i])/small==len && n>=v[i])
            {
                cout<<i+1;
                n=n-v[i];
                break;
            }
        }
    }
    
    cout<<endl;
    
    return 0;
}
