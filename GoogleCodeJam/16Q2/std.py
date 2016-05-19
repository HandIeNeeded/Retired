#!/usr/bin/env python
# coding=utf-8

t = int(raw_input())
#print t
#print type(t)
while t:
    a, b = map(int, raw_input().split())
    print a / b
    t -= 1
