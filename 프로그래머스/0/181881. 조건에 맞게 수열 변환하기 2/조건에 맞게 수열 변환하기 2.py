def solution(arr):
    
    x = 0
    while True:
        lst = []
        for i in arr:
            if i >=50 and i%2==0:
                lst.append(i/2)
            elif i<50 and i%2==1:
                lst.append(i*2+1)
            else:
                lst.append(i)
        x+=1
        
        if arr == lst:
            return x-1

        arr=lst[:]
        