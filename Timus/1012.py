#!/usr/bin/env python
# coding=utf-8

A, B = [], []
n = int(raw_input())
k = int(raw_input())

for i in xrange(2000):
    A.append(0), B.append(0)

B[1] = k - 1

for i in xrange(2, n + 1, 1):
    A[i] = B[i - 1];
    B[i] = (k - 1) * (A[i - 1] + B[i - 1])

print A[n] + B[n]
    
