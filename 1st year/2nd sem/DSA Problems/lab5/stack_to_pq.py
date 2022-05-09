from enum import Enum
from queue import PriorityQueue, LifoQueue


class Type(Enum):
    Bill = 1
    Postcard = 2
    Holiday_Letter = 3
    Advertisement = 4

    def __lt__(self, other):
        return self.value < other.value

    def __str__(self):
        return self.name


class Item:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __lt__(self, other):
        return self.key < other.key

    def __str__(self):
        return f"{self.key}: {self.value}"


st = LifoQueue()
pq = PriorityQueue()

# Demo data
st.put(Item(Type.Bill, 'Energy bill'))
st.put(Item(Type.Postcard, 'Postcard from home'))
st.put(Item(Type.Holiday_Letter, 'Holiday letter from Miami'))
st.put(Item(Type.Advertisement, 'Advertisement for new Asus laptop'))
st.put(Item(Type.Bill, 'Water bill'))
st.put(Item(Type.Holiday_Letter, 'Holiday letter from Dubai'))

print("Stack:")
while not st.empty():
    item = st.get()
    print(item)
    pq.put(item)

print("\nPriority Queue:")
while not pq.empty():
    print(pq.get())
