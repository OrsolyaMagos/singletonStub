#ifndef __SINGLETON_CLASS_HPP
#define __SINGLETON_CLASS_HPP

class SingletonClass
{
  public:
    static SingletonClass* getInstance();
    ~SingletonClass();

  private:
    SingletonClass();
    SingletonClass(const SingletonClass& a);

    static SingletonClass* m_instance;
    bool m_stubUsed; ///> in case of real instance is used, it is false, in case of stub, it is true
};

#endif

