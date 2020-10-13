/*Vasily has a number a, which he wants to turn into a number b. For this purpose, he can do two types of operations:

    multiply the current number by 2 (that is, replace the number x by 2·x);
    append the digit 1 to the right of current number (that is, replace the number x by 10·x + 1). 

You need to help Vasily to transform the number a into the number b using only the operations described above, or find that it is impossible.

Note that in this task you are not required to minimize the number of operations. It suffices to find any way to transform a into b.
Input

The first line contains two positive integers a and b (1 ≤ a < b ≤ 109) — the number which Vasily has and the number he wants to have.
Output

If there is no way to get b from a, print "NO" (without quotes).

Otherwise print three lines. On the first line print "YES" (without quotes). The second line should contain single integer k — the length of the transformation sequence. On the third line print the sequence of transformations x1, x2, ..., xk, where:

    x1 should be equal to a,
    xk should be equal to b,
    xi should be obtained from xi - 1 using any of two described operations (1 < i ≤ k). 

If there are multiple answers, print any of them.
Examples
Input
Copy

2 162

Output
Copy

YES
5
2 4 8 81 162 

Input
Copy

4 42

Output
Copy

NO

Input
Copy

100 40021

Output
Copy

YES
5
100 200 2001 4002 40021 

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a,b;
    cin>>a>>b;
    vector<ll> v;
    v.push_back(b);
    
    while(1)
    {
        if(b<a)
            break;
        if(b==a)
        {
            cout<<"YES"<<endl;
            break;
        }
        if(b%10==1)
        {
            v.push_back(b/10);
            b=b/10;
        }
        else if(b%2==0)
        {
            v.push_back(b/2);
            b/=2;
        }
        else
            break;
    }
    
    if(b==a)
    {
        //cout<<"YES"<<endl
        cout<<v.size()<<endl;
        reverse(v.begin(),v.end());
        for(ll i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
    else
        cout<<"NO"<<endl;
    
    return 0;
}
