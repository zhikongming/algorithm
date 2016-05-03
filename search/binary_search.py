#!/usr/bin/env python
# -*- coding:utf-8 -*-

# Author: Zhiyang Zhao
# Date: 2016-5-24
# Release: 0.1

# We use two ways to do binary search
# One do call recursive method, the other one do not

def binary_search(number, search_list):
    first_index = 0
    last_index = len(search_list) -1
    while(first_index <= last_index):
        mid_index = int((first_index + last_index) / 2)
        if number < search_list[mid_index]:
            last_index = mid_index - 1
        elif number > search_list[mid_index]:
            first_index = mid_index + 1
        else:
            return mid_index
    return -1

def binary_search_recursion(number, search_list, first_index, last_index):
    if first_index > last_index:
        return -1
    mid_index = int((first_index + last_index) / 2)
    if number < search_list[mid_index]:
        return binary_search_recursion(number, search_list, first_index, mid_index - 1)
    elif number > search_list[mid_index]:
        return binary_search_recursion(number, search_list, mid_index + 1, last_index)
    else:
        return mid_index

def main():
    #Binary search need a array which is sroted, We use list instead
    test_list = [23, 45, 12, 3, 56, 74, 12]
    test_list.sort()
    print(test_list)
    search_number = 100
    #return_value = binary_search(search_number, test_list)
    return_value = binary_search_recursion(search_number, test_list, 0, len(test_list) - 1)
    if return_value != -1:
        print("Found %s: index is %s" % (search_number, return_value + 1))
    else:
        print("Not found in the list!")

if __name__ == "__main__":
    main()
