def solution(a, b, c, d):
    dice = [a,b,c,d]
    count = {x : dice.count(x) for x in set(dice)}
    if len(count) == 1:
        return 1111*a
    elif 3 in count.values():
        p = [k for k, v in count.items() if v == 3][0]
        q = [k for k, v in count.items() if v == 1][0]
        return (10 * p + q)**2
    elif len(count) == 2 and 2 in count.values():
        p, q = count.keys()
        return (p+q)*abs(p-q)
        
    elif len(count) == 3:
        other = [k for k, v in count.items() if v == 1]
        return other[0] * other[1]
    elif len(count) == 4:
        return min(dice)