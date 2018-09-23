// C++ code to demonstrate sorting of a 
// 2D vector on basis of a column 
#include<iostream> 
#include<vector> // for 2D vector 
#include<algorithm> // for sort() 
using namespace std; 
  
// Driver function to sort the 2D vector 
// on basis of a particular column 

// struct coord { vector<string> arr; };
// struct Comparer : std::binary_function<coord,coord,bool> {
//     Comparer( int base ) : m_base( base ) {}
//     friend bool operator<( const coord &c1, const coord &c2 ) 
//     { 
//         return c1.arr[m_base] < c2.arr[m_base]; 
//     }
// private:
//     int m_base;
// };
//...
// std::sort( v.begin(), v.end(), Comparer( 1 ) );

struct Local {
    Local(int paramA) { this->paramA = paramA; }
    bool operator()( const vector<string>& v1,const vector<string>& v2 ) { 
        return v1[paramA] < v2[paramA]; 
    }   
    int paramA;
};

  
int main() 
{ 
    // Initializing 2D vector "vect" with 
    // values
    
    vector<vector<string> > vect;
    vector<string> temp;

    temp.push_back("gh");
    temp.push_back("cd");
    temp.push_back("ef");
    vect.push_back(temp);
    temp.clear();

    temp.push_back("mn");
    temp.push_back("ij");
    temp.push_back("kl");
    vect.push_back(temp);
    temp.clear();

    temp.push_back("ab");
    temp.push_back("op");
    temp.push_back("qr");
    vect.push_back(temp);
  
    // Number of rows; 
    int m = vect.size(); 
  
    // Number of columns (Assuming all rows 
    // are of same size).  We can have different 
    // sizes though (like Java). 
    int n = vect[0].size(); 
      
    // Displaying the 2D vector before sorting 
    cout << "The Matrix before sorting is:\n"; 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
            cout << vect[i][j] << "\t"; 
        cout << endl; 
    }     

    int col = 0;                           
  
    // Use of "sort()" for sorting on basis 
    // of 2nd column 
    sort(vect.begin(), vect.end(), Local(col)); 
  
    // Displaying the 2D vector after sorting 
    cout << "The Matrix after sorting is:\n"; 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
            cout << vect[i][j] << "\t"; 
        cout << endl; 
    } 
    return 0; 
} 