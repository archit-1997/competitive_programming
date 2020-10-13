/*In Berland a money reform is being prepared. New coins are being introduced. After long economic calculations was decided that the most expensive coin should possess the denomination of exactly n Berland dollars. Also the following restriction has been introduced for comfort: the denomination of each coin should be divisible by the denomination of any cheaper coin. It is known that among all the possible variants the variant with the largest number of new coins will be chosen. Find this variant. Print in the order of decreasing of the coins' denominations.
Input

The first and only line contains an integer n (1 ≤ n ≤ 106) which represents the denomination of the most expensive coin.
Output

Print the denominations of all the coins in the order of decreasing. The number of coins must be the largest possible (with the given denomination n of the most expensive coin). Also, the denomination of every coin must be divisible by the denomination of any cheaper coin. Naturally, the denominations of all the coins should be different. If there are several solutins to that problem, print any of them.
Examples
Input
Copy

10

Output
Copy

10 5 1

Input
Copy

4

Output
Copy

4 2 1

Input
Copy

3

Output
Copy

3 1
*/

#include <bits/stdc++.h> 
using namespace std; 
  
int main()
{
    
    bool prime[1000001]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=100000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=100000; i += p) 
                prime[i] = false; 
        } 
    } 
    
    vector<int> v;
    
    for (int p=2; p<=100000; p++) 
       if (prime[p]) 
          v.push_back(p);
          
    int n,index=0;   cin>>n;
    
    set<int,greater<int>> s;
    
    while(n!=1)
    {
        s.insert(n);
        if(n%v[index]==0)
            n=n/v[index];
        else
        {
            while(1)
            {
                if(n%v[index]==0)
                    break;
                else
                    index++;
                if(index==v.size())
                    break;
            }
        }
    }
    
    for(auto it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    cout<<1<<endl;

    return 0;  

} 
