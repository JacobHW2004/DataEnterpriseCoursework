#include "Sleeper.h"

namespace ConcurrentUtilities {

void Sleeper::wait()
{
	std::unique_lock<std::mutex> aLock(mMutex);
	mMessagesReady = false;
	mCondVar.wait(aLock, [&] { return mMessagesReady; });	// Wait for publishers thread to set mMessagesReady to true
}

void Sleeper::waitWithTimeout(std::chrono::milliseconds timeout)
{
	std::unique_lock<std::mutex> aLock(mMutex);
	mMessagesReady = false;
	mCondVar.wait_for(aLock, timeout, [&] { return mMessagesReady; });   //thread will be unblocked when notified, or when the timeout expires
}

void Sleeper::waitWithTimeout(std::chrono::microseconds timeout)
{
	std::unique_lock<std::mutex> aLock(mMutex);
	mMessagesReady = false;
	mCondVar.wait_for(aLock, timeout, [&] { return mMessagesReady; });   //thread will be unblocked when notified, or when the timeout expires
}

void Sleeper::wake()
{
	std::unique_lock<std::mutex> aLock(mMutex);
	if (mMessagesReady == false)	// If there were not messages ready previously  
	{
		mMessagesReady = true;
		aLock.unlock();
		mCondVar.notify_one();		// Wake up component from its sleep
	}
	// Else mMessagesReady is already true so nothing to do
}

} // namespace ConcurrentUtilities
