#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int p[121] = {0};
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p[x]++;
    }
    int ans = 0;
    for(int i = 120; i > 0; i--)
    {
        if(p[i] > 0)
        {
            ans += p[i];
            if(ans >= k)
            {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}