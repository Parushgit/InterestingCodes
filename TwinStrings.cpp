// Distinct strings with odd and even changes allowed.
// Given an array of lower case strings, the task is to find the number of strings that are distinct. Two strings are distinct if on applying the following operations on one string the second string cannot be formed.

// A character on odd index can be swapped with another character at odd index only.
// A character on even index can be swapped with another character on even index only.

string hashString(string str)
{
    int hashE[26] = {0}; // Using to hash even characters
    int hashO[26] = {0}; // Using to hash odd characters
    string hashing = "";
    
    for(int i = 0; i < str.length(); i++)
    {
        if(i%2 != 0)
            hashO[str[i] - 'a']++;
        else
            hashE[str[i] - 'a']++;
    }
    
    // Building the hash string in order to match. They will be equal if strings are convertable according to the logic provided in the           question
    for(int i = 0; i < 26; i++)
    {
        hashing += to_string(hashE[i]);
        hashing += to_string(hashO[i]);
    }
    
    return hashing;
}
vector <string> twins(vector < string > a, vector < string > b) {
    
    vector<string> result;
    for(int i = 0; i < a.size(); i++)
    {
        // If sizes don't match, it is a clear case of "No".
        if(a.at(i).length() != b.at(i).length()) 
        {
            result.push_back("No");
            continue;
        }
        
        if(hashString(a.at(i)) == hashString(b.at(i)))
            result.push_back("Yes");
        else
            result.push_back("No");

    }
    return result;
}
