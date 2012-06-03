#include <cxxtest/TestSuite.h>

#define private public

#include "SingletonStub.hpp"

class MyTestSuite : public CxxTest::TestSuite 
{
  public:

    void testStub()
    {
      SingletonClass * singleton = SingletonClass::getInstance();
      TS_ASSERT_EQUALS(true, singleton->m_stubUsed);
    }

};



