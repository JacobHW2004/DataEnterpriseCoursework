#ifndef SLEEPER_H
#define SLEEPER_H

#include <mutex>
#include <condition_variable>
#include <chrono>

namespace ConcurrentUtilities {

class Sleeper
{
public:
	Sleeper() = default;
	void wait();
	void wake();
	void waitWithTimeout(std::chrono::milliseconds);
	void waitWithTimeout(std::chrono::microseconds);

private:

	/* Ensures sleeper class wakes the thread for a component only once and not while already indicated to do so */
	bool mMessagesReady{ false };
	
	/* Threadsafety mutex, ensures wait/wake aren't enacted at the same time */
	std::mutex mMutex;

	/* Used to carry out waiting sleeping/waking functionality within the sleeper class */
	std::condition_variable mCondVar;
};

} // namespace ConcurrentUtilities

#endif // Header Guard 