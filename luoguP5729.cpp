#include <iostream>
using namespace std;
int main()
{
    int w, x, h;
    cin >> w >> x >> h;
    bool V[w+1][x+1][h+1] = {false};
    int ans = w*x*h;
    int q;
    cin >> q;
    while(q--)
    {
        int x1,y1,z1,x2,y2,z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++)
                for(int k = z1; k <= z2; k++)
                    V[i][j][k] = true;
    }
    int count = 0;
    for(int i = 1; i <= w; i++)
        for(int j = 1; j <= x; j++)
            for(int k = 1; k <= h; k++)
                if(V[i][j][k])
                    count++;
    ans = ans - count;
    cout << ans << endl;
}
