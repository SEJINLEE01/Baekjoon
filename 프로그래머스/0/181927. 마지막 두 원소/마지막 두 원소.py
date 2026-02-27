def solution(num_list):
    end_value = num_list[-1]
    end_value2 = num_list[-2]
    
    num_list.append(end_value-end_value2 if end_value>end_value2 else end_value*2)
    return num_list