#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.6667;
    y.im = 0.6667;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez liczbę zespoloną") {
    LZespolona x, y, z;
    
    x.re = 10;
    x.im = 10;

    y.re = 5;
    y.im = 5;

    z.re = 2;
    z.im = 0;

    CHECK(x/y==z);
}

TEST_CASE("Test LZespolona Równe") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;
 
   CHECK(x==y);
}

TEST_CASE("Test LZespolona minimalnie nierówne") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2.0002;
    y.im = 2.0002;
 
   CHECK(!(x==y));
}

TEST_CASE("Test LZespolona Nierówne") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 3;
    y.im = 3;
 
   CHECK(!(x==y));
}

TEST_CASE("Test LZespolona rząd mniejsze od minimalnej założonej różnicy") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2.00001;
    y.im = 2.00001;
 
   CHECK(x==y);
}





TEST_CASE("Test LZespolona dodawanie (0 +0i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    z.re = 2;
    z.im = 2;

    CHECK(x+y==z);
}
TEST_CASE("Test LZespolona dodawanie (0.0 +0.0i)") {
    LZespolona x, y, z;
    
    x.re = 1.2;
    x.im = 1.2;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1.2;
    z.im = 1.2;

    CHECK(x+y==z);
}

TEST_CASE("Test LZespolona dodawanie (0,00001 +0,00001i)") {
    LZespolona x, y, z;
    
    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.00002;
    z.im = 0.00002;

    CHECK(x+y==z);
}


TEST_CASE("Test LZespolona dodawanie (0,00005 +0,00005i) dla minimalnej różnicy") {
    LZespolona x, y, z;
    
    x.re = 0.00005;
    x.im = 0.00005;

    y.re = 0.00005;
    y.im = 0.00005;

    z.re = 0.0001;
    z.im = 0.0001;

    CHECK(x+y==z);
}

TEST_CASE("Test LZespolona odejmowanie (0 +0i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    z.re = 2;
    z.im = 2;

    CHECK(x-y==z);
}

TEST_CASE("Test LZespolona odejmowanie (0.0 +0.0i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 2;
    z.im = 2;

    CHECK(x-y==z);
}

TEST_CASE("Test LZespolona odejmowanie (0.00001 +0.00001i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 1.99999;
    z.im = 1.99999;

    CHECK(x-y==z);
}

TEST_CASE("Test LZespolona odejmowanie (0.00001 +0.00001i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.00001;
    y.im = 0.00001;                  // NIE DOKOŃCZONE nie zrozumiałem pytania

    z.re = 1.99999;
    z.im = 1.99999;

    CHECK(x-y==z);
}

TEST_CASE("Test LZespolona mnożenie przez (0+0i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;

    CHECK(x*y==z);
}
TEST_CASE("Test LZespolona mnożenie przez (1+0i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 0;

    z.re = 2;
    z.im = 2;

    CHECK(x*y==z);
}
TEST_CASE("Test LZespolona mnożenie przez (0+1i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 1;

    z.re = -2;
    z.im = 2;

    CHECK(x*y==z);
}
TEST_CASE("Test LZespolona mnożenie przez (1 +1i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 4;

    CHECK(x*y==z);
    std::cout << "Jesteśmy po wyrażeniu check" << std::endl;
}
