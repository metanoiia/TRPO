#ifndef FIGURES_H
#define FIGURES_H
#include <cmath>
#include <string>

class Figure
{
public:
    Figure( float var1, float var2, float var3 );
    Figure( float var );
    Figure();

    virtual float calculateArea() = 0;
    std::string myTypeIs();

    float var1() const;
    float var2() const;
    float var3() const;
protected:
    float m_var1,
          m_var2,
          m_var3;
};

class Pyramid : public Figure
{
public:
    using Figure::Figure;

    float calculateArea() override;
};

class Prism : public Figure
{
public:
    using Figure::Figure;

    float calculateArea() override;
};

class Sphere : public Figure
{
private:
    const float pi = 3.1415926535;
public:
    using Figure::Figure;

    float calculateArea() override;
};


#endif // FIGURES_H
