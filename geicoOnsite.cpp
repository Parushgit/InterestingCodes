/*
from Crissey, Jack (internal) to Everyone:    7:29  AM
Two strings are anagrams if they have the same characters in the same frequency, but the characters are in a different order.  An example is bat and tab. 
Given a collection of strings, group the anagrams and return the number of groups formed. 
  
Example 
words = ["cat", "listen", "silent", "kitten", "salient"] 
  
Only silent and listen are anagrams. The last word, salient, contains an extra 'a'. No other words are anagrams, so there are 4 groups: [['silent', 'listen'], ['cat'], ['kitten'], ['salient']]. Return 4. 

Approach 1 - Use hashmap and hash the words
TC - O(N)
SC - O(N)

*/

class Anagram {
    public:
        Stringbuilder generateHashFromWord(String word) {
            Stringbuilder result = new Stringbuilder();
            for(Integer i = 0; i <= word.length(); i++) {
                freq[word[i] - 'a']++;
            }

            for(Integer i = 0; i < 26; i++) {
                result += freq[i].toString() + "#";
            }
            return result;
        }
        List<List<string>> generateAnagrams(String[] words) {
            Integer length = words.length();
            List<List<string>> groups = new List<List<string>>();
            Hashmap<String, List<string>> _hash = new Hashmap<String, List<string>>();
            for(Integer i = 0; i < length; i++) {
                _hash[generateHashFromWord(words[i])].insert(words[i]);
            }

            foreach row in _hash {
                groups.insert(row);
            }
            return groups;
        }
}

/*

For a string s and an integer k, a selection of substrings is valid if the following conditions are met: 
The length of every substring is greater than or equal to k 
Each substring is a palindrome. 
No two substrings overlap. 
  
Determine the maximum number of valid substrings that can be formed from s. 
  
Notes: 
A substring is a group of adjacent characters in a string. 
A palindrome is a string that reads the same backward as forward. 
  
Example 
s = "aababaabce" 
k = 3 
  
k = 3 -> aba, bab
a ababa abce 
a aba baab ce 
  
Any valid substring must be k or more characters long. Either 1 or 2 non-overlapping palindromes can be formed. Return 2, the maximum number that can be formed. 

Function Description 
Complete the function getMaxSubstrings in the editor below. 
  
getMaxSubstrings has the following parameters: 
    string s:  the given string 
    int k: the minimum length of a valid substring 
  
Returns 
    int: the maximum number of valid palindromic substrings that can be formed 

*/

class PalindromicSubstring {
    private:
        Integer result = 0;
        String word;
    public:
        // To check if a string is a palindrome
        // aba i = 0, j = 2, i = 1 and j = 1
        Boolean isAValidPalindrome(String input, Integer i, Integer j) {
            while(i < j) {
                if (input[i] ! input[j])
                    return false;
                i++;
                j--;
            }
            return true;
        }
        /*
        Example 
        s = "aababaabce" 
        i = 0 < n
        k = 3 
        */
        void generateSubstrings(String input, Integer start, Integer end, Integer k) {
            if (start == end)
                return;
            else {
                for(Integer i = start, i <= end; i++) {
                    word = input.substr(start, i - start + 1);
                    if (isAValidPalindrome(word, start, i) && word.length() >= k) {
                        result++;
                    }
                    generateSubstrings(input, i + 1, end, k);
                }
            }
            return;
        }

        Integer getMaximumValidPalindromicSubstrings(String input, Integer k) {
            // Base case;
            Integer n = input.length();
            if (n == 0)
                return result;
            if (n == 1)
                return n;

            // Generate the substrings
            generateSubstrings(String input, 0, n, k);
            return result;
        }
}