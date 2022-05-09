def find_pair(nums, target):
    nums.sort()
    left, right = 0, len(nums) - 1
    pair = [nums[left], nums[right]]
    while left < right:
        pair = [nums[left], nums[right]] \
            if abs(nums[left] + nums[right] - target) < abs(pair[0] + pair[1] - target) \
            else pair
        if nums[left] + nums[right] == target:
            return [nums[left], nums[right]]
        elif nums[left] + nums[right] < target:
            left += 1
        else:
            right -= 1
    return pair


arr = [10, 22, 28, 29, 30, 40]
target_sum = 54
print(find_pair(arr, target_sum))
