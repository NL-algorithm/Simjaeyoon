#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt = 0;
ll n, r, c;

void square(ll n, int row, int col)
{ // n:한변의 길이 , 시작하는 점
    if (n == 2)
    {
        if (row == r && col == c)
        {
            cout << cnt;
            return;
        }
        col++;
        cnt++;
        if (row == r && col == c)
        {
            cout << cnt;
            return;
        }
        col--;
        row++;
        cnt++;
        if (row == r && col == c)
        {
            cout << cnt;
            return;
        }
        col++;
        cnt++;
        if (row == r && col == c)
        {
            cout << cnt;
            return;
        }
        return;
    }
    else
    {
        if (r < row + n / 2 && c < col + n / 2)
        {
            square(n / 2, row, col);
            cnt++;
        }
        else
        {
            cnt += pow(n / 2, 2);
        }

        if (r < row + n / 2 && c >= col + n / 2)
        {
            square(n / 2, row, col + n / 2);
            cnt++;
        }
        else
        {
            cnt += pow(n / 2, 2);
        }

        if (r >= row + n / 2 && c < col + n / 2)
        {
            square(n / 2, row + n / 2, col);
            cnt++;
        }
        else
        {
            cnt += pow(n / 2, 2);
        }

        if (r >= row + n / 2 && c >= col + n / 2)
        {
            square(n / 2, row + n / 2, col + n / 2);
        }
        else
        {
            cnt += pow(n / 2, 2);
        }
        return;
    }
}

int main()
{
    cin >> n >> r >> c;

    square(pow(2, n), 0, 0);
}