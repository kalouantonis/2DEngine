#ifndef _MEMORYPOOL_H_
#define _MEMORYPOOL_H_

#include <cstddef>

namespace SuperEngine
{
    class MemoryPool
    {
    private:
        struct m_Block
        {
            m_Block* pPrev;
            m_Block* pNext;
        };

        // Allocated block
        void* m_pRawMemBlock;

        // Pool heads
        m_Block* m_pFreeHead;
        m_Block* m_pAllocHead;

        // Chunk params
        unsigned long m_blockSize;
        unsigned long m_numBlocks;

        std::size_t m_structSize;
        std::size_t m_poolSize;

    public:
        // Set values randomly, check vals later
        MemoryPool()
            :  m_pRawMemBlock(NULL), m_pFreeHead(NULL), m_pAllocHead(NULL),
            m_blockSize(1024), m_numBlocks(1)
        {

        }

        ~MemoryPool();

        bool Init(unsigned long blockSize, unsigned long numBlocks);

        void* Alloc(std::size_t chunkSize, bool useMemPool = true);
        void Free(void* p);

        void Destroy();
    };
};

#endif // _MEMORYPOOL_H_
