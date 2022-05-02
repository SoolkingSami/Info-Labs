# check if array is sorted using divide and conquer

def is_sorted(array):
    if len(array) < 2:
        return True
    else:
        if array[0] <= array[1]:
            return is_sorted(array[1:])
        else:
            return False


arr_not_sorted = [1, 3, -4, 2, 5, -6]
print(f"{arr_not_sorted} is {'' if is_sorted(arr_not_sorted) else 'not '}sorted")

arr_sorted = [-1, 2, 3, 4, 5, 6]
print(f"{arr_sorted} is {'' if is_sorted(arr_sorted) else 'not '}sorted")
