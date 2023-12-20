#include "Gen_key.h"
#include "max_del.h"
#include <random>
using namespace std;

Gen_key::Gen_key() {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist6(1000000, 2000000);
        prime_num = dist6(rng);
    }

long Gen_key::check_prime() {
        for (int i = 2; i < sqrt(prime_num); i++) {
            if (prime_num % i == 0) {
                prime_num++;
                i = 1;
            }
        }
        return prime_num;
    }

long Gen_key::gen_e(long long a) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1000000, 2000000);
    long long e = dist6(rng);
        while (max_del(e, a) != 1)
        {
            e += 1;
        }
        return e;
    }

long Gen_key:: get_key() {
        return prime_num;
    }

