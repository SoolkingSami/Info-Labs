# define node class
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


# define doubly linked list class
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

    def insert_sum_and_diff(self):
        curr = self.head
        while curr.next:
            # calculate sum and difference nodes
            sum_node = Node(curr.data + curr.next.data)
            diff_node = Node(curr.data - curr.next.data)

            # insert sum node after curr
            sum_node.next = diff_node
            sum_node.prev = curr

            # insert diff node after sum node
            diff_node.next = curr.next
            diff_node.prev = sum_node

            # link diff node to curr.next
            curr.next.prev = diff_node
            # link sum node to curr
            curr.next = sum_node
            
            curr = diff_node.next
        self.tail = curr

    def print(self):
        curr = self.head
        while curr:
            print(f"{curr.data}{' <-> ' if curr.next is not None else ''}", end="")
            curr = curr.next
        print()


# create a doubly linked list
dll = DoublyLinkedList()
dll.append(2)
dll.append(3)
dll.append(1)
dll.append(4)

dll.print()

dll.insert_sum_and_diff()
dll.print()
