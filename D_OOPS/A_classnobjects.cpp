#include <iostream>
// class class_name{
//     access specifiers:
//     membernames and variable;
//     data_types methods(){

//     }
// };
#include <bits/stdc++.h>
using namespace std;
class Geeks
{
public: 
    //access specifiers are of 3 types public , private , protected
    // public means accessible to all'
    // private means accessible to only class itself
    // by default private;
    // accessible to child class also
    int id;
    //constructere are of 3 types : default,parametric , copy;
    //copy constructor creates oblect by  copying the data of another object

    Geeks(int n){
        cout<<"parametrized constructor is called\n";
        id = n;
    }
    Geeks(){
        cout<<"default constructor is called\n";
        //no need to define separately if any other constructer is not defined
    }
    // Definition for Destructor
    ~Geeks()
    {
        cout << "Destructor called for id: " << id << endl;
    }
};//obkect can be created at this place also before semicolon

int main()
{

    Geeks obj1;
    // Geeks obj1(3);
    // new keyword is used in case of pointers only
    obj1.id = 7;
    int i = 0;
    while (i < 5)
    {
        Geeks obj2;
        obj2.id = i;
        i++;
    } // Scope for obj2 ends here

    return 0;
} // Scope for obj1 ends here
