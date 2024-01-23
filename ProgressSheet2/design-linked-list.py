class MyLinkedList:

    class Node:
        def __init__(self, value = 0, nex = None):
            self.value = value
            self.next = nex

    def __init__(self):
        self.head = None
        self.size = 0
        

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        
        curNode = self.head
        while index > 0:
            curNode = curNode.next
            index -= 1
        
        return curNode.value
        

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.size, val)
        

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        
        dummy = self.Node(-1, self.head)
        cur = dummy

        for _ in range(index):
            cur = cur.next
        
        node = self.Node(val, cur.next)
        cur.next = node
        
        self.size += 1
        self.head = dummy.next
        

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        
        dummy = self.Node(-1, self.head)
        cur = dummy

        for _ in range(index):
            cur = cur.next
        
        cur.next = cur.next.next
        self.size -= 1
        self.head = dummy.next
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)