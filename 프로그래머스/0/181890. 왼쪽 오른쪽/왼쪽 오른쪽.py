def solution(str_list):
    if "l" not in str_list and "r" not in str_list:
        return []
    
    idx = -1
    
    for i,c in enumerate(str_list):
        if c == 'l':
            return str_list[:i]
        elif c == 'r':
            return str_list[i+1:]
            