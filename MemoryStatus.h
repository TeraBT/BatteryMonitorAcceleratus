#ifndef MEMORYSTATUS_H
#define MEMORYSTATUS_H

#include <memory>

#if defined(_WIN32) || defined(_WIN64)

//#include <Windows.h>

#endif

class MemoryStatus {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    MemoryStatus();

    ~MemoryStatus();

    MemoryStatus(const MemoryStatus &) = delete;

    MemoryStatus &operator=(const MemoryStatus &) = delete;

    void update();

    float getTotalMemory();

    float getAvailableMemory();

    float getUsedMemory();

};

#endif
