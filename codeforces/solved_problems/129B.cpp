/*Anna and Maria are in charge of the math club for junior students. When the club gathers together, the students behave badly. They've brought lots of shoe laces to the club and got tied with each other. Specifically, each string ties together two students. Besides, if two students are tied, then the lace connects the first student with the second one as well as the second student with the first one.

To restore order, Anna and Maria do the following. First, for each student Anna finds out what other students he is tied to. If a student is tied to exactly one other student, Anna reprimands him. Then Maria gathers in a single group all the students who have been just reprimanded. She kicks them out from the club. This group of students immediately leaves the club. These students takes with them the laces that used to tie them. Then again for every student Anna finds out how many other students he is tied to and so on. And they do so until Anna can reprimand at least one student.

Determine how many groups of students will be kicked out of the club.
Input

The first line contains two integers n and m — the initial number of students and laces (). The students are numbered from 1 to n, and the laces are numbered from 1 to m. Next m lines each contain two integers a and b — the numbers of students tied by the i-th lace (1 ≤ a, b ≤ n, a ≠ b). It is guaranteed that no two students are tied with more than one lace. No lace ties a student to himself.
Output

Print the single number — the number of groups of students that will be kicked out from the club.
Examples
Input
Copy

3 3
1 2
2 3
3 1

Output
Copy

0

Input
Copy

6 3
1 2
2 3
3 4

Output
Copy

2

Input
Copy

6 5
1 4
2 4
3 4
5 4
6 4

Output
Copy

1

Note

In the first sample Anna and Maria won't kick out any group of students — in the initial position every student is tied to two other students and Anna won't be able to reprimand anyone.

In the second sample four students are tied in a chain and two more are running by themselves. First Anna and Maria kick out the two students from both ends of the chain (1 and 4), then — two other students from the chain (2 and 3). At that the students who are running by themselves will stay in the club.

In the third sample Anna and Maria will momentarily kick out all students except for the fourth one and the process stops at that point. The correct answer is one.
*/

#include<cstdio>
main(){
	int n,m,d[101]={},a,b,C,O=-1,i,j;
	bool c[101][101]={};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		++d[a];
		++d[b];
		c[a][b]=1;
		c[b][a]=1;
	}
	do{
		int E[101]={};
		C=0;
		for(i=1;i<=n;++i)
			if(d[i]==1){
				E[C++]=i;
				--d[i];
			}
		for(i=0;i<C;++i)
			for(j=1;j<=n;++j)
				if(c[E[i]][j])
					--d[j];
		++O;
	}while(C>0);
	printf("%d",O);
}
