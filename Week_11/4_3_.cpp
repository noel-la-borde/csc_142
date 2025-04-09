#include <iostream>
#include <sys/time.h>
#include <memory> 

struct TimerClass {
    std::shared_ptr<timeval> timestamp;

    
    TimerClass() : timestamp(std::make_shared<timeval>()) {
        gettimeofday(timestamp.get(), nullptr);
        std::cout << "Timer started.\n";
    }

    
    TimerClass(const TimerClass& other) : timestamp(other.timestamp) {
        std::cout << "Timer copied.\n";
    }

    
    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            timestamp = other.timestamp;
            std::cout << "Timer assigned.\n";
        }
        return *this;
    }

    ~TimerClass() {
        timeval now;
        gettimeofday(&now, nullptr);

        long seconds = now.tv_sec - timestamp->tv_sec;
        long microseconds = now.tv_usec - timestamp->tv_usec;
        if (microseconds < 0) {
            seconds -= 1;
            microseconds += 1000000;
        }

        std::cout << "Timer lived for: " << seconds << "s and " << microseconds << "μs\n";
    }
};

int main() {
    TimerClass t1;
    TimerClass t2 = t1;         
    TimerClass t3;
    t3 = t1;                    

    return 0;
}