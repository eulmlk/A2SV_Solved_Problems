class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

class BrowserHistory:
    def __init__(self, homepage: str):
        self.cur = ListNode(homepage)
    
    def visit(self, url: str) -> None:
        node = ListNode(url)
        self.cur.next = node
        node.prev = self.cur
        self.cur = node
    
    def back(self, steps: int) -> str:
        while steps > 0 and self.cur.prev:
            self.cur = self.cur.prev
            steps -= 1
        
        return self.cur.val
    
    def forward(self, steps: int) -> str:
        while steps > 0 and self.cur.next:
            self.cur = self.cur.next
            steps -= 1
        
        return self.cur.val
