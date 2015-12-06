#!/usr/env/python

l = [2,5,8,4,7,2,2,5,0,9,9,0,6,7,4,5,2,1,4,6,7,8,7,3,5,4,8,7,8,9,4,3,6,3,6]

def bubble(lst):
    sorted = True
    for i in range(len(lst) - 1):
        if lst[i] > lst[i + 1]:
            temp = lst[i]
            lst[i] = lst[i + 1]
            lst[i + 1] = temp
            sorted = False
    if sorted:
        return lst
    else:
        return bubble(lst[:-1]) + [lst[-1]]

def bubble2(lst):
    if len(lst) >= 2:
        if lst[0] > lst[1]:
            temp = lst[0]
            lst[0] = lst[1]
            lst[1] = temp



for e in bubble(l):
    print(e)
