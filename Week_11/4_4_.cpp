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

    
    TimerClass(TimerClass&& other) noexcept : timestamp(std::move(other.timestamp)) {
        std::cout << "Timer moved.\n";
        other.timestamp = nullptr; 
    }

    
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this != &other) {
            timestamp = std::move(other.timestamp);
            other.timestamp = nullptr; 
            std::cout << "Timer move-assigned.\n";
        }
        return *this;
    }

    
    ~TimerClass() {
        if (timestamp) {
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
    }
};

int main() {
    TimerClass t1;
    TimerClass t2 = std::move(t1); 

    TimerClass t3;
    t3 = std::move(t2);            

    

    return 0;
}