/*When Valera has got some free time, he goes to the library to read some books. Today he's got t free minutes to read. That's why Valera took n books in the library and for each book he estimated the time he is going to need to read it. Let's number the books by integers from 1 to n. Valera needs ai minutes to read the i-th book.

Valera decided to choose an arbitrary book with number i and read the books one by one, starting from this book. In other words, he will first read book number i, then book number i + 1, then book number i + 2 and so on. He continues the process until he either runs out of the free time or finishes reading the n-th book. Valera reads each book up to the end, that is, he doesn't start reading the book if he doesn't have enough free time to finish reading it.

Print the maximum number of books Valera can read.
Input

The first line contains two integers n and t (1 ≤ n ≤ 105; 1 ≤ t ≤ 109) — the number of books and the number of free minutes Valera's got. The second line contains a sequence of n integers a1, a2, ..., an (1 ≤ ai ≤ 104), where number ai shows the number of minutes that the boy needs to read the i-th book.
Output

Print a single integer — the maximum number of books Valera can read.
Examples
Input
Copy

4 5
3 1 2 1

Output
Copy

3

Input
Copy

3 3
2 2 3

Output
Copy

1*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,t; cin>>n>>t;
    
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll num; cin>>num;
        v.push_back(num);
    }
    
    ll time=0,j=0;
    
    while(j<n && (time+v[j])<=t)
    {
        time+=v[j];
        j++;
    }
    
    ll ans=j;
    
    for(ll i=0;i<n;i++)
    {
        time-=v[i];
        while(j<n && (time+v[j])<=t)
        {
            time+=v[j];
            j++;
        }
        if((j-i-1)>ans)
            ans=j-i-1;
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}
