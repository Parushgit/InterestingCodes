#include<iostream>
#include<stdio.h>
#include<vector>
#include<sstream> 
#include<string> 
#include<ostream>
using namespace std;
string average(string time1, string time2)
{
    vector<int> time1variables;
    vector<int> time2variables;

    //PARSING THE STRING SEPARATED BY :
    istringstream input1(time1); 
    string number1; 
    while (getline(input1, number1, ':')) 
    { 
        std::istringstream iss(number1); 
        int i; 
        iss >> i; 
        time1variables.push_back(i); 
    } 

    //PARSING THE STRING SEPARATED BY :
    istringstream input2(time2); 
    string number2; 
    while (getline(input2, number2, ':')) 
    { 
        std::istringstream iss(number2); 
        int i; 
        iss >> i; 
        time2variables.push_back(i); 
    } 


    /* THE BELOW CODE IF COMMENTED FOR AVERAGE TO BE IN FLOATING NUMBER
    float fractionMinutes = 0, fractionSeconds = 0, fractionHundreds = 0;

    if((time1variables.at(0) % 2 != 0 && time1variables.at(0) % 2 == 0) || (time1variables.at(0) % 2 == 0 && time1variables.at(0) % 2 != 0))
        fractionMinutes = 0.5;
    if((time1variables.at(1) % 2 != 0 && time1variables.at(1) % 2 == 0) || (time1variables.at(1) % 2 == 0 && time1variables.at(1) % 2 != 0))
        fractionSeconds = 0.5;
    if((time1variables.at(2) % 2 != 0 && time1variables.at(2) % 2 == 0) || (time1variables.at(2) % 2 == 0 && time1variables.at(2) % 2 != 0))
        fractionHundreds = 0.5; */

    int minutes, seconds, hundreds; 

    hundreds = (time1variables.at(2) + time2variables.at(2)) / 2 % 100;

    //TERNARY OPERATOR
    seconds = ((time1variables.at(1) + time2variables.at(1)) / 2 >= 60) ? 
    ((time1variables.at(1) + time2variables.at(1))) / 2 % 60 + (((time1variables.at(2) + time2variables.at(2))) / 2 / 100) % 100 : 
    (time1variables.at(1) + time2variables.at(1)) / 2 + (((time1variables.at(2) + time2variables.at(2))) / 2 / 100) % 100 ;

    minutes = (time1variables.at(0) + time2variables.at(0)) / 2 + ((time1variables.at(1) + time2variables.at(1))) / 2 / 60;

    /*
    float fminutes, fseconds, fhundreds;
    fhundreds = (float)hundreds + fractionHundreds;
    fseconds = (float)seconds + fractionSeconds;
    fminutes = (float)minutes + fractionMinutes; */

    //STORING IN OUTPUT CHAR POINTER
    char *output;
    asprintf(&output, "%2.2d:%2.2d:%2.2d\n", minutes, seconds, hundreds);
    return output;
}
int main()
{
    string time1, time2;
    cin >> time1;
    cin >> time2;

    string avgtime = average(time1, time2);
    cout << avgtime;

}