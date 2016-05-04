#!/usr/bin/env python
# -*- coding:utf-8 -*-

# Author: Zhiyang Zhao
# Date: 2016-5-4
# Release: 0.1

# Compute binomial distribution.

def binomial(count, happen_times, probality):
    if count == 0 and happen_times == 0:
        return 1;
    if count < 0 or happen_times < 0:
        return 0;
    return (1 - probality) * binomial(count - 1, happen_times, probality) + probality * binomial(count - 1, happen_times -1, probality) 

if __name__ == "__main__":
    print binomial(10, 5, 0.5)
