#ifndef __SINGLETON_STUB__HPP
#define __SINGLETON_STUB__HPP

#include "Singleton.hpp"


namespace stubs
{
  //class SingletonStub;
  //SingletonClass SingletonStub::getInstance();

  class SingletonStub: public SingletonClass
  {
    public:
      static SingletonClass* getInstance()
      {
        std::cout << std::endl << "stub getinstance is called" << std::endl;
        if ( 0 == m_instance )
        {
          m_instance = new SingletonStub;
        }
        return m_instance;
      }
  };
}

SingletonClass::SingletonClass()
  : m_stubUsed(true)
{
  std::cout << std::endl << "constructor in stub file is called" << std::endl;
}

SingletonClass::~SingletonClass()
{
  if ( 0 != m_instance )
  {
    delete m_instance;
  }
  m_instance = 0;
}

SingletonClass* SingletonClass::getInstance()
{
  std::cout << std::endl << " we are in good place..." << std::endl;
  return stubs::SingletonStub::getInstance();
}


#endif

