#include<iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
std::ostream&
operator<<( std::ostream& dest, __int128 value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
typedef vector<__int128> v;
typedef vector<vector< __int128>> vv;

int main(void) {
    int n, m;
    cin >> n >> m;
    vv a = vv(n + 3, v(m + 3, 0));
    a[2][2] = 1;
    int tmp1 = 2, tmp2 = 2;
    while ((tmp1 < n + 1) || (tmp2 < m + 1))
    {
        if (tmp2 == m + 1) tmp1++;
        else tmp2++;
        int i = tmp1;
        int j = tmp2;
        while ((i <= n + 1) && j >= 2)
        {
            a[i][j] = a[i + 1][j - 2] + a[i - 1][j - 2] + a[i - 2][j - 1] + a[i - 2][j + 1];
            i++;
            j--;
        }
    }
    cout  << a[n + 1][m + 1];
    return 0;
}