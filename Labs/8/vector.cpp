#include "./vector.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
    vector<int> v;   //Our vector class
    std::vector<int> stdv; //Standard vector

    //Compare operation of our vector to std
    
    v.push_back(23);
    stdv.push_back(23);

    vector<int> v2;
    v2 = v;

    vector<int>v3 = v;

    cout << "Our vector size: " << v.size() << endl;
    cout << "STL vector size: " << stdv.size() << endl;
    cout << "Our second vector size: " << v2.size() << endl;
    cout << "Our third vector size: " << v3.size() << endl;
    ////cout << "Testing STL vector []: " << stdv[1] << endl;

    try{
        cout << " Testing v at index 1 (invalid): " << v[1] << endl;
    }
    catch(std::exception & oor){
        cout << oor.what() << endl;
    }

    try{
        cout << "Testing the existance of index 0 (invalid): " << v.at(1) << endl;
    }
    catch(std::exception & oor){
        cout << oor.what() << endl;
    }

    vector<int> v4(1);
    v4.push_back(23);
    v4.push_back(23);

    return 0;
}