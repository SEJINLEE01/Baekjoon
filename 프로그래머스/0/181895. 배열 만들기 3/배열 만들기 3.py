def solution(arr, intervals):
    result = []
    for i in intervals:
        a,b = i
        result.extend(arr[a:b+1])
    return result
        