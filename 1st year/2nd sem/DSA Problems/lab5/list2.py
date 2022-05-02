from list1 import SinglyLinkedList


def reverse_node_connections(node):
    """
    Reverse the connections of a node.
    """
    if node is None:
        return None
    if node.next is None:
        return node
    new_head = reverse_node_connections(node.next)
    node.next.next = node
    node.next = None
    return new_head


sll = SinglyLinkedList()
sll.add_multiple([1, 2, 3, 4, 5, 6])
sll.print_list()

# sll.head = reverse_node_connections(sll.head)
sll.remove_evens()
sll.print_list()
