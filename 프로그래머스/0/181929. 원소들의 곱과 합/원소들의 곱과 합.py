import math

def solution(num_list):
    return (lambda l: 1 if math.prod(l) < sum(l)**2 else 0)(num_list)