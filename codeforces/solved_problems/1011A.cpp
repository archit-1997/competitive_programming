/*Natasha is going to fly to Mars. She needs to build a rocket, which consists of several stages in some order. Each of the stages is defined by a lowercase Latin letter. This way, the rocket can be described by the string — concatenation of letters, which correspond to the stages.

There are 𝑛
stages available. The rocket must contain exactly 𝑘

of them. Stages in the rocket should be ordered by their weight. So, after the stage with some letter can go only stage with a letter, which is at least two positions after in the alphabet (skipping one letter in between, or even more). For example, after letter 'c' can't go letters 'a', 'b', 'c' and 'd', but can go letters 'e', 'f', ..., 'z'.

For the rocket to fly as far as possible, its weight should be minimal. The weight of the rocket is equal to the sum of the weights of its stages. The weight of the stage is the number of its letter in the alphabet. For example, the stage 'a 'weighs one ton,' b 'weighs two tons, and' z' — 26

tons.

Build the rocket with the minimal weight or determine, that it is impossible to build a rocket at all. Each stage can be used at most once.
Input

The first line of input contains two integers — 𝑛
and 𝑘 (1≤𝑘≤𝑛≤50

) – the number of available stages and the number of stages to use in the rocket.

The second line contains string 𝑠
, which consists of exactly 𝑛

lowercase Latin letters. Each letter defines a new stage, which can be used to build the rocket. Each stage can be used at most once.
Output

Print a single integer — the minimal total weight of the rocket or -1, if it is impossible to build the rocket at all.
Examples
Input
Copy

5 3
xyabd

Output
Copy

29

Input
Copy

7 4
problem

Output
Copy

34

Input
Copy

2 2
ab

Output
Copy

-1

Input
Copy

12 1
abaabbaaabbb

Output
Copy

1

Note

In the first example, the following rockets satisfy the condition:

    "adx" (weight is 1+4+24=29

);
"ady" (weight is 1+4+25=30
);
"bdx" (weight is 2+4+24=30
);
"bdy" (weight is 2+4+25=31

    ).

Rocket "adx" has the minimal weight, so the answer is 29

.

In the second example, target rocket is "belo". Its weight is 2+5+12+15=34

.

In the third example, 𝑛=𝑘=2
, so the rocket must have both stages: 'a' and 'b'. This rocket doesn't satisfy the condition, because these letters are adjacent in the alphabet. Answer is -1.
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
	
	ll n,k; cin>>n>>k;
	string s;   cin>>s;
	sort(s.begin(),s.end());
	vector<ll> v;
	for(ll i=0;i<n;i++)
	{
	    ll val=s[i]-'a'+1;
	    v.push_back(val);
	}
	
	auto it=unique(v.begin(),v.end());
	
	v.resize(distance(v.begin(),it));
	
// 	cout<<v.size()<<endl;
	
// 	for(ll i=0;i<v.size();i++)
// 	    cout<<v[i]<<" ";

    if(v.size()==0)
        cout<<-1<<endl;
    else if(k==1)
    {
        cout<<v[0]<<endl;
    }
    else
    {
        ll ans=v[0],i=1,val,prev=v[0];
        k--;
        while(i<n)
        {
            ll cur=v[i];
            if(cur-prev>1)
            {
                ans+=cur;
                prev=cur;
                k--;
                if(k==0)
                    break;
                i++;
            }
            else
                i++;
        }
        
        if(k==0)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
	
	return 0;
}
