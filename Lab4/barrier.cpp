/*! *Author: Declan Carter
 *Date Created: 20/10/17
 *Latest update: 26/10/17
 *Version 1.0.0
 *Copyright: MIT License
 
*

*/


#include "Semaphore.h"
#include <iostream>
#include <thread>
int threadCounter = 0;
int nThreads = 2;

void barrierTask(std::shared_ptr<Semaphore> Barrier, std::shared_ptr<Semaphore> Barrier2, std::shared_ptr<Semaphore> Mutex, int threadCounter, int nThreads)
{
  Mutex->Wait();
  std::cout<<threadCounter<<std::endl;
  threadCounter++;
  /*! checks if the counter is equal to the number of threads*/
  if(threadCounter == nThreads)
    {
      /*! using two barriers to implement a turnstile */
      std::cout<<"Counter is equal to N threads "<< nThreads<<std::endl;
      Barrier2->Wait();
      Barrier->Signal();
    }
  Mutex->Signal();
  Barrier->Wait();
  Barrier->Signal();
  std::cout<< "Allow through the second barrier "<<nThreads<<std::endl;
  Mutex->Wait();

  std::cout << "Counter value after the first barrier "<< threadCounter<< std::endl;
  threadCounter--;

  if(threadCounter == 0){
    Barrier->Wait();
    Barrier2->Signal();
    std::cout<<nThreads<<std::endl;
}
  Mutex->Signal();
  Barrier2->Wait();
  Barrier2->Signal();
  std::cout<<"After the second barrier "<< std::endl;
}

int main(void){
  
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> Mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> Barrier( new Semaphore);
  std::shared_ptr<Semaphore> Barrier2( new Semaphore(1));
  threadOne=std::thread(barrierTask, Mutex, Barrier, Barrier2, nThreads,threadCounter);
  threadTwo=std::thread(barrierTask, Mutex, Barrier, Barrier2, nThreads,threadCounter);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
