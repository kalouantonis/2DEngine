#include <Engine.h>

#include <cstdlib>
#include <iostream>

namespace SuperEngine
{
    MemoryPool::~MemoryPool()
    {
        Destroy();
    }

    void MemoryPool::Destroy()
    {
        free(m_pRawMemBlock);
    }

    bool MemoryPool::Init(unsigned long blockSize, unsigned long numBlocks)
    {
        m_numBlocks = numBlocks;
        m_blockSize = blockSize;

        m_structSize = sizeof(m_Block);
        m_poolSize = m_numBlocks * (m_blockSize + m_structSize);

        m_pRawMemBlock = malloc(m_poolSize);

        if(!m_pRawMemBlock)
        {
            // Log in engine that memory alloc failed
            // should probably burn that PC as there's serious
            // hardware problems or a lack of memory
            return false;
        }

        for(unsigned long i = 0; i < m_numBlocks; i++)
        {
            // CPPCheck detects C-Style cast, use std::static_cast<T> instead
            m_Block* pCurrBlock = (m_Block*) ((char*) m_pRawMemBlock +
                                                             (i * (m_structSize + m_blockSize)));

            //pCurrBlock->pPrev = NULL;
            //pCurrBlock->pNext = m_pFreeHead;
            pCurrBlock->pNext = NULL;
            pCurrBlock->pPrev = m_pFreeHead;

            if(m_pFreeHead)
                // Set last block to reference this block as a previous item
                m_pFreeHead->pNext = pCurrBlock;

            // Move Free Head up by one block
            m_pFreeHead = pCurrBlock;
        }

        return true;
    }

    void* MemoryPool::Alloc(std::size_t chunkSize, bool useMemPool)
    {
        // if the needed chunk size is larger than the memory pool chunks
        // just malloc a new chunk. Also, if there is no memblock or free blocks
        // just return it as a new malloc
        if((chunkSize > m_blockSize) || (!useMemPool) ||
           (!m_pRawMemBlock) || (!m_pFreeHead))
           return malloc(chunkSize);

        // assign to the top free mem
        m_Block* pCurrBlock = m_pFreeHead;

        // Move head up one block
        m_pFreeHead = pCurrBlock->pPrev;

        // TODO: check this flow, looks like
        if(m_pFreeHead)
            // The previous item behind the free head is no longer refernced
            // as a free block
            m_pFreeHead->pNext = NULL;

        // If there is no next alloc head, set the next val to NULL
        //Looks like we're skipping a mem address
        // TODO: check flow again
        pCurrBlock->pNext = m_pAllocHead;
        if(m_pAllocHead)
            m_pAllocHead->pPrev = pCurrBlock;

        // Shift alloc head up
        m_pAllocHead = pCurrBlock;

        return (void*)((char*)pCurrBlock + m_structSize);
    }

    void MemoryPool::Free(void* p)
    {
        char* pStructPos = (char*)p - m_structSize;

        if((p > m_pRawMemBlock) && (void*)pStructPos < (void*)((char*)m_pRawMemBlock +
                                                        (m_numBlocks * (m_blockSize + m_structSize))))
        {
            struct m_Block* pCurrBlock = (struct m_Block*)pStructPos;

            m_pAllocHead = pCurrBlock->pNext;
            if(m_pAllocHead)
                m_pAllocHead->pNext = NULL;

            pCurrBlock->pPrev = m_pFreeHead;
            if(m_pFreeHead)
                m_pFreeHead->pNext = pCurrBlock;

            m_pFreeHead = pCurrBlock;
        }
        else
        {
            free(p);
        }
    }
};
