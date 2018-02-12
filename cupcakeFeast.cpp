// Little Bobby loves chocolate, and he frequently goes to his favorite  store, Penny Auntie, with  dollars to buy chocolates. Each chocolate has a flat cost of  dollars, and the store has a promotion where they allow you to trade in  chocolate wrappers in exchange for  free piece of chocolate.

// For example, if  and Bobby has  dollars that he uses to buy  chocolates at  dollar apiece, he can trade in the  wrappers to buy  more chocolates. Now he has  more wrappers that he can trade in for  more chocolate. Because he only has  wrapper left at this point and , he was only able to eat a total of  pieces of chocolate.

// Given , , and  for  trips to the store, can you determine how many chocolates Bobby eats during each trip?

// Input Format

// The first line contains an integer, , denoting the number of trips Bobby makes to the store. 
// Each line  of the  subsequent lines contains three space-separated integers describing the respective , , and values for one of Bobby's trips to the store.

// Constraints

// Output Format

// For each trip to Penny Auntie, print the total number of chocolates Bobby eats on a new line.

// Sample Input

// 3
// 10 2 5
// 12 4 4
// 6 2 2
// Sample Output

// 6
// 3
// 5
// Explanation

// Bobby makes the following  trips to the store:

// He spends his  dollars on  chocolates at  dollars apiece. He then eats them and exchanges all  wrappers to get  more chocolate. We print the total number of chocolates he ate, which is .
// He spends his  dollars on  chocolates at  dollars apiece; however, he needs  wrappers to trade for his next chocolate. Because he only has  wrappers, he cannot purchase or trade for any more chocolates. We print the total number of chocolates he ate, which is .
// He spends  dollars on  chocolates at  dollars apiece. He then exchanges  of the  wrappers for  additional piece of chocolate. Next, he uses his third leftover chocolate wrapper from his initial purchase with the wrapper from his trade-in to do a second trade-in for  more piece of chocolate. At this point he has  wrapper left, which is not enough to perform another trade-in. We print the total number of chocolates he ate, which is .



void maximumCupcakes(vector < string > trips) {
    
    vector<int> result;
    int n;
    for(int i = 0; i < trips.size(); i++)
    {
        std::istringstream iss(trips.at(i)); // Converting string digits to integer numbers
        while(iss >> n)
        {
            result.push_back(n); //Doing this in order to store n, c and m values in a result vector
        }
    }
    
    for(int i = 0; i < result.size(); i = i + 3) // Iterating over a counter increment of 3 since n, c and m are there.
    {
        int number, wrapper = 0;
        number = result.at(i) / result.at(i+1);
        wrapper = number;
        while(wrapper >= result.at(i+2))
        {
            number = number + (wrapper / result.at(i+2));
            wrapper = wrapper/result.at(i+2) + (wrapper % result.at(i+2));
        }
        cout << number << endl;
