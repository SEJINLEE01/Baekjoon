def solution(strArr):
    lst = []
    for i,n in enumerate(strArr):
        if i % 2 == 0:
            lst.append(strArr[i].lower())
        else:
            lst.append(strArr[i].upper())
    return lst