#include <string.h>
#include <iostream>
#include "Singleton.hpp"

SingletonClass* SingletonClass::m_instance;

SingletonClass::SingletonClass()
  : m_stubUsed(false)
{ 
  std::cout << std::endl << "OHHH... real singleton's constructor";
}


SingletonClass::~SingletonClass()
{ 
  std::cout << std::endl << "OHHH... real singleton's destructor";
  delete m_instance;
}


SingletonClass* SingletonClass::getInstance()
{
  std::cout << std::endl << "OHHH... real getinstance";
  if ( 0 == m_instance )
  {
    m_instance = new SingletonClass;
  }
  return m_instance;
}

