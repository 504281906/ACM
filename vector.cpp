#include <vector>
#include <iostream>
int main( )
{
   using namespace std;   
   vector <int> v1;
   vector <int>::size_type i;
   
   v1.push_back( 1 );
   i = v1.size( );
   cout << "Vector length is " << i << "." << endl;

   v1.push_back( 2 );
   i = v1.size( );
   cout << "Vector length is now " << i << "." << endl;
}
