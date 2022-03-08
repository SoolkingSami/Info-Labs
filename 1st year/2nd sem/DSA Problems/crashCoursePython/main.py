# result = isinstance(1, object)
# print(result)
#
#
# def compute(a, b, c):
#     return (a + b) * c
#
#
# print(compute(1, 2, 3))
# print(compute([1], [2, 3], 2))
# print(compute('1', 'olo', 3))

# x = 'hello world'
# y = 'hello'
# y += ' world'
#
# print(x == y)
# print(x is y)
#
# print(id(x))
# print(id(y))
#
# print([1, 2, 3] is [1, 2, 3])

# questions = ['name', 'quest', 'favorite color']
# answers = ['lancelot', 'the holy grail', 'blue']
#
# for q, a in zip(questions, answers):
#     print('What is your {0}? It is {1}.'.format(q, a))

# res = [x + y for (x, y) in zip([1, 2, 3], [4, 5, 6])]
# print(res)

# x = 2
#
#
# def foo(y):
#     z = 5
#     print(locals())
#     print(globals()['x'])
#     print(x, y, z)
#
#
# foo(3)

# def add(x, y):
#     """
#     Add two numbers together.
#     :param x:
#     :param y:
#     :return: x + y
#     """
#     return x + y
#
#
# print(add.__doc__)

# def get_ods(arr):
#     """
#     Get the odd numbers from an array.
#     :param arr:
#     :return: odd numbers from arr
#     """
#     return list(filter(lambda x: x % 2, arr))
#
#
# print(get_ods([1, 2, 3, 4, 5, 6, 7, 8, 9]))

# pairs = [(1, 9), (2, 4), (3, 6)]
# print(max(pairs, key=lambda x: x[1]))
# print(sorted(pairs, key=lambda x: x[1]))

# def length_of_all_elements(arr):
#     """
#     Get the length of all elements in an array.
#     :param arr:
#     :return: length of all elements in arr
#     """
#     return list(map(len, arr))
#
#
# print(length_of_all_elements(['hello', 'world']))

# def starts_with_m(arr):
#     """
#     Return iterable of elements from arr which starts with 'm'.
#     :param arr:
#     :return: iterable of elements from arr which starts with 'm'
#     """
#     return list(filter(lambda x: x.lower().startswith('m'), arr))
#
#
# print(starts_with_m(['hello', 'Marry', 'mars']))

def fib():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


def gen_under(n, gen):
    curr = next(gen)
    while curr < n:
        yield curr
        curr = next(gen)


g = fib()
print(list(gen_under(100, g)))
