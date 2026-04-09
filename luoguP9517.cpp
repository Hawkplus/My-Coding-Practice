#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(n);
    int start = 0, end = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1&&!flag)
        {
            start = i;
            end = start;
            flag = true;
        }
        if(a[i] == 1&&flag)
        {
            end = i;
        }
    }
    int ans = 0;
    ans = end - start + 1;
    cout << ans << endl;
}