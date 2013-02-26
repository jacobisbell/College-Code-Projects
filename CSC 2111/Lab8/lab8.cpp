/*--- lab8.cpp -------------------------------------------------------

  A study of STL's vector container

  Lab #8

  Add your name(s) here and other info requested by your instructor.

   Jacob Isbell
   Savannah Nolen

 --------------------------------------------------------------------------*/


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream & operator<<(ostream & out, const vector<T> & v)
/*-------------------------------------------------------------------------
  Overloaded output operator for vector<T>s.

  Precondition:  ostream out is open.
  Postcondition: Elements of v have been output to out and out is returned.
 --------------------------------------------------------------------------*/
{
   for (int i = 0; i < v.size(); i++)
      out << v.operator[](i) << "  ";
   return out;
}

int main()
{
   // Declare 6 vectors v1, v2, v3, v4, v5, v6 to illustrate the
   // various types of declarations (and constructors)
   vector<int> v1;
   vector<int> v2(4);
   int numInts;
   cout << "Enter capacity of v3: ";
   cin >> numInts;
   vector<int> v3(numInts);
   vector<int> v4(3, 50);
   // The preceding declaration should work, but it may not in some
   // versions of some compilers. The following is a work-around:
   // vector<int> v4(2);
   // for (int i = 0; i < 2; i++)  v4[i] = 50;
   //--- End of work-around

   int a[] = {1, 12, 30, 52, 66};
   vector<int> v5(a, a + 5);
   vector<int> v6;

   //--- 1 --- Add:
   // Statements to display the capacity and size of each vector<int>
   // and whether it is empty
   
   cout << "v1" << endl;
   cout << "Capacity: " << v1.capacity() << endl;
   cout << "Size:     " << v1.size() << endl;
   cout << "Is empty: " << v1.empty() << endl << endl;

   cout << "v2" << endl;   
   cout << "Capacity: " << v2.capacity() << endl;
   cout << "Size:     " << v2.size() << endl;
   cout << "Is empty: " << v2.empty() << endl << endl;

   cout << "v3" << endl;   
   cout << "Capacity: " << v3.capacity() << endl;
   cout << "Size:     " << v3.size() << endl;
   cout << "Is empty: " << v3.empty() << endl << endl;

   cout << "v4" << endl;   
   cout << "Capacity: " << v4.capacity() << endl;
   cout << "Size:     " << v4.size() << endl;
   cout << "Is empty: " << v4.empty() << endl << endl;
   
   cout << "v5" << endl;
   cout << "Capacity: " << v5.capacity() << endl;
   cout << "Size:     " << v5.size() << endl;
   cout << "Is empty: " << v5.empty() << endl << endl;
   

   //--- 2 --- Add:
   // Statement to display the maximum capacity of a vector<int>
   cout << "Max size: " << v1.max_size() << endl << endl;

   //--- 3 --- Add:
   // Statements to see the effect of the reserve() member function
   cout << "v4" << endl;
   v4.reserve(6);
   cout << "Capacity: " << v4.capacity() << endl;
   cout << "Size:     " << v4.size() << endl;

   //--- 4 --- Add:
   // Output statements of the form   cout << vector-variable << endl;
   // to display the contents of each vector
   
   cout << "v1: " << v1 << endl;
   cout << "v2: " << v2 << endl;
   cout << "v3: " << v3 << endl;
   cout << "v4: " << v4 << endl;
   cout << "v5: " << v5 << endl;


   //--- 5 --- Add:
   // Statements to append 111 to v2 and then output v2's size and contents
   //               append 222 to v2 and then output v2's size and contents
   //               append 333 to v2 and then output v2's size and contents
   //               remove the last element of v2 and then output v2's size
   //               and contents
	
   cout << endl;
   v2.push_back(111);
   cout << "Size of v2: " << v2.size() << endl;
   cout << "Contents of v2: " << v2 << endl;
   
   cout << endl;
   v2.push_back(222);
   cout << "Size of v2: " << v2.size() << endl;
   cout << "Contents of v2: " << v2 << endl;

   cout << endl;
   v2.push_back(333);
   cout << "Size of v2: " << v2.size() << endl;
   cout << "Contents of v2: " << v2 << endl;  
   
   cout << endl;
   v2.pop_back();
   cout << "Size of v2: " << v2.size() << endl;
   cout << "Contents of v2: " << v2 << endl;


   //--- 6 --- Statements to investigate how capacities grow
   // Add statements to append 99 to v1 and then output v1's capacity, size,
   // and contents
   cout << endl;
   v1.push_back(99);
   cout << "Size of v1: " << v1.size() << endl;
   cout << "Capacity of v1: " << v1.capacity() << endl;
   cout << "Contents of v1: " << v1 << endl;


   //--- 7 --- Statements to investigate how capacities grow
   // Add statements to append 101, 202, 303, 404, and 505 to v1 and output
   // v1's capacity, size, and contents after each value is appended
   
   cout << "Appending Values to v1" << endl << endl;
   
   cout << endl;
   v1.push_back(101);
   cout << "Size of v1: " << v1.size() << endl;
   cout << "Capacity of v1: " << v1.capacity() << endl;
   cout << "Contents of v1: " << v1 << endl;

   cout << endl;
   v1.push_back(202);
   cout << "Size of v1: " << v1.size() << endl;
   cout << "Capacity of v1: " << v1.capacity() << endl;
   cout << "Contents of v1: " << v1 << endl;
   
   cout << endl;
   v1.push_back(303);
   cout << "Size of v1: " << v1.size() << endl;
   cout << "Capacity of v1: " << v1.capacity() << endl;
   cout << "Contents of v1: " << v1 << endl;
   
   cout << endl;
   v1.push_back(404);
   cout << "Size of v1: " << v1.size() << endl;
   cout << "Capacity of v1: " << v1.capacity() << endl;
   cout << "Contents of v1: " << v1 << endl;
   
   cout << endl;
   v1.push_back(505);
   cout << "Size of v1: " << v1.size() << endl;
   cout << "Capacity of v1: " << v1.capacity() << endl;
   cout << "Contents of v1: " << v1 << endl;


   //--- 8 --- Statements to investigate how capacities grow
   // Remove the comment delimiters from the following:

   int oldCapacity = v1.capacity();
   cout << "(old) v1.capacity() = " << oldCapacity << endl;
   for (int i = v1.size() + 1; i <= 2500; i++)
   {
      v1.push_back(99);
      if (v1.capacity() == v1.size())
         cout << "\n*** v1 is full with " << v1.size() << " elements\n";
      if (v1.capacity() > oldCapacity)
      {
         cout << "Adding additional one element increases capacity from "
              << oldCapacity << " to " << v1.capacity() << endl;
         oldCapacity = v1.capacity();
      }
   }


   //--- 9 --- Statements to see if element type affects how capacities grow
   // Add:
   //    A declaration of an empty vector<double> v0;
   //    A loop like the preceding but with v1 replaced by v0
   //
   
   cout <<endl << endl;
   cout << "--------------------------- VECTOR DOUBLE ------------------------" << endl << endl;
   
   
   vector<double> v0;
   
   double oldCapacity0 = v0.capacity();
   cout << "(old) v0.capacity() = " << oldCapacity0 << endl;
   for (int i = v0.size() + 1; i <= 2500; i++)
   {
      v0.push_back(99);
      if (v0.capacity() == v0.size())
         cout << "\n*** v0 is full with " << v0.size() << " elements\n";
      if (v0.capacity() > oldCapacity0)
      {
         cout << "Adding additional one element increases capacity from "
              << oldCapacity0 << " to " << v0.capacity() << endl;
         oldCapacity0 = v0.capacity();
      }
   }


   //--- 10 --- Statements to see how initial capacity affects
   //           how capacities grow
   //
   // Uncomment the following line:
   cout << "Initial capacity of v4 is " << v4.capacity() << endl;
   
      cout <<endl << endl;
   cout << "--------------------------- V4 ------------------------" << endl << endl;
   
   double oldCapacity4 = v4.capacity();
   cout << "(old) v4.capacity() = " << oldCapacity4 << endl;
   for (int i = v4.size() + 1; i <= 2500; i++)
   {
      v4.push_back(99);
      if (v4.capacity() == v4.size())
         cout << "\n*** v4 is full with " << v4.size() << " elements\n";
      if (v4.capacity() > oldCapacity4)
      {
         cout << "Adding additional one element increases capacity from "
              << oldCapacity4 << " to " << v4.capacity() << endl;
         oldCapacity4 = v4.capacity();
      }
   }

   // Add a loop like that in 9 but output changes in v4's capacity


   //--- 11 --- Statements to access the ends of a vector

   // Uncomment the following line:
   cout << "Original contents of v5: " << v5 << endl;

   // Add statements to:

   //    Output the first and last elements of v5
   cout << endl;
   cout << "v5 front: " << v5.front() << endl;
   cout << "v5 back : " << v5.back() << endl;

   //    Change the first element to 787 and the last element to 878
   v5.front() = 787;
   v5.back() = 878;

   //    Output the contents of v5
   cout << endl;
   cout << "v5 front: " << v5.front() << endl;
   cout << "v5 back : " << v5.back() << endl;

   //--- 12 --- Statements to demonstrate correct and incorrect
   //           use of the subscript operator
   // Add statements that try using the subscript operator to:
   //            change the value in location 2 of v2 to 200

   v2[2] = 200;
   cout << endl;
   cout << "v2: " << v2 << endl;

   //            append the value 300 to v2
   
   v2[v2.size()] = 300;
   cout << endl;
   cout << "v2: " << v2 << endl;
   
   for (int i = 0; i <=v2.size(); i++)
   {
      cout << v2[i] << " =  ";
   }
   cout << endl;
   
   cout << "v2" << endl;   
   cout << "Capacity: " << v2.capacity() << endl;
   cout << "Size:     " << v2.size() << endl;
   

}
















