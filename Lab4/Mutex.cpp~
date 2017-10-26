/*! *Arthur: Declan Carter
 *Date Created: 6/10/17
 *Latest update: 11/10/17
 *Version 1.0.0
 *Copyright: MIT License
 
*Using semaphores to show mutal exclusion

*/


#include "Semaphore.h"
#include <iostream>
#include <thread>
int counter = 0;

void taskOne(std::shared_ptr<Semaphore> mutex){
  
  mutex->Wait();
  std::cout<<counter<<std::endl;
  counter++;
  std::cout<<"Increment Counter"<<std::endl;
  mutex->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> mutex){
  mutex->Wait();
  std::cout<<counter<<std::endl;
  counter= counter+1;
  std::cout<<"Increment Counter"<<std::endl;
  mutex->Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex( new Semaphore(5));
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo, mutex);
  threadTwo=std::thread(taskOne, mutex);
  std::cout << "Finish";
  threadOne.join();
  threadTwo.join();
  std::cout<< counter<<std::endl;
  return 0;
}
