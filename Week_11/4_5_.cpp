#include <iostream>
#include <sys/time.h>
#include <memory>
#include <string>

struct TimerClass {
    std::shared_ptr<timeval> timestamp;
    std::string name;

    
    TimerClass(const char* timer_name = "Unnamed Timer")
        : timestamp(std::make_shared<timeval>()), name(timer_name) {
        gettimeofday(timestamp.get(), nullptr);
        std::cout << "Timer [" << name << "] started.\n";
    }

    
    TimerClass(const TimerClass& other)
        : timestamp(other.timestamp), name(other.name) {
        std::cout << "Timer [" << name << "] copied.\n";
    }

    
    TimerClass& operator=(const TimerClass& other) {
        if (this != &other) {
            timestamp = other.timestamp;
            name = other.name;
            std::cout << "Timer [" << name << "] assigned.\n";
        }
        return *this;
    }

    
    TimerClass(TimerClass&& other) noexcept
        : timestamp(std::move(other.timestamp)), name(std::move(other.name)) {
        other.timestamp = nullptr;
        std::cout << "Timer [" << name << "] moved.\n";
    }

    
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this != &other) {
            timestamp = std::move(other.timestamp);
            name = std::move(other.name);
            other.timestamp = nullptr;
            std::cout << "Timer [" << name << "] move-assigned.\n";
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

            std::cout << "Timer [" << name << "] lived for: "
                      << seconds << "s and " << microseconds << "μs\n";
        }
    }
};

int main() {
    TimerClass t1("Main Timer");

    {
        TimerClass t2("Inner Timer");
        TimerClass t3 = std::move(t2); 
    } 

    return 0;
}