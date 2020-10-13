/*Squirrel Liss loves nuts. There are n trees (numbered 1 to n from west to east) along a street and there is a delicious nut on the top of each tree. The height of the tree i is hi. Liss wants to eat all nuts.

Now Liss is on the root of the tree with the number 1. In one second Liss can perform one of the following actions:

Walk up or down one unit on a tree.
Eat a nut on the top of the current tree.
Jump to the next tree. In this action the height of Liss doesn't change. More formally, when Liss is at height h of the tree i (1 ≤ i ≤ n - 1), she jumps to height h of the tree i + 1. This action can't be performed if h > hi + 1.
Compute the minimal time (in seconds) required to eat all nuts.

Input
The first line contains an integer n (1  ≤  n ≤ 105) — the number of trees.

Next n lines contains the height of trees: i-th line contains an integer hi (1 ≤ hi ≤ 104) — the height of the tree with the number i.

Output
Print a single integer — the minimal time required to eat all nuts in seconds.

Examples
inputCopy
2
1
2
outputCopy
5
inputCopy
5
2
1
2
1
1
outputCopy
14*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    vector<ll> h;
    for(ll i=0;i<n;i++)
    {
        ll num; cin>>num;
        h.push_back(num);
    }
    
    if(n==1)
    {
        cout<<(h[0]+1)<<endl;
        return 0;
    }
    
    ll time=h[0]+1;//climbed and eaten
    
    for(ll i=1;i<n;i++)
    {
        if(h[i]>=h[i-1])
        {
            time++;//jump
            time+=(h[i]-h[i-1]);//climbed
            time++;//eaten
        }
        else
        {
            time+=(h[i-1]-h[i]);//climbed down
            time+=2;//jumped and eaten
        }
    }
    
    cout<<time<<endl;
    
    
    return 0;
}
