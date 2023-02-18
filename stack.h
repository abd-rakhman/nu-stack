
#ifndef STACK_ 
#define STACK_  1

#include <string>
#include <algorithm>
#include <iostream>

class stack 
{
   size_t sz;
   size_t cap; 

   std::string* data; 
      // INVARIANT: data is an allocated memory block
      // with size cap, and cap is a power of two.
      // We are not sharing our allocated data with any other data 
      // structure. We also preserve the global variant: All 
      // allocated blocks of memory 
      // are reachable from a live variable through valid pointer
      // applications.

   void ensure_capacity( size_t c );
       // Ensure that cap >= c. Moreover, cap must be a power of two.

public:
   stack( );
      // Default stack is empty. Only write a default constructor if there
      // is a natural default value. In this case there is one. 

   stack( const stack& s );
   const stack& operator = ( const stack& s );
   ~stack( );

   void push( const std::string& val );

   const std::string& peek( ) const;

   void pop( );

   void clear( );

   void reset( size_t s ); 

   size_t size( ) const; 

   bool empty( ) const; 

   stack( std::initializer_list< std::string > values );

   void push( std::initializer_list< std::string > values ); 

   void print( std::ostream& out ) const;

   friend int main( int argc, char* argv[] );
}; 

inline std::ostream& operator << ( std::ostream& out, const stack& st )
{
   st. print( out );
   return out;
}

#endif


