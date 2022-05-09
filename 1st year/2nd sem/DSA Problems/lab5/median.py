arr1 = [1, 2, 3, 4, 5]
arr2 = [1, 4, 7, 8, 9, 10, 20, 30, 40, 50]


def median(vec1, vec2):
    vec1 += vec2
    vec1.sort()
    print(vec1)
    return vec1[len(vec1) // 2]


print(median(arr1, arr2))
