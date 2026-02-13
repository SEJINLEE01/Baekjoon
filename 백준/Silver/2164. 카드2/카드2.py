# queue (FIFO)
class Node:
    def __init__(self,data):
        self.data=data
        self.next = None

class Queue:
    def __init__(self):
        self.head=None
        self.tail=None
        self.count = 0

    def push(self,data):
        new_node = Node(data)
        if self.empty() :
            self.head = new_node
            self.tail = new_node
        else :
            current = self.tail
            current.next = new_node
            self.tail = new_node
        self.count += 1

    def pop(self):
        if self.empty() :
            print("큐가 비어있음")
            return
        else :
            current = self.head
            data = current.data
            self.head = current.next
            current=None
            self.count -= 1
            return data

    def size(self):
        return self.count
        
    def empty(self):
        return self.head is None

    def front(self):
        return -1 if self.empty() else self.head.data 
    
    def back(self):
        return -1 if self.empty() else self.tail.data 
        
    def display(self):
        current = self.head
        while current != None :
            print(f"{current.data}|", end="")
            current = current.next
        print("None")
            
            
               
Q = Queue()
N = int(input())

for i in range(1,N+1):
    Q.push(i)

while Q.size()>1:
    Q.pop()
    if Q.size()==1:
        break
    Q.push(Q.pop())
    
print(Q.front())