# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

#You need to define a valid password for an email but the only restrictions are:
#The password must contain one uppercase character
#The password should not have numeric digit
#Now, given a String, find the length of the longest substring which is a valid password. For e.g Input Str = "a0Ba" , the output should be 2 as "Ba" is the valid substring.

def solution(S):
    # write your code in Python 3.6
    l, r, maximum = 0, 0, 0
    while(r < len(S)):
        while(r < len(S)) and S[r].isdigit(): #checking if the number is a digit
            r = r+1
        upper = False
        l = r
        
        while(r < len(S)) and not S[r].isdigit(): #checking if the number is not a digit
            if(S[r].isupper()): #checking if the number is a upper case character
                upper = True
            r = r+1
        
        if upper:
            maximum = max(maximum, r - l) #computing the maximum in order to get the longest substring
        
    return -1 if maximum == 0 else maximum
        
    pass