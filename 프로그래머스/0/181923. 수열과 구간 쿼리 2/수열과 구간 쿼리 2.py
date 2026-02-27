def solution(arr, queries):
    list = []
    for s,e,k in queries:
        min = float('inf')
        for i in arr[s:e+1]:
            if i>k and i<min:
                min = i
        if min == float('inf'):
            min = -1 
        
        list.append(min)
    return list