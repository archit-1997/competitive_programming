/*Valera is a lazy student. He has m clean bowls and k clean plates.

Valera has made an eating plan for the next n days. As Valera is lazy, he will eat exactly one dish per day. At that, in order to eat a dish, he needs exactly one clean plate or bowl. We know that Valera can cook only two types of dishes. He can eat dishes of the first type from bowls and dishes of the second type from either bowls or plates.

When Valera finishes eating, he leaves a dirty plate/bowl behind. His life philosophy doesn't let him eat from dirty kitchenware. So sometimes he needs to wash his plate/bowl before eating. Find the minimum number of times Valera will need to wash a plate/bowl, if he acts optimally.
Input

The first line of the input contains three integers n, m, k (1 ≤ n, m, k ≤ 1000) — the number of the planned days, the number of clean bowls and the number of clean plates.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 2). If ai equals one, then on day i Valera will eat a first type dish. If ai equals two, then on day i Valera will eat a second type dish.
Output

Print a single integer — the minimum number of times Valera will need to wash a plate/bowl.
Examples
Input
Copy

3 1 1
1 2 1

Output
Copy

1

Input
Copy

4 3 1
1 1 1 1

Output
Copy

1

Input
Copy

3 1 2
2 2 2

Output
Copy

0

Input
Copy

8 2 2
1 2 1 2 1 2 1 2

Output
Copy

4

Note

In the first sample Valera will wash a bowl only on the third day, so the answer is one.

In the second sample, Valera will have the first type of the dish during all four days, and since there are only three bowls, he will wash a bowl exactly once.

In the third sample, Valera will have the second type of dish for all three days, and as they can be eaten from either a plate or a bowl, he will never need to wash a plate/bowl.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second
#define P pair<ll,ll>
#define PP pair<pair<ll,ll>,ll>
#define V vector<ll>
#define VP vector<pair<ll,ll>>
#define VS vector<string>
#define VV vector<vector<ll>> 
#define VVP vector<vector<pair<ll,ll>>> 
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll,vector<ll>,greater<ll>>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	FAST;
	
	ll days,bowl,plate; cin>>days>>bowl>>plate;
	
    ll d1=0,d2=0;
    FOR(i,0,days)
    {
        ll num; cin>>num;
        if(num==1)
            d1++;
        else
            d2++;
    }
    
    ll ans=0;
    
    if(bowl>=d1)
        bowl-=d1;
    else
    {
        ans+=(d1-bowl);
        bowl=0;
    }
    
    ll rem=bowl+plate;
    
    if(rem<d2)
        ans+=(d2-rem);
    
    cout<<ans;
    
    
	
	return 0;
}
