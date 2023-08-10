# LEETCODE 215  - Kth Largest Element in an Array //Difficulty - Medium
# Problem Statement - 
# Given an integer array and an integer k, return the kth largest element in the array.
# Note that it is the kth largest element in the sorted order, not the kth distinct element.
# Can you solve it without sorting?

import heapq

class Solution :
    def find_Kth_Largest_Element(k,array):
        if(k>len(array)):
            print("Error ; k exceeds array size.")
            return -1
        min_heap= []
        for i in range (k) :
            heapq.heappush(min_heap,array[i])
        for i in range(k,len(array)):
            if(array[i]>min_heap[0]):
                heapq.heappop(min_heap)
                heapq.heappush(min_heap,array[i])
        
        return min_heap[0]
    
    sample_array = [3, 2, 2, 7, 5, 2, 9, 6]
    k = 3
    result = find_Kth_Largest_Element(k,sample_array)
    print(result)
    