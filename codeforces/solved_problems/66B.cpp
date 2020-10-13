/*Little Petya often travels to his grandmother in the countryside. The grandmother has a large garden, which can be represented as a rectangle 1 × n in size, when viewed from above. This rectangle is divided into n equal square sections. The garden is very unusual as each of the square sections possesses its own fixed height and due to the newest irrigation system we can create artificial rain above each section.

Creating artificial rain is an expensive operation. That's why we limit ourselves to creating the artificial rain only above one section. At that, the water from each watered section will flow into its neighbouring sections if their height does not exceed the height of the section. That is, for example, the garden can be represented by a 1 × 5 rectangle, where the section heights are equal to 4, 2, 3, 3, 2. Then if we create an artificial rain over any of the sections with the height of 3, the water will flow over all the sections, except the ones with the height of 4. See the illustration of this example at the picture:

As Petya is keen on programming, he decided to find such a section that if we create artificial rain above it, the number of watered sections will be maximal. Help him.
Input

The first line contains a positive integer n (1 ≤ n ≤ 1000). The second line contains n positive integers which are the height of the sections. All the numbers are no less than 1 and not more than 1000.
Output

Print a single number, the maximal number of watered sections if we create artificial rain above exactly one section.
Examples
Input
Copy

1
2

Output
Copy

1

Input
Copy

5
1 2 1 2 1

Output
Copy

3

Input
Copy

8
1 2 1 1 1 3 3 4

Output
Copy

6
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

    for(ll i=0;i<n;i++)
    {
        ll num;cin>>num;
        v.push_back(num);
    }
    
    vector<ll> lis(n,0);
    for(ll i=1;i<n;i++)
    {
        if(v[i]>=v[i-1])
            lis[i]=lis[i-1]+1;
    }
    //for(ll i=0;i<n;i++)
    //    cout<<lis[i]<<" ";
    //cout<<endl;
    vector<ll> lds(n,0);
    for(ll i=n-2;i>=0;i--)
    {
        if(v[i]>=v[i+1])
            lds[i]=lds[i+1]+1;
    }
    //for(ll i=0;i<n;i++)
    //    cout<<lds[i]<<" ";
    //cout<<endl;
    
    ll ans=INT_MIN;
    for(ll i=0;i<n;i++)
        ans=max(ans,lis[i]+lds[i]);
    
    cout<<ans+1<<endl;
    
    
    
    return 0;
}
