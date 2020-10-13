/*Long story short, shashlik is Miroslav's favorite food. Shashlik is prepared on several skewers simultaneously. There are two states for each skewer: initial and turned over.

This time Miroslav laid out n
skewers parallel to each other, and enumerated them with consecutive integers from 1 to n in order from left to right. For better cooking, he puts them quite close to each other, so when he turns skewer number i, it leads to turning k closest skewers from each side of the skewer i, that is, skewers number i−k, i−k+1, ..., i−1, i+1, ..., i+k−1, i+k

(if they exist).

For example, let n=6
and k=1. When Miroslav turns skewer number 3, then skewers with numbers 2, 3, and 4 will come up turned over. If after that he turns skewer number 1, then skewers number 1, 3, and 4 will be turned over, while skewer number 2

will be in the initial position (because it is turned again).

As we said before, the art of cooking requires perfect timing, so Miroslav wants to turn over all n
skewers with the minimal possible number of actions. For example, for the above example n=6 and k=1, two turnings are sufficient: he can turn over skewers number 2 and 5

.

Help Miroslav turn over all n

skewers.
Input

The first line contains two integers n
and k (1≤n≤1000, 0≤k≤1000

) — the number of skewers and the number of skewers from each side that are turned in one step.
Output

The first line should contain integer l
 — the minimum number of actions needed by Miroslav to turn over all n skewers. After than print l integers from 1 to n

denoting the number of the skewer that is to be turned over at the corresponding step.
Examples
Input
Copy

7 2

Output
Copy

2
1 6 

Input
Copy

5 1

Output
Copy

2
1 4 

Note

In the first example the first operation turns over skewers 1
, 2 and 3, the second operation turns over skewers 4, 5, 6 and 7

.

In the second example it is also correct to turn over skewers 2
and 5, but turning skewers 2 and 4, or 1 and 5 are incorrect solutions because the skewer 3 is in the initial state after these operations.
*/

        #include<iostream>
        using namespace std;
        int main()
        {
        	int n,k,d,i,q,r;
        	cin>>n>>k;
        	d=2*k+1;
        	q=n/d;
        	r=n%d;
        	if(r!=0)
        		q++;
        	else
        		r=2*k;
        	cout<<q<<endl;
        	for(i=1+r/2;i<=n;i+=d)
        		cout<<i<<" ";
        	return 0;
        }
