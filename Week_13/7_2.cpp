#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstring>

const size_t MAX_LARGE_BUCKET_SIZE = 1024 * 1024; 
const size_t SMALL_ALLOC_THRESHOLD = 4096;        

class LargeBucket {
    std::unique_ptr<char[]> data;
    size_t size;

public:
    LargeBucket(size_t allocSize) {
        if (allocSize > MAX_LARGE_BUCKET_SIZE) {
            throw std::bad_alloc();
        }

        try {
            data = std::make_unique<char[]>(allocSize);
            size = allocSize;
        } catch (...) {
            throw std::bad_alloc();
        }
    }

    char* getData() {
        return data.get();
    }

    size_t getSize() const {
        return size;
    }
};

class Heap {
public:
    virtual ~Heap() = default;

    virtual void* allocate(size_t size) {
        if (size >= SMALL_ALLOC_THRESHOLD) {
            LargeBucket* bucket = new LargeBucket(size);
            return bucket->getData(); 
        }

        try {
            return new char[size];
        } catch (...) {
            throw std::bad_alloc();
        }
    }

    virtual void deallocate(void* ptr, size_t size) {
        if (size >= SMALL_ALLOC_THRESHOLD) {
            delete[] static_cast<char*>(ptr); 
        } else {
            delete[] static_cast<char*>(ptr);
        }
    }
};


int main() {
    Heap heap;

    try {
        
        void* smallPtr = heap.allocate(100);
        std::strcpy(static_cast<char*>(smallPtr), "Small allocation");
        std::cout << "Small: " << static_cast<char*>(smallPtr) << "\n";
        heap.deallocate(smallPtr, 100);

        
        void* largePtr = heap.allocate(10 * 1024);
        std::strcpy(static_cast<char*>(largePtr), "Large allocation");
        std::cout << "Large: " << static_cast<char*>(largePtr) << "\n";
        heap.deallocate(largePtr, 10 * 1024);

        
        heap.allocate(2 * MAX_LARGE_BUCKET_SIZE);
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation failed: " << e.what() << "\n";
    }

    return 0;
}
