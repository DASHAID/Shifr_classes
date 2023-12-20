#include "max_del.h"

int max_del(int a, int b) {
    return b ? max_del(b, a % b) : a;
}
