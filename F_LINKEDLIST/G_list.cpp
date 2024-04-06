// C++ program to demonstrate the implementation of List
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

// function for printing the elements in a list
void showlist(list<int> g)
{
	list<int>::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}
//  functions : push_back   inserts at last
//  push_front  inserts at end
//  front()  returns first element
//  back()  return last element
//  pop_front()  removes first element
//  pop_back()   removes last element
//  reverse()  reverse the list
//  sort()  sort the list



// Driver Code
int main()
{
	list<int> list1,list2;
	for (int i = 0; i < 10; ++i) {
		list1.push_back(i * 2);
		list2.push_front(i * 3);
	}
	cout << "\nList 1 (gqlist1) is : ";
	showlist(list1);

	cout << "\nList 2 (gqlist2) is : ";
	showlist(list2);

	cout << "\ngqlist1.front() : " << list1.front();
	cout << "\ngqlist1.back() : " << list1.back();

	cout << "\ngqlist1.pop_front() : ";
	list1.pop_front();
	showlist(list1);

	cout << "\ngqlist2.pop_back() : ";
	list2.pop_back();
	showlist(list2);

	cout << "\ngqlist1.reverse() : ";
	list1.reverse();
	showlist(list1);

	cout << "\ngqlist2.sort(): ";
	list2.sort();
	showlist(list2);

    list2.clear();
	return 0;
}
