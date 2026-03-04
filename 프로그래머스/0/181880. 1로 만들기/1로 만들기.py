def solution(num_list):
    x = 0
    for i in num_list:
        n=i
        while n!=1:
            if n % 2 == 0 :
                n/=2
            else:
                n = (n-1)/2
            x+=1
    return x