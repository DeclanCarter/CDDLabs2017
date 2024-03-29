/*! *Arthur: Declan Carter
 *Date Created: 6/10/17
 *Latest update: 11/10/17
 *Version 1.0.0
 *Copyright: MIT License
 
*Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

#include <mutex>
#include <condition_variable>
#include <chrono>

class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    void Signal();

};
