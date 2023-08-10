# LEETCODE 1 , Easy
# Problem Statement :
# Given an array of integers and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution:
    def twoSum(array, target):
        number_indices = []
        for i in range(0, len(array)):
            element = array[i]
            complement = target - element
            for j in range(i+1, len(array)):
                if (complement == array[j]):
                    number_indices.append(i)
                    number_indices.append(j)
                    return number_indices
        return number_indices
                    

    nums = [2, 7, 11, 15]
    target = 26
    result = twoSum(nums, target)
    print("Indices of the two numbers that add upto target :", result)
