
#include "stack.h"
#include <string>

using namespace std;

void stack::ensure_capacity( size_t c ) 
{
   if(c <= cap) {
      return ;
   } else {
      size_t pw = 1;
      while(pw < c) {
         pw *= 2;
      }
      cap = pw;
      string *nw = new string[cap];
      copy(data, data + cap, nw);
      delete[] data;
      data = nw;
   }
   // We keep cap always in powers of two:
}

stack::stack( ){
   cap = 1;
   sz = 0;
   data = new string[cap];
}

stack::stack( const stack& s ){
   cap = s.cap;
   sz = s.sz;
   data = new string[cap];
   copy(s.data, s.data + cap, data);
}

const stack& stack::operator = ( const stack& s )
{
   ensure_capacity(s.sz);
   sz = s.sz;
   copy(s.data, s.data + cap, data);
   return *this;
}

stack::~stack( )
{
   sz = 0;
   cap = 0;
   delete[] data;
}

void stack::push( const std::string& val )
{
   ensure_capacity(sz + 1);
   data[sz++] = val;
}

void stack::pop( )
{
   if(sz == 0) {
      throw std::runtime_error( "pop: stack is empty" );
   } else {
      sz--;
   }
}

void stack::clear( )
{
   sz = 0;
}

void stack::reset( size_t s )
{
   sz = s;
}

const std::string& stack::peek( ) const
{
   if(sz == 0) {
      throw std::runtime_error( "pop: stack is empty" );
   } else {
      return data[sz - 1];
   }
}

size_t stack::size( ) const
{
   return sz;
}

bool stack::empty( ) const
{
   return sz == 0;
}

stack::stack( std::initializer_list< std::string > values )
{
   sz = values.size();
   cap = 1;
   data = new string[cap];
   ensure_capacity(sz);
   copy(values.begin(), values.end(), data);
}

void stack::push( std::initializer_list< std::string > values ) {
   ensure_capacity(sz + values.size());
   copy(values.begin(), values.end(), data + sz);
   sz += values.size();
}

void stack::print( std::ostream& out ) const 
{
   out << "stack: ";
   for(int i = 0; i < sz; i++) {
      if(i != 0) {
         out << " ";
      }
      out << data[i];
   }
   out << endl;
}