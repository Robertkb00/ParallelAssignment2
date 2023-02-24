#include <iostream>
#include <cstdlib>
#include <array>
#include <mutex>
#include <chrono>

//Define a number of guests
#define GUEST_COUNT 40

//Keep track of status of guests and cupcake plate
std::array<bool, GUEST_COUNT> guestsCalled;
std::mutex camera;
bool plateEmpty = false;
int guestCounter = 0;
int activeThread;

void checkPlate()
{
  while(guestCounter < GUEST_COUNT)
  {
    camera.lock();
    if(activeThread == 0)
    {
      //Refill Plate if empty
      if(plateEmpty)
      {
        guestCounter++;
        plateEmpty = false;
      }
      
      //Eat first cupcake to verify system functions
      if(!plateEmpty && !guestsCalled[0])
      {
        guestCounter++;
        plateEmpty = false;
        guestsCalled[0] = true;
      }
     camera.unlock();
    }
  }
}

void enterLabyrinth(int threadNum)
{
  while(guestCounter < GUEST_COUNT)
  {
    camera.lock()
    if(activeThread == threadNum && !plateEmpty && !guestsCalled[threadNum])
    {
      plateEmpty = true;
      guestsCalled[threadNum] = true;
      std::cout << "Guest " << threadNum << " has eaten a cupcake!" << std:endl
    }
    camera.unlock();
  }  
}  

int main ()
{
  auto startTime = std::chrono::high_resolution_clock::now();
  
  std::array<std::thread, GUEST_COUNT> threads{};
  threads[0] = std::thread(checkPlate);
  
  for(size_t i = 1; i < threads.size(); i++)
    threads[i] = std::thread(enterLabyrinth, i);
  
  while(guestCounter < GUEST_COUNT)
  {
    int randomCall = rand();
    activeThread = randomCall % 50 + 1;
  }
  
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(end - start);
  
  std::cout << "All " << guestCounter << " guests have travled through the labyrinth." << std::endl;
  std::cout << "Finished in " << duration.count() << "ms" << std::endl;
}
