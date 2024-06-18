#include <iostream>
#include <thread>
#include <mutex>

int main() {
    int counter = 0;
    std::mutex mtx;  // Mutex to protect the counter

    auto work = [&counter, &mtx]() {
        for (int i = 0; i < 100000; i++) {
            std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
            counter += 1;
        }
    };

    std::thread t1(work);
    std::thread t2(work);
    t1.join();
    t2.join();

    std::cout << counter << '\n';
    return 0;
}
