/**
 * Copyright (c) 2019 EG
 * Distributed under the MIT software license, see the accompanying
 * file LICENSE or http://www.opensource.org/licenses/mit-license.php
 */

#include <gmp.h>

class BigNumber
{
    public:
        static char* DivBN(char* number1, char* number2);
};

char* BigNumber::DivBN(char* number1, char* number2)
{
    mpz_t n1;
    mpz_init_set_str(n1, number1, 10);

    mpz_t n2;
    mpz_init_set_str(n2, number2, 10);

    mpz_t result;
    mpz_init(result);
    mpz_fdiv_q(result, n1, n2);

    return mpz_get_str(NULL, 10, result);
}