#include <iostream>
#include <cmath>
using namespace std;
int remain(int num)
{
    int sum = 0;
    while(num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main()
{
    int n,p;
    cin >> n >> p;
    int start = int(pow(10,n-1));
    int end = int(pow(10,n)) - 1;
    int minNum = remain(start)%p;
    int ans = start;
    for(int i = start; i <= end; i++)
    {
        if(remain(i) % p < minNum)
        {
            minNum = remain(i) % p;
            ans = i;
        }
    }
    cout << ans << endl;

}