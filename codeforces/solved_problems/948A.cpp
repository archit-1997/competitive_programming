/*Bob is a farmer. He has a large pasture with many sheep. Recently, he has lost some of them due to wolf attacks. He thus decided to place some shepherd dogs in such a way that all his sheep are protected.

The pasture is a rectangle consisting of R × C cells. Each cell is either empty, contains a sheep, a wolf or a dog. Sheep and dogs always stay in place, but wolves can roam freely around the pasture, by repeatedly moving to the left, right, up or down to a neighboring cell. When a wolf enters a cell with a sheep, it consumes it. However, no wolf can enter a cell with a dog.

Initially there are no dogs. Place dogs onto the pasture in such a way that no wolf can reach any sheep, or determine that it is impossible. Note that since you have many dogs, you do not need to minimize their number.
Input

First line contains two integers R (1 ≤ R ≤ 500) and C (1 ≤ C ≤ 500), denoting the number of rows and the numbers of columns respectively.

Each of the following R lines is a string consisting of exactly C characters, representing one row of the pasture. Here, 'S' means a sheep, 'W' a wolf and '.' an empty cell.
Output

If it is impossible to protect all sheep, output a single line with the word "No".

Otherwise, output a line with the word "Yes". Then print R lines, representing the pasture after placing dogs. Again, 'S' means a sheep, 'W' a wolf, 'D' is a dog and '.' an empty space. You are not allowed to move, remove or add a sheep or a wolf.

If there are multiple solutions, you may print any of them. You don't have to minimize the number of dogs.
Examples
Input
Copy

6 6
..S...
..S.W.
.S....
..W...
...W..
......

Output
Copy

Yes
..SD..
..SDW.
.SD...
.DW...
DD.W..
......

Input
Copy

1 2
SW

Output
Copy

No

Input
Copy

5 5
.S...
...S.
S....
...S.
.S...

Output
Copy

Yes
.S...
...S.
S.D..
...S.
.S...

Note

In the first example, we can split the pasture into two halves, one containing wolves and one containing sheep. Note that the sheep at (2,1) is safe, as wolves cannot move diagonally.

In the second example, there are no empty spots to put dogs that would guard the lone sheep.

In the third example, there are no wolves, so the task is very easy. We put a dog in the center to observe the peacefulness of the meadow, but the solution would be correct even without him.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll r,c;   cin>>r>>c;
    vector<vector<char>> v(r+1,vector<char> (c+1));
    
    for(ll i=1;i<=r;i++)
    {
        for(ll j=1;j<=c;j++)
        {
            char ch;    cin>>ch;
            v[i][j]=ch;
        }
    }
    
    for(ll i=1;i<=r;i++)
    {
        for(ll j=1;j<=c;j++)
        {
            //checking up
            if(i>=2 && v[i][j]=='S' && v[i-1][j]=='W')
            {
                cout<<"No";
                return 0;
            }
            //checking down
            if(i<=r-1 && v[i][j]=='S' && v[i+1][j]=='W')
            {
                cout<<"No";
                return 0;
            }
            //checking right
            if(j<=c-1 && v[i][j]=='S' && v[i][j+1]=='W')
            {
                cout<<"No";
                return 0;
            }
            //checking left
            if(j>=2 && v[i][j]=='S' && v[i][j-1]=='W')
            {
                cout<<"No";
                return 0;
            }
        }
    }
    
    cout<<"Yes"<<endl;
    for(ll i=1;i<=r;i++)
    {
        for(ll j=1;j<=c;j++)
        {
            if(v[i][j]=='.')
                cout<<"D";
            else
                cout<<v[i][j];
        }
        cout<<endl;
    }
    
    
    return 0;
}
