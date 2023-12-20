#include "fast_pow.h"

 long long fast_pow(long long a, long long  x, long long p)
{
     long long y = 1, s = a;
    while (x > 0)
    {
        if (x % 2) y = (y * s) % p;
        s = (s * s) % p;
        x /= 2;
    }
    return y;
}

