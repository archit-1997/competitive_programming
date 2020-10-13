/*Vasya has become interested in wrestling. In wrestling wrestlers use techniques for which they are awarded points by judges. The wrestler who gets the most points wins.

When the numbers of points of both wrestlers are equal, the wrestler whose sequence of points is lexicographically greater, wins.

If the sequences of the awarded points coincide, the wrestler who performed the last technique wins. Your task is to determine which wrestler won.
Input

The first line contains number n — the number of techniques that the wrestlers have used (1 ≤ n ≤ 2·105).

The following n lines contain integer numbers ai (|ai| ≤ 109, ai ≠ 0). If ai is positive, that means that the first wrestler performed the technique that was awarded with ai points. And if ai is negative, that means that the second wrestler performed the technique that was awarded with ( - ai) points.

The techniques are given in chronological order.
Output

If the first wrestler wins, print string "first", otherwise print "second"
Examples
Input
Copy

5
1
2
-3
-4
3

Output
Copy

second

Input
Copy

3
-1
-2
3

Output
Copy

first

Input
Copy

2
4
-4

Output
Copy

second

Note

Sequence x  =  x1x2... x|x| is lexicographically larger than sequence y  =  y1y2... y|y|, if either |x|  >  |y| and x1  =  y1,  x2  =  y2, ... ,  x|y|  =  y|y|, or there is such number r (r  <  |x|, r  <  |y|), that x1  =  y1,  x2  =  y2,  ... ,  xr  =  yr and xr  +  1  >  yr  +  1.

We use notation |a| to denote length of sequence a.
*/

#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    int compare;
    int arr[t];
 
    vector<int> temp1;
    vector<int> temp2;
 
    long long sum1=0;
    long long sum2=0;
 
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
        compare=arr[t-1];
        if(arr[i]>0)
        {
            sum1+=arr[i];
            temp1.push_back(arr[i]);
        }
        else if(arr[i]<0)
        {
            sum2+=abs(arr[i]);
            temp2.push_back(abs(arr[i]));
        }
    }
    if(sum1>sum2)
    {
        cout<<"first"<<endl;
        return 0;
    }
    else if(sum2>sum1)
    {
        cout<<"second"<<endl;
        return 0;
    }
    else
    {
        for(int i=0;i<min(temp1.size(),temp2.size());i++)
        {
            if(temp1[i]>temp2[i])
            {
                cout<<"first"<<endl;
                return 0;
            }
            else if(temp2[i]>temp1[i])
            {
                cout<<"second"<<endl;
                return 0;
            }
        }
    }
 
    if(temp1.size()>temp2.size())
    {
        cout<<"first"<<endl;
        return 0;
    }
    else if(temp2.size()>temp1.size())
    {
        cout<<"second"<<endl;
        return 0;
    }
 
     if(sum1==sum2 && compare>0)
        cout<<"first"<<endl;
    else if (sum1==sum2 && compare<0)
        cout<<"second"<<endl;
 
        return 0;
 
}
