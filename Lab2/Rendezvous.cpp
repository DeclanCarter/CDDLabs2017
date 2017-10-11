/*! *Arthur: Declan Carter
 *Date Created: 6/10/17
 *Latest update: 11/10/17
 *Version 1.0.0
 *Copyright: MIT License
 
 *Using semaphores to schedule when threads proceed. Thread A1 will print out first, Thread B1 will print before Thread A2 and Thread B2 will print last.
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> sem1, std::shared_ptr<Semaphore> sem2){
  std::cout <<"A1 ";

  sem1->Signal();
  sem2->Wait();
  std::cout << "A2"<<std::endl;
  sem1->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> sem1, std::shared_ptr<Semaphore> sem2){
  sem1->Wait();
  std::cout <<"B1 ";
  sem2->Signal();
  sem1->Wait();
  std::cout << "B2"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  /**< Launch the threads  */
    threadOne=std::thread(taskTwo,sem1, sem2);
  threadTwo=std::thread(taskOne,sem1, sem2);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
