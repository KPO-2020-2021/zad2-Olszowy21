#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"


TEST_CASE("Test LZespolona Równe") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;
 
   WARN_THROWS(x==y);
}

TEST_CASE("Test LZespolona minimalnie nierówne") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2.0002;
    y.im = 2.0002;
 
   WARN_THROWS(!(x==y));
}

TEST_CASE("Test LZespolona Nierówne") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 3;
    y.im = 3;
 
   WARN_THROWS(!(x==y));
}

TEST_CASE("Test LZespolona rząd mniejsze od minimalnej założonej różnicy") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2.00001;
    y.im = 2.00001;
 
   WARN_THROWS(x==y);
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
    z.im = 0;

    CHECK(x*y==z);
}
TEST_CASE("Test LZespolona mnożenie przez (0+1i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 1;

    z.re = 0;
    z.im = 1;

    CHECK(x*y==z);
}
TEST_CASE("Test LZespolona mnożenie przez (1 +1i)") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    z.re = 2;
    z.im = 2;

    CHECK(x*y==z);
}

