#include <iostream>
#include <sys/time.h> 

struct TimerClass {
    timeval start_time;

    TimerClass() {
        gettimeofday(&start_time, nullptr);
    }

    ~TimerClass() {
        timeval end_time;
        gettimeofday(&end_time, nullptr);

        long seconds = end_time.tv_sec - start_time.tv_sec;
        long microseconds = end_time.tv_usec - start_time.tv_usec;
        if (microseconds < 0) {
            seconds -= 1;
            microseconds += 1000000;
        }

        std::cout << "Timer lived for: " << seconds << "s and " << microseconds << "μs\n";
    }
};

int main() {
    {
        TimerClass timer;
        
        for (volatile int i = 0; i < 1000000; ++i);
    } 

    return 0;
}