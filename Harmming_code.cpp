#include <iostream>
#include <string>
#include <cstdio>  // 补上 printf 需要的头文件
using namespace std;
#include <bitset>

int main()
{
    int Harmming_num = 0;
    cin >> Harmming_num;
    bitset<11> two_num(Harmming_num);
    int p1 = 0, p2 = 0, p4 = 0, p8 = 0;
    p1 = two_num[0] ^ two_num[2] ^ two_num[4] ^ two_num[6] ^ two_num[8] ^ two_num[10];
    p2 = two_num[1] ^ two_num[2] ^ two_num[5] ^ two_num[6] ^ two_num[9] ^ two_num[10];
    p4 = two_num[3] ^ two_num[4] ^ two_num[5] ^ two_num[6];
    p8 = two_num[7] ^ two_num[8] ^ two_num[9] ^ two_num[10];
    int error_position = p1 * 1 + p2 * 2 + p4 * 4 + p8 * 8;
    if(error_position == 0)
    {
        //3 5 6 7 9 10 11
        cout << two_num[10] << two_num[9] << two_num[8] << two_num[6] << two_num[5] << two_num[4] << two_num[2] << endl;
    }
    else
    {
        two_num[error_position - 1] = !two_num[error_position - 1];
        cout << two_num[10] << two_num[9] << two_num[8] << two_num[6] << two_num[5] << two_num[4] << two_num[2] << endl;
    }

}