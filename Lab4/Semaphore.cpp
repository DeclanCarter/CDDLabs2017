/*! *Arthur: Declan Carter
 *Date Created: 6/10/17
 *Latest update: 11/10/17
 *Version 1.0.0
 *Copyright: MIT License
 
*Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

#include "Semaphore.h"


void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}


void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
