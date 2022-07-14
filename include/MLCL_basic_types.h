/*
 *   This file is part of the MLCL Library.
 *
 *   Copyright (C) 2022 Antoine Bastos
 *
 *   This Library is free software under the terms of
 *   the MIT license.
 */

#ifndef MYLITTLECLIBRARY_MLCL_BASIC_TYPES_H
#define MYLITTLECLIBRARY_MLCL_BASIC_TYPES_H

#include "MLCL_TypeDescriptor.h"
#include <stdio.h>

/* ############## char ############## */
/**
 * @brief The char manifest assign its respective functions according
 * to the required ones by the type interface TypeDescriptor
 * @param type_descriptor
 */
void char_manifest(TypeDescriptor * type_descriptor);

/**
 * @brief
 * @param x
 * @param y
 * @return
 */
int char_cmp(const void * x, const void * y);

int char_eq(const void * x, const void * y);
int char_lt(const void * x, const void * y);
int char_le(const void * x, const void * y);
int char_gt(const void * x, const void * y);
int char_ge(const void * x, const void * y);

/**
 * @brief
 * @param x
 */
void char_print(const void * x);

/**
 * @brief
 * @param x
 * @param file
 */
void char_fprint(FILE * file, const void * x);

/**
 * Copy the given data to a new address
 * @param data data considered as a char
 * @return pointer to a new allocated copy of the given data
 */
void * char_copy(const void * data);

/**
 * @brief
 * @param x
 */
void char_free(void ** x);


/* ############## int ############## */
/**
 * @brief The int manifest assign its respective functions according
 * to the required ones by the type interface TypeDescriptor
 * @param type_descriptor
 */
void int_manifest(TypeDescriptor * type_descriptor);

/**
 * @brief
 * @param x
 * @param y
 * @return
 */
int int_cmp(const void * x, const void * y);

int int_eq(const void * x, const void * y);
int int_lt(const void * x, const void * y);
int int_le(const void * x, const void * y);
int int_gt(const void * x, const void * y);
int int_ge(const void * x, const void * y);

/**
 * @brief
 * @param x
 */
void int_print(const void * x);

/**
 *
 * @param x
 */
void int_fprint(FILE * file, const void * x);

/**
 * Copy the given data to a new address
 * @param data data considered as a int
 * @return pointer to a new allocated copy of the given data
 */
void * int_copy(const void * data);

/**
 * @brief
 * @param x
 * @param file
 */
void int_free(void ** x);

/* ############## float ############## */
/**
 * @brief The float manifest assign its respective functions according
 * to the required ones by the type interface TypeDescriptor
 * @param type_descriptor
 */
void float_manifest(TypeDescriptor * type_descriptor);

/**
 * @brief
 * @param x
 * @param y
 * @return
 */
int float_cmp(const void * x, const void * y);

int float_eq(const void * x, const void * y);
int float_lt(const void * x, const void * y);
int float_le(const void * x, const void * y);
int float_gt(const void * x, const void * y);
int float_ge(const void * x, const void * y);

/**
 * @brief
 * @param x
 */
void float_print(const void * x);

/**
 * @brief
 * @param x
  * @param file
 */
void float_fprint(FILE * file, const void * x);

/**
 * Copy the given data to a new address
 * @param data data considered as a float
 * @return pointer to a new allocated copy of the given data
 */
void * float_copy(const void * data);

/**
 * @brief
 * @param x
 */
void float_free(void ** x);

#endif /* MYLITTLECLIBRARY_MLCL_BASIC_TYPES_H */
