/*People do many crazy things to stand out in a crowd. Some of them dance, some learn by heart rules of Russian language, some try to become an outstanding competitive programmers, while others collect funny math objects.

Alis is among these collectors. Right now she wants to get one of k-special tables. In case you forget, the table n × n is called k-special if the following three conditions are satisfied:

    every integer from 1 to n2 appears in the table exactly once;
    in each row numbers are situated in increasing order;
    the sum of numbers in the k-th column is maximum possible. 

Your goal is to help Alice and find at least one k-special table of size n × n. Both rows and columns are numbered from 1 to n, with rows numbered from top to bottom and columns numbered from left to right.
Input

The first line of the input contains two integers n and k (1 ≤ n ≤ 500, 1 ≤ k ≤ n) — the size of the table Alice is looking for and the column that should have maximum possible sum.
Output

First print the sum of the integers in the k-th column of the required table.

Next n lines should contain the description of the table itself: first line should contains n elements of the first row, second line should contain n elements of the second row and so on.

If there are multiple suitable table, you are allowed to print any.
Examples
Input
Copy

4 1

Output
Copy

28
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Input
Copy

5 3

Output
Copy

85
5 6 17 18 19
9 10 23 24 25
7 8 20 21 22
3 4 14 15 16
1 2 11 12 13
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,k;	cin>>n>>k;
    ll val=n*n,ans=0,diff=n-k+1;
    val=val-(diff-1);
    ans=val;
    
    for(int i=1;i<n;i++)
    {
        val=val-diff;
        ans+=val;
    }
    //Value of the sum of the column
    cout<<ans<<endl;
	
	//Printing the matrix
	
	vector<vector<int>> v(n,vector<int>(n));
	int col=k;
	for(int i=1;i<=n;i++)
	{
	    for(int j=col;j<=n;j++)
	    {
	        v[i-1][j-1]=val;
	        val++;
	    }
	}
	
	val=1;
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<col;j++)
	    {
	        v[i-1][j-1]=val;
	        val++;
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cout<<v[i][j]<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
