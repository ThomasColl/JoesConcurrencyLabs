/*! \fn Barrier.cpp
    \brief The main method to deomonstrate how a barrier can operate in multithreaded code
    \author Thomas Coll
    Creation Date: 14/02/19
    License: Creative Commons

   Uses C++11 features such as mutex and condition variables to implement a barrier which will catch all threads

*/

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100; 
int sharedVariable=0;


/*! \fn barrierTask
    \brief An example of using a reusable barrier
*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task
    std::cout << "A"<< i;
    //Barrier
    theBarrier->Wait();
    //Do second half of task
    std::cout<< "B" << i;
  }
  

}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  //std::cout << sharedVariable << std::endl;
  return 0;
}
