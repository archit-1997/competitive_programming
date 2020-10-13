/*The letters shop showcase is a string s, consisting of n

lowercase Latin letters. As the name tells, letters are sold in the shop.

Letters are sold one by one from the leftmost to the rightmost. Any customer can only buy some prefix of letters from the string s

.

There are m
friends, the i-th of them is named ti

. Each of them is planning to estimate the following value: how many letters (the length of the shortest prefix) would s/he need to buy if s/he wanted to construct her/his name of bought letters. The name can be constructed if each letter is presented in the equal or greater amount.

    For example, for s

="arrayhead" and ti="arya" 5
letters have to be bought ("arrayhead").
For example, for s
="arrayhead" and ti="harry" 6
letters have to be bought ("arrayhead").
For example, for s
="arrayhead" and ti="ray" 5
letters have to be bought ("arrayhead").
For example, for s
="arrayhead" and ti="r" 2
letters have to be bought ("arrayhead").
For example, for s
="arrayhead" and ti="areahydra" all 9

    letters have to be bought ("arrayhead"). 

It is guaranteed that every friend can construct her/his name using the letters from the string s

.

Note that the values for friends are independent, friends are only estimating them but not actually buying the letters.
Input

The first line contains one integer n
(1≤n≤2⋅105) — the length of showcase string s

.

The second line contains string s
, consisting of exactly n

lowercase Latin letters.

The third line contains one integer m
(1≤m≤5⋅104

) — the number of friends.

The i
-th of the next m lines contains ti (1≤|ti|≤2⋅105) — the name of the i

-th friend.

It is guaranteed that ∑i=1m|ti|≤2⋅105

.
Output

For each friend print the length of the shortest prefix of letters from s

s/he would need to buy to be able to construct her/his name of them. The name can be constructed if each letter is presented in the equal or greater amount.

It is guaranteed that every friend can construct her/his name using the letters from the string s

.
Example
Input
Copy

9
arrayhead
5
arya
harry
ray
r
areahydra

Output
Copy

5
6
5
2
9
*/

        #include<bits/stdc++.h>
        using namespace std;
        int main()
        {
            int n,m;
            cin>>n;
            string s;
            cin>>s;
            cin>>m;
            vector<int> v[27];
            for(int i=0;i<s.length();i++)
            {
                int ch=s[i]-96;
                v[ch].push_back(i+1);
            }
            for(;m--;)
            {
                int pos[27];
                for(int i=1;i<27;i++)
                {
                    if(v[i].size()==0)
                    pos[i]=-1;
                    else
                    pos[i]=0;
                }
                string w;
                cin>>w;
                int ans=0;
                for(int i=0;i<w.length();i++)
                {
                    int c=w[i]-96;
                    if(v[c][pos[c]]>ans)
                    {
                        ans=v[c][pos[c]];
                    }
                    pos[c]++;
                }
                cout<<ans<<"\n";
            }
        }
