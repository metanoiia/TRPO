#include <iostream>
#include <math.h>
#include "mytan.h"
#include "mylist.h"



int main()
{
    MyList < float > list;
    MyTan <float> tan;

    for( int i = 0; i < 10; i++ )
        list.append( float( i ) );

    list.append( constants::pi / 2 );

    std::cout << "size of list: " << list.size() << std::endl;

    std::cout <<"elements: ";

    for( float val : list )
        std::cout << val << " ";


    std::cout <<"tans of elements: ";
    try
    {
        for( float val : list )
            std::cout << tan( val );
    }
    catch ( const MyTan< float >::TanExcept &ex )
    {
        std::cout << std::endl;
        std::cout << tan.exception().what();
    }

    std::cout << std::endl;

    std::cout << "size before clean(): " << list.size() << std::endl;

    list.clear();

    std::cout << "size after clean(): " << list.size() << std::endl;

    return 0;
}
