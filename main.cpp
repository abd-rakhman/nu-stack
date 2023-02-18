
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <stdexcept>

#include "stack.h"

// You may use this for testing:


void read_and_push( stack& s, std::ifstream& in )
{
   std::string str;

   int c = in. get( );

   while( in )
   {
      if( isspace(c))
      {
         if( str. size( ))
         {
            s. push( str );
            str. clear( );
         }
      }
      else
         str. push_back(c);
      c = in. get( );
   }

   if( str. size( ))
      s. push( str );
}



int main( int argc, char* argv [ ] )
{
#if 0
   stack st;
   st.push("1");
   st.push("2");
   st.push("3");
   st.push("4");
   st.push("5");
   st.push("6");
   st.push("7");
   st.push("8");
   st.push("9");
   st.push("10");
   st.push("11");
   st.push("12");
   st.push("13");
   st.push("14");
   st.push("15");
   st.push("16");
   st.push("17");
   st.push("18");
   st.push("19");
   st.push("20");
   std::cout << st;
#endif

#if 0
   stack st;
   st.push("1");
   st.push("2");
   st.push("3");
   std::cout << st;
   st.pop();
   st.push("4");
   st.push("5");
   st.push("6");
   st.pop();
   std::cout << st;
   st.push("7");
   st.push("8");
   st.push("9");
   while(!st.empty()) {
      st.pop();
      std::cout << st;
   }
#endif

#if 0
   stack st({"let’s", "start", "at", "the", "beginning"});
   st. push( { "a", "very", "good", "place", "to", "start" } );
   std::cout << st;
#endif


#if 0
   stack st = { "let’s", "start", "at", "the", "beginning" };
   st. push( { "a", "very", "good", "place", "to", "start" } );
   std::cout << st;
#endif
   // Read the file input.txt, and push the words in it
   // on the stack. You can use this test.

#if 0
   stack st;
   std::ifstream in( "input.txt" );
   if( !in )
   {
      std::cerr << "could not open input.txt\n"; 
      return -1;
   }
   read_and_push( st, in );
   std::cout << st << "\n";
   return 0;
#endif
#if 0
   stack st = stack({"let’s", "start", "at", "the", "beginning"});
   auto s1 = st;   // CC
   std::cout << s1 << "\n";
   auto st2 = st;  // CC 
   st = st2;       // Assignment 
   st = st;        // Self-assignment
   std::cout << st << "\n";
   return 0;
#endif 
}

