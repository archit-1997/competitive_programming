/*Let us define two functions f and g on positive integer numbers.

You need to process Q queries. In each query, you will be given three integers l, r and k. You need to print the number of integers x between l and r inclusive, such that g(x) = k.
Input

The first line of the input contains an integer Q (1 ≤ Q ≤ 2 × 105) representing the number of queries.

Q lines follow, each of which contains 3 integers l, r and k (1 ≤ l ≤ r ≤ 106, 1 ≤ k ≤ 9).
Output

For each query, print a single line containing the answer for that query.
Examples
Input
Copy

4
22 73 9
45 64 6
47 55 7
2 62 4

Output
Copy

1
4
0
8

Input
Copy

4
82 94 6
56 67 4
28 59 9
39 74 4

Output
Copy

3
1
1
5

Note

In the first example:

    g(33) = 9 as g(33) = g(3 × 3) = g(9) = 9
    g(47) = g(48) = g(60) = g(61) = 6
    There are no such integers between 47 and 55.
    g(4) = g(14) = g(22) = g(27) = g(39) = g(40) = g(41) = g(58) = 4 
    */
    
    #include<bits/stdc++.h>
int a[10][1000001];
using namespace std;
int f(int n)
{
    int mul=1;
    while(n)
    {
        if(n%10!=0)
        {
            mul*=n%10;
        }
        n/=10;
    }
    return mul;
}
int g(int x)
{
    if(x<10)
        return x;
    return g(f(x));
}
int main()
{
    int n,cnt,l,r,i,k;
    for(i=1; i<10; i++)
    {
        cnt=0;
        for(int j=1; j<1000001; j++)
        {
            if(g(j)==i)
            {
                cnt++;
            }
            a[i][j]=cnt;
        }
    }
    cin>>n;
    while(n--)
    {
        cin>>l>>r>>k;
        cout<<a[k][r]-a[k][l-1]<<endl;
    }
    return 0;
}
