def solution(strArr):
    lst = []
    for s in strArr:
        if "ad" not in s:
            lst.append(s)
    return lst