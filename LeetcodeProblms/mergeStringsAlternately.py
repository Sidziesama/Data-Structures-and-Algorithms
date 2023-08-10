#LEETCODE 1768 Easy ; Merge two Strings Alternately

class Solution(object):
    def mergeAlternately( word1, word2):
        length = max(len(word1),len(word2))
        word1_length = len(word1)
        word2_length = len(word2)
        merged_word = ''

        for i in range(0,length):
            if (word1_length > 0 ):
                merged_word = merged_word + word1[i]
                word1_length = word1_length - 1

            if (word2_length > 0 ):
                merged_word = merged_word + word2[i]
                word2_length = word2_length - 1
        return merged_word
    
    word1 = "abcd"
    word2 = "A"
    print("The Merged String is : ", mergeAlternately(word1,word2))