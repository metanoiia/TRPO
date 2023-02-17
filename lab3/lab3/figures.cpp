#include "figures.h"

Figure::Figure( float var1, float var2, float var3 )
    : m_var1( var1 ), m_var2( var2 ), m_var3( var3 ) {}

Figure::Figure( float var ) : Figure( ) { m_var1 = var; }

Figure::Figure() : m_var1( 0 ), m_var2( 0 ), m_var3( 0 ) {}

std::string Figure::myTypeIs()
{
    std::string typeName( typeid ( *this ).name() );
    return typeName.substr( 1, typeName.length() - 1 ); // substr to avoid results like 7Pyramid, 6Figure etc
}

float Figure::var1() const { return m_var1; }
float Figure::var2() const { return m_var2; }
float Figure::var3() const { return m_var3; }



float Pyramid::calculateArea()
{
    float majorSideLen = m_var1;
    float minorSideLen = m_var2;
    float height = m_var3;

    float apothem = std::sqrt( std::pow( ( majorSideLen / 2  - minorSideLen / 2 ), 2 )
                             + std::pow( height, 2 ) );

    float result = 2 * ( majorSideLen + minorSideLen ) * apothem
            + std::pow( minorSideLen, 2 ) + std::pow( majorSideLen, 2 );

    return result;
}



float Prism::calculateArea()
{
    float sideLen = m_var1;
    float normalLen = m_var2; // lenght of normal to side
    float height = m_var3; //figure height

    return sideLen * normalLen + 3 * sideLen * height;
}



float Sphere::calculateArea()
{
    float radius = m_var1;

    return 4 * pi * radius;
}
