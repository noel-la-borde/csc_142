#include <iostream>
#include <sys/time.h> 
#include <ctime>

struct TimerClass {
    timeval timestamp;

    TimerClass() {
        gettimeofday(&timestamp, nullptr);
    }

    void printTimestamp() const {
        std::cout << "Seconds: " << timestamp.tv_sec << ", Microseconds: " << timestamp.tv_usec << "\n";
    }
};

int main() {
    TimerClass timer;
    timer.printTimestamp();
    return 0;
}