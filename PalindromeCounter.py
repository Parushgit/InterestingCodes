#Given a string, the task is to count all palindrome substring in a given string. Length of palindrome substring is greater then or equal to 2.
def countPalindromes(s):
size = len(s)
answer = 0

for middle in xrange( 2 * size - 1):
    left = middle / 2
    right = left + middle % 2
    
    while left >=0 and right < size and s[left] == s[right]:
        answer += 1
        left   -= 1 # To check for left and see other palindrome numbers
        right  += 1 # To check for right and see other palindrome numbers
        
return answer