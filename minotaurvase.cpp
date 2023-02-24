#include <iostream>
#include <cstdlib>
#include <array>
#include <mutex>
#include <thread>
#include <chrono>

//Define a number of guests
#define GUEST_COUNT 40

//False is available, true is busy
bool roomStatus = false;

//Keep track of guests
std::array<bool, GUEST_COUNT> guestsViewed;
std::mutex camera;
int guestCounter = 0;
int activeThread;

void viewVase(int threadNum)
{
    std::thread::id threadId = std::this_thread::get_id();

    while (guestsVisited.size() < NUM_GUESTS)
    {
        mutex.lock();

        if (!roomStatus && guestsViewed[threadId] == guestsVisited.end()) {
            roomStatus = true;
            std::cout << "Guest " << threadNum << " is admiring the crystal vase." << std::endl;
            int randomTime = rand();
            std::this_thread::sleep_for(std::chrono::milliseconds(randommTime % 100 + 10);
            roomStatus = Status::AVAILABLE;

            guestsVisited.insert(threadId);
        }

        mutex.unlock();
    }
}

int main()
{
  auto startTime = std::chrono::high_resolution_clock::now();
  
  std::array<std::thread, GUEST_COUNT> threads{};
  
  for(size_t i = 1; i < threads.size(); i++)
    threads[i] = std::thread(viewVase, i);
  
  for (auto& thread : threads)
    thread.join();
  
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::milli>(end - start);
  
  std::cout << "All " << guestCounter << " guests have travled through the labyrinth." << std::endl;
  std::cout << "Finished in " << duration.count() << "ms" << std::endl;
}
