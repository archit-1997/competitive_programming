/*Tanechka is shopping in the toy shop. There are exactly n toys in the shop for sale, the cost of the i-th toy is i burles. She wants to choose two toys in such a way that their total cost is k
burles. How many ways to do that does she have?
Each toy appears in the shop exactly once. Pairs (a,b)
and (b,a) are considered equal. Pairs (a,b), where a=b
, are not allowed.
Input
The first line of the input contains two integers n
, k (1≤n,k≤1014
) — the number of toys and the expected total cost of the pair of toys.
Output
Print the number of ways to choose the pair of toys satisfying the condition above. Print 0, if Tanechka can choose no pair of toys in such a way that their total cost is k
burles.
Examples
Input
Copy
8 5
Output
Copy
2
Input
Copy
8 15
Output
Copy
1
Input
Copy
7 20
Output
Copy
0
Input
Copy
1000000000000 1000000000001
Output
Copy
500000000000
Note
In the first example Tanechka can choose the pair of toys (1,4
) or the pair of toys (2,3
).
In the second example Tanechka can choose only the pair of toys (7,8
).
In the third example choosing any pair of toys will lead to the total cost less than 20
. So the answer is 0.
In the fourth example she can choose the following pairs: (1,1000000000000)
, (2,999999999999), (3,999999999998), ..., (500000000000,500000000001). The number of such pairs is exactly 500000000000.
*/
#include <iostream>
    using namespace std;
    int main()
    {
        long long n,k;
        cin>>n>>k;
        if(n<k) k=2*n-k+2;
        if(k<=0) cout<<"0";
        else cout<<(k-1)/2;
        return 0;
}
