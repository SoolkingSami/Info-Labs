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


c1 = 'a'
c2 = 'i'
str1 = 'babaca'
print(iterative_substitute(str1, c1, c2))
print(recursive_substitute(str1, c1, c2))
