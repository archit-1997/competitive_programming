There are n Imperial stormtroopers on the field. The battle field is a plane with Cartesian coordinate system. Each stormtrooper is associated with his coordinates (x, y) on this plane.

Han Solo has the newest duplex lazer gun to fight these stormtroopers. It is situated at the point (x0, y0). In one shot it can can destroy all the stormtroopers, situated on some line that crosses point (x0, y0).

/*Your task is to determine what minimum number of shots Han Solo needs to defeat all the stormtroopers.

The gun is the newest invention, it shoots very quickly and even after a very large number of shots the stormtroopers don't have enough time to realize what's happening and change their location.
Input

The first line contains three integers n, x0 и y0 (1 ≤ n ≤ 1000,  - 104 ≤ x0, y0 ≤ 104) — the number of stormtroopers on the battle field and the coordinates of your gun.

Next n lines contain two integers each xi, yi ( - 104 ≤ xi, yi ≤ 104) — the coordinates of the stormtroopers on the battlefield. It is guaranteed that no stormtrooper stands at the same point with the gun. Multiple stormtroopers can stand at the same point.
Output

Print a single integer — the minimum number of shots Han Solo needs to destroy all the stormtroopers.
Examples
Input
Copy

4 0 0
1 1
2 2
2 0
-1 -1

Output
Copy

2

Input
Copy

2 1 2
1 1
1 0

Output
Copy

1

Note

Explanation to the first and second samples from the statement, respectively: */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,a,b;   cin>>n>>a>>b;
    
    vector<ll> x,y;
    
    for(ll i=0;i<n;i++)
    {
        ll n1,n2;   cin>>n1>>n2;
        x.push_back(n1);
        y.push_back(n2);
    }
    
    bool check[n];
    
    memset(check,false,sizeof(check));
    
    ll count=0;
    
    for(ll i=0;i<n;i++)
    
    {
        if(check[i])
            continue;
            
        count++;
        
        ll dx=a-x[i];
        ll dy=b-y[i];
        
        for(ll j=0;j<n;j++)
        {
            ll ex=a-x[j];
            ll ey=b-y[j];
            
            if(dx*ey==dy*ex)
            {
                check[j]=true;
                
            }
        }
    }
    
    cout<<count<<endl;
    
    return 0;
}
