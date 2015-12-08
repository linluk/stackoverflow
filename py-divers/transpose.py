#!/usr/bin/env python

# http://stackoverflow.com/questions/34153628/adding-items-to-a-list-by-checking-if-the-index-exists-and-then-updating

def transpose(strlist):
    result = []
    for i in range(len(strlist)):
        for j in range(len(strlist[i])):
            if len(result) > j:
                result[j] = result[j] + strlist[i][j]
            else:
                result.append(strlist[i][j])
    return result

print(transpose(['transpose', '', 'list', 'of', 'strings']))
