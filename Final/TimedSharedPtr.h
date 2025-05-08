#ifndef TIMEDSHAREDPTR_H
#define TIMEDSHAREDPTR_H
#include <iostream>
#include <chrono>
using Clock = std::chrono::high_resolution_clock;
typedef std::chrono::time_point<Clock> clockTime;
typedef std::chrono::milliseconds milliSeconds;

// This block tracks pointers, ref count, and expiration time
struct ControlTimedSharedPtr {
    void* ptr;
    long count;
    clockTime createdAt;
    milliSeconds timeLimitMs;

    ControlTimedSharedPtr(void* p, long ms)
        : ptr(p), count(1),
          createdAt(Clock::now()),
          timeLimitMs(ms) {
        std::cout << "ControlTimedSharedPtr " << ptr << " start: 0 ms" << std::endl;
    }

    ~ControlTimedSharedPtr() {
        auto now = Clock::now();
        auto elapsed = std::chrono::duration_cast<milliSeconds>(now.time_since_epoch() - createdAt.time_since_epoch());
        std::cout << "ControlTimedSharedPtr " << ptr << " end: " << elapsed.count() << " ms" << std::endl;        
        delete static_cast<char*>(ptr); // generic delete
    }
};

// TimedSharedPtr is same as shared_ptr but with expiration features
template <typename T>
class TimedSharedPtr {
private:
    ControlTimedSharedPtr* control;

public:
    TimedSharedPtr() {
        control = nullptr;
    }
    TimedSharedPtr(T* raw, long ms) {
        control = new ControlTimedSharedPtr(static_cast<void*>(raw), ms);
    }
    TimedSharedPtr(T* raw) {
        control = new ControlTimedSharedPtr(static_cast<void*>(raw), 1000);
    }
    TimedSharedPtr(const TimedSharedPtr& other) {
        control = other.control;
        if (control) {
            control->count++;
        }
    }
    TimedSharedPtr& operator=(const TimedSharedPtr& other) {
        if (this != &other) {
            if (control && --control->count == 0) {
                delete control;
            }
            control = other.control;
            if (control) {
                control->count++;
            }
        }
        return *this;
    }
    ~TimedSharedPtr() {
        if (control && --control->count == 0) {
            delete control;
        }
    }
    long use_count() const {
        return control ? control->count : 0;
    }
    // Returns pointer if not expired, else null
    T* get() const {
        if (!control) return nullptr;
        auto now = Clock::now();
        auto elapsed = now - control->createdAt;
        if (elapsed > control->timeLimitMs) {
            std::cout << "Yeo! Expired ";
            return nullptr;
        }
        return static_cast<T*>(control->ptr);
    }
};

#endif
