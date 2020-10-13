/*SmallR is an archer. SmallR is taking a match of archer with Zanoes. They try to shoot in the target in turns, and SmallR shoots first. The probability of shooting the target each time is for SmallR while for Zanoes. The one who shoots in the target first should be the winner.

Output the probability that SmallR will win the match.
Input

A single line contains four integers .
Output

Print a single real number, the probability that SmallR will win the match.

The answer will be considered correct if the absolute or relative error doesn't exceed 10 - 6.
Examples
Input
Copy

1 2 1 2

Output
Copy

0.666666666667*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    
    double f1=a/b,f2=c/d;
    //cout<<f1<<" "<<f2<<endl;
    double r=(1-f1)*(1-f2);
    double den=(1-r);
    
    double ans=f1/den;
    cout<<ans<<endl;
    
    return 0;
}
