#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include "IsSquare.h"

int main()
{
    std::vector < int > v = { 1, 5, 3, 8, 34, 64, 0, 5, 3, 6, 8, 4, 16, 9, 12, 144, 625 };

    for( int & val : v )
        std::cout << val << ' ';
    std::cout << std::endl;

    int k = 5;

    IsSquare < int > square;

    std::transform( v.begin(), v.end(), v.begin(), [ &k, &square ]( int & val )
    {
        if( square( val ) )
            return val * k;
        else
            return val;
    } );

    for( int & val : v )
        std::cout << val << ' ';
    std::cout << std::endl;

    std::cout<< "Count of squares: " << square.getCount() << std::endl;

}
