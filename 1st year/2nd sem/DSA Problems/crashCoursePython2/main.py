# class MyClass:
#     """A simple example class"""
#     num = 41
#
#     def greet(self):
#         return "Hello World!"
#
#
# x = MyClass()
# print(type(x.greet))
# print(type(MyClass.greet))

# class Point:
#     def __init__(self, x, y):
#         self.x = x
#         self.y = y
#
#     def __add__(self, other):
#         return Point(self.x + other.x, self.y + other.y)
#
#     def __str__(self):
#         return f"({self.x}, {self.y})"
#
#
# p1 = Point(2, 3)
# p2 = Point(4, 5)
#
# print(p1 + p2)

import numpy as np

# arr = np.fromiter((x * x for x in range(10)), int)
# matrix = np.fromiter((x * y for x in range(3) for y in range(3)), int).reshape(3, 3)
# print(arr.shape)
# print(matrix.shape)
# print(matrix)

# arr = np.array([[1, 2, 3], [4, 5, 6]])
# sumOnAxis = np.sum(arr, axis=0)
# print(sumOnAxis)

arr = np.array([[1, 2, 3], [4, 5, 6]])
val = np.array([1, -1, 1])
print(arr + val)
