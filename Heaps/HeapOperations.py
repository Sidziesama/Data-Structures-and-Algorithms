import heapq
#HEAPS

# A heap is a complete binary tree where the parent is compared with it's children and arranged accordingly.A heap is a priority queue.
# There are two main types of heaps : 
# 1) Min Heap - the smallest element is arranged as the root.
# 2) Max Heap - the largest element is arranged as the root.
# We insert from the left to right , following the property of a complete binary tree. 
# I am using array representation of heaps. Let Number of nodes= 0,1,2,3,4,... n.
# A[0] = root node; The children nodes are : Left Node = A[2i+1] and  Right node = A[2i+2]; The elements are inserted in thsi order.
# Time complexity of heap operations : Insertion and Deletion : O(Logn) ; Space complexity: O(n)


# 1) Min Heap : A[i] < A[2i+1] and A[i] < A[2i+2] ; the parent node is always smaller than the child node.

# Creating min heap using heapq library and heapify method
min_heap = [5,3,6,1,7,11,54,4]
heapq.heapify(min_heap)

print("MIN HEAP: \n", min_heap)

# Insertion
print('INSERTION :')
insert_element_min_heap = 8
print("Inserting element "+str(insert_element_min_heap)+" into the min heap")
heapq.heappush(min_heap,insert_element_min_heap)

print("Min Heap after Insertion :" ,min_heap)

# Pop smallest / root element
min_element_min_heap = heapq.heappop(min_heap)
heapq.heapify(min_heap)

print("Min Heap after popping smallest element :" , min_heap)


# 2) Max Heap : A[i]  > A[2i+1] and A[i] > A[2i + 2] ; the parent node is always greater than the child node. 

# Creating Max Heap by negating all elements and then using heapq.heapify to create a heap. Undoing the negation once the heap is created.
max_heap = [12,16,11,19,18,10,17,15,22]
max_heap = [-x for x in max_heap]
heapq.heapify(max_heap)
max_heap = [-x for x in max_heap]

print("MAX HEAP :\n " ,max_heap)

# Insertion
print('INSERTION :')
insert_element_max_heap = 13
print("Inserting element "+str(insert_element_max_heap)+" into the max heap")

max_heap = [-x for x in max_heap]
heapq.heappush(max_heap,-(insert_element_max_heap))
max_heap = [-x for x in max_heap]

print("Max Heap after Insertion :" ,max_heap)

# Pop largest / root element
max_element_max_heap = heapq.heappop(max_heap)
max_heap = [-x for x in max_heap]
heapq.heapify(max_heap)
max_heap = [-x for x in max_heap]
print("Max Heap after popping largest element :" , max_heap)




