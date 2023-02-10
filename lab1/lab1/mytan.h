#ifndef MYTAN_H
#define MYTAN_H

#include <math.h>
#include <string>
#include <exception>

namespace constants
{
    const float eps = 1.0e-5;
    const float pi = 3.14159265358979323846;
}


template < typename T >
class MyTan
{
public:
    enum type
    {
        div_by_zero,
        ambiguity,
        unknown
    };

    class TanExcept
    {
    public:
        TanExcept( int type ) : m_type( type ) {}

        std::string what() const
        {
            std::string res;

            switch ( m_type )
            {
            case div_by_zero:
                res = "division by zero is not allowed";
                break;

            case ambiguity:
                res = "there are ambiguity during division cos by sin";
                break;

            default:
                res = "unknown exception";
                break;
            }

            return res;
        }
    private:
        int m_type;
    };



    MyTan() : m_arg( T() ), m_except( unknown ), m_result( double() ) {}

    float operator()( T arg )
    {
        if( cos( arg ) <= constants::eps )
            throw m_except = TanExcept( div_by_zero );
        else
        {
            m_arg = arg;
            m_result = static_cast < float > ( sin( arg ) / cos( arg ) );
            return m_result;
        }
    }

    TanExcept exception() const { return m_except; }

private:
    T         m_arg;
    TanExcept m_except;

    double    m_result;
};

#endif // MYTAN_H
