/*
 *   This file is part of the MLCL Library.
 *   Antoine Bastos 2022
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifndef MYLITTLECLIBRARY_MLCL_ALL_TESTS_H
#define MYLITTLECLIBRARY_MLCL_ALL_TESTS_H

#include "MLCL_TypeDescriptor_test.h"
/* Lists */
#include "Lists/MLCL_List_test.h"
#include "Lists/MLCL_ArrayList_test.h"
#include "Lists/MLCL_LinkedList_test.h"
#include "Lists/MLCL_CircularLinkedList_test.h"
#include "Lists/MLCL_DoubleLinkedList_test.h"
#include "Lists/MLCL_CircularDoubleLinkedList_test.h"
/* Trees */
#include "Trees/MLCL_BinarySearchTree_test.h"
#include "Trees/MLCL_AVLTree_test.h"

int run_all_tests();

#endif /* MYLITTLECLIBRARY_MLCL_ALL_TESTS_H */
