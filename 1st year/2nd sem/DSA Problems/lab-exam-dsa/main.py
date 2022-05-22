def swap_char(string, c1, c2):
    # noul string (empty initial)
    string_new = ""
    # verificam fiecare char din string
    for c in string:
        # daca c este c1 (care trebuie inlocuit)
        if c == c1:
            # adaugam in noul string c2 (cel prin care se inlocuieste)
            string_new += c2
        # altfel
        else:
            # adaugam c in noul string
            string_new += c

    return string_new


def swap_char_filter(string, c1, c2):
    string_new = map(lambda c: c if c != c1 else c2, string)
    return "".join(string_new)


def remove_odds(vec):
    return list(filter(lambda x: x % 2 == 0, vec))


def count_occurrences(vec, item):
    count = 0
    for x in vec:
        if x == item:
            count += 1
    return count


def count_occ(vec, item):
    return vec.count(item)


def check_key(dict_input, key):
    return key in dict_input


def reverse_str(string):
    if string:
        return reverse_str(string[1:]) + string[0]
    else:
        return ""


# print(reverse_str("abbac"))

def iterative_substitute(string, old, new):
    for i in range(len(string)):
        if string[i] == old:
            string = string[:i] + new + string[i+1:]
    return string


def recursive_substitute(string, old, new):
    if string == '':
        return ''
    if string[0] == old:
        return new + recursive_substitute(string[1:], old, new)
    return string[0] + recursive_substitute(string[1:], old, new)


def count_items(string, types):
    return len(list(filter(lambda x: x in types, string)))


def sum_rec(n):
    if n == 0:
        return 0
    else:
        return n + sum_rec(n - 1)


def sum_cif_rec(n):
    if n != 0:
        return n % 10 + sum_cif_rec(n // 10)
    else:
        return 0


def prod_cif_rec(n):
    if n != 0:
        return n % 10 * prod_cif_rec(n // 10)
    else:
        return 1


# print(sum_cif_rec(1120))

# print("ana" == reverse_str("ana"))

# print(count_items("ana ana ana", " "))

def fac_rec(n):
    if n == 1:
        return 1
    else:
        return n * fac_rec(n - 1)


# print(fac_rec(5))

# print(reverse_str(str(1234)))

string = "ana"
string = str(string[0].upper()) + string[1:]
print(string)


# print(sum_rec(10))

# n = 256
# print(bin(n).replace("0b", ""))
# print(oct(n).replace("0o", ""))
# print(hex(n).replace("0x", ""))

# print(count_items("abbacci", "aeiou"))

# c = "a"
# if c in "aeiou":
#     print("vocala")
# else:
#     print("consoana")

# x = [1, 2, 1, 3, 4]
# x = [x[-2], x[-1]] + x[:-2]
# print(x)

# c1 = 'a'
# c2 = 'i'
# str1 = 'babaca'
# print(iterative_substitute(str1, c1, c2))
# print(recursive_substitute(str1, c1, c2))

# given_dict = {"a": 1, "b": 3, "c": 8}
# print(check_key(given_dict, "a"))

# nr = "120.0"
# try:
#     float(nr)
#     print("Convertible to float")
# except ValueError:
#     print("Not convertible to float")

# print(count_occurrences([1, 2, 1, 2, 1, 3, 4], 1))
# print(remove_odds([1, 2, 3, 4, 5]))
# print(count_occ([1, 2, 1, 1, 3], 1))

# print(swap_char("abbac", "a", "b"))
# print(swap_char_filter("abbac", "a", "b"))

# A = int(input("A="))
# B = int(input("B="))
# A = 70
# B = 40
# C = 30
# #algoritmul de interschimbare
# T = A
# A = B
# B = C
# C = T

# afișarea rezultatelor
# print("A =",A)
# print("B =",B)
# print("C =",C)


# lista = [1,2,3,4,5,4,3,2,1]
# #șterg primul element ce conține 2
# lista.remove(2)
# #afișez iar lista
# print(lista)
# #șterg primul element
# del lista[0]
# print(lista)

# a = int(input("Enter the number to find odd "))
# if (a % 2) == 0:
#     print("{0} is Odd".format(a))
