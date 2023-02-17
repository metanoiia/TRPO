#include <iostream>
#include <typeinfo>
#include "figures.h"
#include <time.h>



int main()
{
    Figure * pF;

    srand( time( NULL ) );

    switch ( rand() % 3 )
    {
    case 0:
    {
        pF = new Pyramid( 2, 1, 1 ); //maj = 2, mi = 1, height = 1
        Pyramid * pPyr = dynamic_cast < Pyramid * > ( pF );

        if( pPyr )
            std::cout << pPyr->myTypeIs() << " area is "
                      << pPyr->calculateArea() << std::endl;

        break;
    }
    case 1:
    {
        pF = new Prism( 2, 1, 1 );// side = 2, norm  = 1, height = 1
        Prism * pPrsm = dynamic_cast < Prism * > ( pF );

        if( pPrsm )
            std::cout << pPrsm->myTypeIs() << " area is "
                      << pPrsm->calculateArea() << std::endl;

        break;
    }
    case 2:
    {
        pF = new Sphere( 2 );// r = 2
        Sphere * pSp = dynamic_cast < Sphere * > ( pF );

        if( pSp )
            std::cout << pSp->myTypeIs() << " area is "
                      << pSp->calculateArea() << std::endl;
        break;
    }
    default:
        pF = nullptr;
        break;
    }

    return 0;
}



