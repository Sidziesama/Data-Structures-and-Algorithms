# LEETCODE 9 ; Easy ; Palindrome Number

# Problem Statement:
# Check if a number is palindrome or not
# Basic Idea : Number = 156 ; Number = 1 * 10^2 + 5 * 10^1 + 6 * 10^0

class Solution(object):
    def isPalindrome(number):
        original_number = number
        print("Original Number = " + str(original_number))
        if(number<0):
            return False
        reverse_number = 0
        count = 0
        while (number > 0):
            last_digit = number % 10
            count=count+1
            number = number // 10
        i=0
        number = original_number
        while(i<count):
            last_digit = number % 10
            reverse_number = reverse_number + ((10**(count-i-1)) * last_digit)
            number = number // 10
            i=i+1
        print("Reverse Number = " + str(reverse_number))
        if (reverse_number == original_number):
            return True
        else:
            return False

    number = -1221
    result = isPalindrome(number)
    print("Is Palindrome ? \n" +str(result))
