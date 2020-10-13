/*The Bitlandians are quite weird people. They have very peculiar customs.

As is customary, Uncle J. wants to have n eggs painted for Bitruz (an ancient Bitland festival). He has asked G. and A. to do the work.

The kids are excited because just as is customary, they're going to be paid for the job!

Overall uncle J. has got n eggs. G. named his price for painting each egg. Similarly, A. named his price for painting each egg. It turns out that for each egg the sum of the money both A. and G. want for the painting equals 1000.

Uncle J. wants to distribute the eggs between the children so as to give each egg to exactly one child. Also, Uncle J. wants the total money paid to A. to be different from the total money paid to G. by no more than 500.

Help Uncle J. Find the required distribution of eggs or otherwise say that distributing the eggs in the required manner is impossible.
Input

The first line contains integer n (1 ≤ n ≤ 106) — the number of eggs.

Next n lines contain two integers ai and gi each (0 ≤ ai, gi ≤ 1000; ai + gi = 1000): ai is the price said by A. for the i-th egg and gi is the price said by G. for the i-th egg.
Output

If it is impossible to assign the painting, print "-1" (without quotes).

Otherwise print a string, consisting of n letters "G" and "A". The i-th letter of this string should represent the child who will get the i-th egg in the required distribution. Letter "A" represents A. and letter "G" represents G. If we denote the money Uncle J. must pay A. for the painting as Sa, and the money Uncle J. must pay G. for the painting as Sg, then this inequality must hold: |Sa  -  Sg|  ≤  500.

If there are several solutions, you are allowed to print any of them.
Examples
Input
Copy

2
1 999
999 1

Output
Copy

AG

Input
Copy

3
400 600
400 600
400 600

Output
Copy

AGA
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    ll v[n][2];

    for(ll i=0;i<n;i++)
    {
        ll  a,g;    cin>>a>>g;
        v[i][0]=a;
        v[i][1]=g;
    }
    
    char ans[n];
   
    ll s1=0,s2=0;
    ll flag=0;
    for(ll i=0;i<n;i++)
    {
        ll v1=s1+v[i][0];
        ll v2=s2+v[i][1];
        
        if(abs(v1-s2)<=500)
        {
            s1+=v[i][0];
            ans[i]='A';
        }
        else if(abs(v2-s1)<=500)
        {
            s2+=v[i][1];
            ans[i]='G';
        }
        else
        {
            flag=1;
            cout<<"-1"<<endl;
            break;
        }
    }
    
    if(!flag)
    {
        //cout<<"YES"<<endl;
        for(ll i=0;i<n;i++)
            cout<<ans[i];
        
        cout<<endl;
    }
    
    return 0;
}
