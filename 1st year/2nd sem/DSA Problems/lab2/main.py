# def get_mul_table(x):
#     for y in range(11):
#         yield f"{x} * {y} = {x * y}"
#
#
# n = int(input('Enter a number: '))
# mul_table_n = get_mul_table(n)
# for i in mul_table_n:
#     print(i)

# def is_prime(n):
#     if n <= 1:
#         return False
#     for di in range(2, n):
#         if n % di == 0:
#             return False
#     return True
#
#
# def get_prime_numbers_in_range(start, end):
#     for item in range(start, end + 1):
#         if is_prime(item):
#             yield item
#
#
# def get_prime_numbers_in_range_lambda(start, end):
#     return filter(lambda x:
#                   False if x <= 1 or any(x % d == 0 for d in range(2, x))
#                   else True,
#                   range(start, end + 1))
#
#
# a, b = map(int, input('Enter a range: ').split())
# # prime_numbers = get_prime_numbers_in_range(a, b)
# prime_numbers = get_prime_numbers_in_range_lambda(a, b)
# for i in prime_numbers:
#     print(i)

# n = int(input('Enter a number: '))
# # res = list(map(lambda x: 2 ** x, range(n + 1)))
# # print(res)
# prettify_res = list(map(lambda x: f"2 ** {x} = {2 ** x}", range(n + 1)))
# print('\n'.join(prettify_res))

import os
from functools import reduce
from math import cos, sin, log
from termcolor import colored


class ScientificCalculator:
    def __init__(self):
        self.operations = dict(
            add=lambda x, y: x + y,
            sub=lambda x, y: x - y,
            mul=lambda x, y: x * y,
            div=lambda x, y: x / y,
            mod=lambda x, y: x % y,
            pow=lambda x, y: x ** y,
            sqrt=lambda x: x ** 0.5,
            sin=lambda x: sin(x),
            cos=lambda x: cos(x),
            log=lambda b, x: log(x, b),
        )
        self.operations_str = [
            "add",
            "sub",
            "mul",
            "div",
            "mod",
            "pow",
            "sqrt",
            "sin",
            "cos",
            "log",
            "exit",
            "clear",
            "help",
        ]
        self.operations_str_help = {
            "add": "(a , b) -> a + b",
            "sub": "(a , b) -> a - b",
            "mul": "(a , b) -> a * b",
            "div": "(a , b) -> a / b",
            "mod": "(a , b) -> a % b",
            "pow": "(a , b) -> a ** b",
            "sqrt": "(a) -> a ** 0.5",
            "sin": "(a) -> sin(a), a in radians",
            "cos": "(a) -> cos(a), a in radians",
            "log": "(base , a) -> log(a, base), base in base 2, 10, 16",
        }

    def __calculate(self, operation, *args):
        return self.operations[operation](*args)

    def run(self):
        print(colored('Welcome to your pocket Scientific Calculator!', 'blue'))
        print('Please, choose an operation:')
        print(colored('  '.join(self.operations_str), 'green'))

        while True:
            operation = input('Enter operation :> ')
            if 'exit' in operation:
                break
            elif 'clear' in operation:
                os.system('cls')
            elif 'help' in operation:
                # check for global help for all operations
                print(colored('  '.join(self.operations_str), 'green'))
            else:
                try:
                    # safe guard against operation not in specified list of operations
                    if operation not in self.operations_str:
                        raise ValueError
                    # get the input arguments from stdin
                    args = list(map(str, input('Enter args :> ').split()))
                    # check for local help for the current operation
                    if 'help' in args:
                        print(colored(self.operations_str_help[operation], 'green'))
                    else:
                        # calculate the result
                        args = list(map(float, args))
                        print(self.__calculate(operation, *args))
                # catch occurring exceptions
                except ValueError:
                    print(colored('Invalid argument or operation! Please, enter a valid one!', 'red'))
                except TypeError:
                    print(colored('Invalid list of arguments! Please, enter a valid one!', 'red'))
                except ZeroDivisionError:
                    print(colored('Division by zero!', 'red'))
                except Exception as e:
                    print(colored(f'Unknown error: {e}', 'red'))


# os.system('color')
# calc = ScientificCalculator()
# calc.run()


def factorial_recursive(n):
    if n == 0:
        return 1
    return n * factorial_recursive(n - 1)


def factorial_iterative(n):
    res = 1
    return reduce(lambda x, y: x * y, range(1, n + 1), res)


# print(factorial_recursive(5))
# print(factorial_iterative(5))

# def get_matrix_transpose(matrix):
#     return list(map(list, zip(*matrix)))
#
#
# mrx = [[1, 2, 3],
#        [4, 5, 6],
#        [7, 8, 9]]
# mrx = get_matrix_transpose(mrx)
# for row in mrx:
#     print(row)

def get_union_of_lists(list1, list2):
    return list(set(list1 + list2))


def get_intersection_of_lists(list1, list2):
    # return list(set(list1) & set(list2))
    return list(filter(lambda x: x in list1, list2))


def get_difference_of_lists(list1, list2):
    # return list(set(list1) - set(list2))
    return list(filter(lambda x: x not in list2, list1))


# listA = [1, 2, 3, 4, 5]
# listB = [4, 5, 6, 7, 8, 9, 10]
# print(get_union_of_lists(listA, listB))
# print(get_intersection_of_lists(listA, listB))
# print(get_difference_of_lists(listB, listA))

def order_input(reverse=False):
    def sort_input(get_input):
        return ''.join(sorted(get_input(), reverse=reverse))

    return sort_input


# @order_input()
# def get_string():
#     return input('Enter a string :> ')


# get_string = order_input(reverse=True)(get_string)
# print(get_string)

def is_odd(x):
    return not is_even(x)


def is_even(x):
    if x == 0:
        return True
    if is_odd(x - 1):
        return True
    return False


print(is_odd(5))
print(is_even(5))
