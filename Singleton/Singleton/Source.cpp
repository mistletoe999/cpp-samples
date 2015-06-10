#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>

template <typename T>
class Singleton
{
private:
    static std::unique_ptr<T> instance_;
    static std::once_flag once_;
    Singleton(const Singleton& source) = delete;
    Singleton& operator=(const Singleton& source) = delete;
    Singleton(Singleton&& source) = delete;
    Singleton& operator=(Singleton&& source) = delete;
protected:
    Singleton() 
    {
        std::cout << "Singleton Constructor called" << std::endl;
    }
public:
    virtual ~Singleton() 
    {
        std::cout << "Singleton Destructor called" << std::endl;
    }
    static T& instance()
    {
        std::call_once
            (Singleton::once_,
            []() { Singleton::instance_.reset(new T()); }
        );
        return *instance_;
    }
};

template<typename T>
std::unique_ptr<T> Singleton<T>::instance_;

template<typename T>
std::once_flag Singleton<T>::once_;


class IdGen : public Singleton < IdGen >
{
    static int64_t id_;
public:
    std::string new_id();
};

int64_t IdGen::id_ = 0;

std::string IdGen::new_id()
{
    ++id_;
    std::stringstream stream;
    stream << id_;
    return stream.str();
}

int main()
{
    std::cout << IdGen::instance().new_id() << std::endl;
    std::cout << IdGen::instance().new_id() << std::endl;
    std::cout << IdGen::instance().new_id() << std::endl;
    std::cout << IdGen::instance().new_id() << std::endl;
    std::cout << IdGen::instance().new_id() << std::endl;
    return 0;
}