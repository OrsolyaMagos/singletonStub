#include <cxxtest/TestSuite.h>

#define private public

#include "SingletonStub.hpp"

class MyTestSuite : public CxxTest::TestSuite 
{
  public:
    void testAddition()
    {
      TS_ASSERT( 1 + 1 > 1 );
      TS_ASSERT_EQUALS( 1 + 1, 2 );
    }

    void testStub()
    {
      SingletonClass * singleton = SingletonClass::getInstance();
      TS_ASSERT_EQUALS(true, singleton->m_stubUsed);
    }

};



