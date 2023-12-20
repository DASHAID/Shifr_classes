#include "euclid.h"

long long euclid(long long a, long long b)
{
    if (a < b)
    {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    int q = 0;
    long long U[] = { a, 1, 0 };
    long long V[] = { b, 0, 1 };
    long long T[] = { 0, 0, 0 };
    int k = 0;
    while (V[0] != 0)
    {
        q = U[0] / V[0];
        T[0] = U[0] % V[0];
        T[1] = U[1] - q * V[1];
        T[2] = U[2] - q * V[2];

        for (int i = 0; i < 3; i++)
            U[i] = V[i];
        for (int i = 0; i < 3; i++)
            V[i] = T[i];

    }

    if (U[2] < 0) U[2] += a;

    return U[2];

}