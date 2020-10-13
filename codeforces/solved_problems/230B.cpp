/*We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.
Input

The first line contains a single positive integer, n (1 ≤ n ≤ 105), showing how many numbers are in the array. The next line contains n space-separated integers xi (1 ≤ xi ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is advised to use the cin, cout streams or the %I64d specifier.
Output

Print n lines: the i-th line should contain "YES" (without the quotes), if number xi is Т-prime, and "NO" (without the quotes), if it isn't.
Examples
Input
Copy

3
4 5 6

Output
Copy

YES
NO
NO

Note

The given test has three numbers. The first number 4 has exactly three divisors — 1, 2 and 4, thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5), and the third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //sieve of eratosthenes
    bool prime[1000000]; 
    memset(prime, true, sizeof(prime));
    
    prime[0]=false;
    prime[1]=false;
  
    for (ll p=2; p*p<=1000000; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (ll i=p*p; i<=1000000; i += p) 
                prime[i] = false; 
        } 
    } 
    
    ll n;   cin>>n;
    
    for(ll i=0;i<n;i++)
    {
        ll num; cin>>num;
        
        ll sq=(int)(sqrt(num));
        //cout<<sqrt(num)<<" "<<sq<<" "<<prime[sq]<<endl;
        
        if(num==4)
            cout<<"YES"<<endl;
        else if(num%2==0)
            cout<<"NO"<<endl;
        else if(prime[sq] && sq==sqrt(num))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}
