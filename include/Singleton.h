#pragma once

#include <mutex>

template <typename T>
class Singleton
{
protected:
    Singleton()          = default;
    virtual ~Singleton() = default;

public:
    Singleton(const Singleton &)            = delete;
    Singleton(Singleton &&)                 = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    static T *getInstance()
    {
        if (m_instance == nullptr) {
            std::lock_guard<std::mutex> guard(m_mutex);
            if (m_instance == nullptr) {
                m_instance = new T();
            }
        }
        return m_instance;
    }

protected:
    static std::mutex m_mutex;
    static T         *m_instance;
};

template <typename T>
std::mutex Singleton<T>::m_mutex;

template <typename T>
T *Singleton<T>::m_instance = nullptr;
