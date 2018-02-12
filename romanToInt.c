// Given an integer, convert it into roman numeral

int roman(char c)
{
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    
    //if(s.empty()) return 0;
        int sum = 0;
        while(*s)
        {
            int cur = roman(s[0]);
            int next = roman(s[1]);
            if(cur<next)
                sum = sum - cur;
            else
                sum = sum + cur;
            s++;
        }
        return sum;
}