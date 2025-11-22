#include "String.hpp"

String::String( void ) {
    _size = 0;
    _buffer = new char[_size + 1];
}

String::String( char *s ) {
    _size = strlen(s);
    _buffer = new char[_size + 1];
    strncpy(_buffer, s, _size + 1);
}

String::~String( void ) {
    // delete[] _buffer;
}

String::String( const String& obj ) {
    _size = obj._size;
    _buffer = new char[_size + 1];
    strncpy(_buffer, obj._buffer, _size + 1);
}
