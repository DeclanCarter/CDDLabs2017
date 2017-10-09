/*! A1 will print out first, B1 will print before A2 and B2 will print last.
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
