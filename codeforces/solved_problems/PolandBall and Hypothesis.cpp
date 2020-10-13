/*PolandBall is a young, clever Ball. He is interested in prime numbers. He has stated a following hypothesis: "There exists such a positive integer n that for each positive integer m number n·m + 1 is a prime number".

Unfortunately, PolandBall is not experienced yet and doesn't know that his hypothesis is incorrect. Could you prove it wrong? Write a program that finds a counterexample for any n.
Input

The only number in the input is n (1 ≤ n ≤ 1000) — number from the PolandBall's hypothesis.
Output

Output such m that n·m + 1 is not a prime number. Your answer will be considered correct if you output any suitable m such that 1 ≤ m ≤ 103. It is guaranteed the the answer exists.
Examples
Input
Copy

3

Output
Copy

1

Input
Copy

4

Output
Copy

2

Note

A prime number (or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself.

For the first sample testcase, 3·1 + 1 = 4. We can output 1.

In the second sample testcase, 4·1 + 1 = 5. We cannot output 1 because 5 is prime. However, m = 2 is okay since 4·2 + 1 = 9, which is not a prime number.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    vector<bool> prime(1e6,true);
    prime[0]=false;
    prime[1]=false;
    
    for(ll i=2;i*i<1e6;i++)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<=1e6;j+=i)
                prime[j]=false;
        }
    }
    
    ll n;   cin>>n;
    
    for(ll i=1;i<=1000;i++)
    {
        //cout<<i*n+1<<endl;
        if(prime[i*n+1]==false)
        {
            cout<<i;
            break;
        }
        //cout<<i*n+1<<endl;

    }
    
    
    return 0;
}
