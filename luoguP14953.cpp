#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        int maxx = 0, minn = 0;
        maxx = n - 1;
        minn = n / 2;
        cout << maxx << " " << minn << endl;
    }
}