def solution(num_list):
    str_odd = ""
    str_even = ""
    
    for x in num_list:
        if x%2==0:
            str_even += str(x)
        else:
            str_odd += str(x)
    
    return eval(f"{str_even}+{str_odd}")
        