/*It is raining heavily. But this is the first day for Serval, who just became 3 years old, to go to the kindergarten. Unfortunately, he lives far from kindergarten, and his father is too busy to drive him there. The only choice for this poor little boy is to wait for a bus on this rainy day. Under such circumstances, the poor boy will use the first bus he sees no matter where it goes. If several buses come at the same time, he will choose one randomly.

Serval will go to the bus station at time 𝑡
, and there are 𝑛 bus routes which stop at this station. For the 𝑖-th bus route, the first bus arrives at time 𝑠𝑖 minutes, and each bus of this route comes 𝑑𝑖

minutes later than the previous one.

As Serval's best friend, you wonder which bus route will he get on. If several buses arrive at the same time, you can print any of them.
Input

The first line contains two space-separated integers 𝑛
and 𝑡 (1≤𝑛≤100, 1≤𝑡≤105

) — the number of bus routes and the time Serval goes to the station.

Each of the next 𝑛
lines contains two space-separated integers 𝑠𝑖 and 𝑑𝑖 (1≤𝑠𝑖,𝑑𝑖≤105

) — the time when the first bus of this route arrives and the interval between two buses of this route.
Output

Print one number — what bus route Serval will use. If there are several possible answers, you can print any of them.
Examples
Input
Copy

2 2
6 4
9 5

Output
Copy

1

Input
Copy

5 5
3 3
2 5
5 6
4 9
6 1

Output
Copy

3

Input
Copy

3 7
2 2
2 3
2 4

Output
Copy

1

Note

In the first example, the first bus of the first route arrives at time 6
, and the first bus of the second route arrives at time 9

, so the first route is the answer.

In the second example, a bus of the third route arrives at time 5

, so it is the answer.

In the third example, buses of the first route come at times 2
, 4, 6, 8, and so fourth, buses of the second route come at times 2, 5, 8, and so fourth and buses of the third route come at times 2, 6, 10, and so on, so 1 and 2 are both acceptable answers while 3 is not.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , t , s , d , M=1000000 , A;
	cin >>n >> t;
	for (int i=1;i<=n;i++)
	{
		cin>>s>>d;
		while(s<t)
			s+=d;
		if(s<M)
		{
			M=s;
			A=i;
		}
	}
	cout<<A;
}
