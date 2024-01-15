#pragma once
#include <corecrt_malloc.h>
#include <array>
#include <cstdint>
#include <iostream>


void memPractice() {
    void* ptr = malloc(16 * sizeof(std::array<uint32_t, 16>));

    std::cout << (void*)ptr << "\n";
    std::cout << (void*)((char*)ptr + sizeof(std::array<uint32_t, 16>));
}

/*
class MemoryPool
{
public:
    MemoryPool() : ptr(mem)
    {
    }

    void* allocate(int mem_size)
    {
        assert((ptr + mem_size) <= (mem + sizeof mem) && "Pool exhausted!");
        void* mem = ptr;
        ptr += mem_size;
        return mem;
    }

private:
    MemoryPool(const MemoryPool&);
    MemoryPool& operator=(const MemoryPool&);
    char mem[4096];
    char* ptr;
};
*/