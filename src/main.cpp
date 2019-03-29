/**
 * Copyright (c) 2019 EG
 * Distributed under the MIT software license, see the accompanying
 * file LICENSE or http://www.opensource.org/licenses/mit-license.php
 */

#include <iostream>
#include <bignumber.h>

main(int argc, char *argv[])
{
    std::cout << printf("Division of %s by %s is %s\n", *(&argv[1]), *(&argv[2]), BigNumber::DivBN(*(&argv[1]), *(&argv[2])));

    return 0;
}