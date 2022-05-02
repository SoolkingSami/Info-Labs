class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def add_multiple(self, data_list):
        for data in data_list:
            self.append(data)

    def remove_evens(self):
        cur_node = self.head
        prev_node = None
        while cur_node:
            if cur_node.data % 2 == 0:
                if prev_node is None:
                    self.head = cur_node.next
                else:
                    prev_node.next = cur_node.next
            else:
                prev_node = cur_node
            cur_node = cur_node.next

    def print_list(self):
        cur_node = self.head
        while cur_node:
            print(f"{cur_node.data}{' -> ' if cur_node.next is not None else ''}", end="")
            cur_node = cur_node.next
        print()


# sll_odd = SinglyLinkedList()
# sll_even = SinglyLinkedList()
# val = int(input("Enter a value to be appended: "))
# while val != -1:
#     if val % 2 == 0:
#         print(f"{val} is even so it will be appended to the even list")
#         sll_even.append(val)
#     else:
#         print(f"{val} is odd so it will be appended to the odd list")
#         sll_odd.append(val)
#     val = int(input("Enter a value to be appended: "))
#
# print("The odd list is: ")
# sll_odd.print_list()
# print("The even list is: ")
# sll_even.print_list()
