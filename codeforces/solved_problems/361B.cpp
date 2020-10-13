/*Levko loves permutations very much. A permutation of length n is a sequence of distinct positive integers, each is at most n.

Let’s assume that value gcd(a, b) shows the greatest common divisor of numbers a and b. Levko assumes that element pi of permutation p1, p2, ... , pn is good if gcd(i, pi) > 1. Levko considers a permutation beautiful, if it has exactly k good elements. Unfortunately, he doesn’t know any beautiful permutation. Your task is to help him to find at least one of them.
Input

The single line contains two integers n and k (1 ≤ n ≤ 105, 0 ≤ k ≤ n).
Output

In a single line print either any beautiful permutation or -1, if such permutation doesn’t exist.

If there are multiple suitable permutations, you are allowed to print any of them.
Examples
Input
Copy

4 2

Output
Copy

2 4 3 1

Input
Copy

1 1

Output
Copy

-1

Note

In the first sample elements 4 and 3 are good because gcd(2, 4) = 2 > 1 and gcd(3, 3) = 3 > 1. Elements 2 and 1 are not good because gcd(1, 2) = 1 and gcd(4, 1) = 1. As there are exactly 2 good elements, the permutation is beautiful.

The second sample has no beautiful permutations.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;   cin>>n>>k;
    
    if(k>=n)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        for(ll i=1;i<=n-k-1;i++)
            cout<<i+1<<" ";
        cout<<"1 ";
        for(ll i=n-k+1;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
    }
    
    return 0;
}
