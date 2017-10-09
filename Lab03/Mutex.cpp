#include "Semaphore.h"
#include <iostream>
#include <thread>
int counter = 0;

void taskOne(std::shared_ptr<Semaphore> mutex){
  
  mutex->Wait();
  counter++;
  std::cout<<"Print first"<<std::endl;
  mutex->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> mutex){
  mutex->Wait();
  counter= counter+1;
  std::cout<<"Print Second"<<std::endl;
  mutex->Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex( new Semaphore(5));
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo, mutex);
  threadTwo=std::thread(taskOne, mutex);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  std::cout<< counter<<std::endl;
  return 0;
}
