#pragma once

#include "ConcurrentQueue.h"
#include "Sleeper.h"
class TestComponentMessaging
{

public:
    // --------------------------------
    // Methods run on publishers thread
    void storeTopicA(int topicA)
    {
        mTopicA_queue.push(topicA);
        mSleeper.wake();
    }
    void storeTopicB(int topicB)
    {
        mTopicB_queue.push(topicB);
        mSleeper.wake();

    }

    // --------------------------------
    // Methods run on subscribers thread
    std::optional<int> getTopicA()
    {
        return mTopicA_queue.tryFrontPop();
    }
    std::optional<int> getTopicB()
    {
        return mTopicB_queue.tryFrontPop();
    }
    void waitForMessages()
    {
        mWaitCount++;
        mSleeper.wait();
    }
    int getWaitCount()
    {
        return mWaitCount;
    }
            
    std::atomic<bool> processedAll { false };

private:
    // Queues to store incoming topics
    // Accessed concurrently on publishers and subscribers threads
    ConcurrentQueue<int> mTopicA_queue;
    ConcurrentQueue<int> mTopicB_queue;

    std::atomic<int> mWaitCount { 0 };

    ConcurrentUtilities::Sleeper mSleeper{};
};
