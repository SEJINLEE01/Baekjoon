def solution(code):
    result = ""
    mode = False
    i=0
    while len(code)!=i:
        if code[i]=="1":
            mode = not mode
            i+=1
            continue
        
        if not mode:
            if i%2==0:
                result += code[i]
        else:
            if i%2==1:
                result += code[i]
        
        i+=1
    return result if len(result)!=0 else "EMPTY"
        