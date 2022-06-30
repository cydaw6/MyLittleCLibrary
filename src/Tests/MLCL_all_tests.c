/*
 *   This file is part of the MLCL Library.
 *   Antoine Bastos 2022
 *
 *   This Library is free software under the terms of
 *   the MIT license.
 */

#include "../../include/Tests/MLCL_all_tests.h"
#include "../../include/Tests/MLCL_TypeDescriptor_test.h"
#include <stdio.h>

int run_all_tests(){
    printf("[Running all tests]\n");

    if(!run_all_type_descriptor_tests())
        return 0;

    if(!run_all_linked_list_tests())
        return 0;

    printf("All tests successfully passed.\n");
    return 1;
}