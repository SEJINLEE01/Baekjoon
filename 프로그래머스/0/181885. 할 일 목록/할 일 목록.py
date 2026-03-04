def solution(todo_list, finished):
    result = []
    for i,b in enumerate(finished):
        if b == False:
            result.append(todo_list[i])
    return result