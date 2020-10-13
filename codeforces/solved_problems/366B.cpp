/*You helped Dima to have a great weekend, but it's time to work. Naturally, Dima, as all other men who have girlfriends, does everything wrong.

Inna and Dima are now in one room. Inna tells Dima off for everything he does in her presence. After Inna tells him off for something, she goes to another room, walks there in circles muttering about how useless her sweetheart is. During that time Dima has time to peacefully complete k - 1 tasks. Then Inna returns and tells Dima off for the next task he does in her presence and goes to another room again. It continues until Dima is through with his tasks.

Overall, Dima has n tasks to do, each task has a unique number from 1 to n. Dima loves order, so he does tasks consecutively, starting from some task. For example, if Dima has 6 tasks to do in total, then, if he starts from the 5-th task, the order is like that: first Dima does the 5-th task, then the 6-th one, then the 1-st one, then the 2-nd one, then the 3-rd one, then the 4-th one.

Inna tells Dima off (only lovingly and appropriately!) so often and systematically that he's very well learned the power with which she tells him off for each task. Help Dima choose the first task so that in total he gets told off with as little power as possible.
Input

The first line of the input contains two integers n, k (1 ≤ k ≤ n ≤ 105). The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 103), where ai is the power Inna tells Dima off with if she is present in the room while he is doing the i-th task.

It is guaranteed that n is divisible by k.
Output

In a single line print the number of the task Dima should start with to get told off with as little power as possible. If there are multiple solutions, print the one with the minimum number of the first task to do.
Examples
Input
Copy

6 2
3 2 1 6 5 4

Output
Copy

1

Input
Copy

10 5
1 3 5 7 9 9 4 1 8 5

Output
Copy

3

Note

Explanation of the first example.

If Dima starts from the first task, Inna tells him off with power 3, then Dima can do one more task (as k = 2), then Inna tells him off for the third task with power 1, then she tells him off for the fifth task with power 5. Thus, Dima gets told off with total power 3 + 1 + 5 = 9. If Dima started from the second task, for example, then Inna would tell him off for tasks 2, 4 and 6 with power 2 + 6 + 4 = 12.

Explanation of the second example.

In the second example k = 5, thus, Dima manages to complete 4 tasks in-between the telling off sessions. Thus, Inna tells Dima off for tasks number 1 and 6 (if he starts from 1 or 6), 2 and 7 (if he starts from 2 or 7) and so on. The optimal answer is to start from task 3 or 8, 3 has a smaller number, so the answer is 3.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;   cin>>n>>k;
    vector<ll> v;

    for(ll i=0;i<n;i++)
    {
        ll num;cin>>num;
        v.push_back(num);
    }
    
    ll set_size=n/k;
    
    ll min_sum=INT_MAX,min_index=0;
    
    for(ll i=0;i<k;i++)
    {
        ll sum=0;
        for(ll j=0;j<set_size;j++)
        {
            ll index=i+k*j;
            sum+=v[index];
        }
        
        if(min_sum>sum)
        {
            min_sum=sum;
            min_index=i;
        }
    }
    
    cout<<min_index+1<<endl;
    
    return 0;
}
