#include <thread>
#include <future>
#include <chrono>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TestComponentMessaging.h"

// This function emulates what the component's run function in ComponentCmpEntry.cpp would do.
int subscriberThread(TestComponentMessaging &aTestComponentMessaging, int noOfExpectedMessages)
{
	int messageCount = 0;

	//loop this until we've picked up all messages
	//really shouldn't ever not get them all, but if we don't, this will infinite loop
	while (!aTestComponentMessaging.processedAll)
	{
		//this is set up as a while loop because it's possible to receive more than one topic before a complete iteration of the parent while loop
		//therefore, 1 iteration != 1 topic
		//the function call here will return false if no topic is received
		while(aTestComponentMessaging.getTopicA())
		{
			//in the real code this would be where the topic is processed.
			//instead we just incremenet the number of messages / topics
			messageCount++;
		}

		//bail out if we've got enough messages
		if (messageCount >= noOfExpectedMessages)
		{
			aTestComponentMessaging.processedAll = true;
			break;
		}
		
		//wait for messages
		//we increment the number of calls to this function inside waitForMessages
		//therefore 1 iteration of this == 1 call to wait for messages
		aTestComponentMessaging.waitForMessages();
	}

	return messageCount;
}

// This function emulates what the lca::fabric::Subscriber lambda in ComponentMessaging.cpp would do.
void publisherThread(TestComponentMessaging &aTestComponentMessaging, int noOfMessagesPublished)
{
	// Dummy topic to be published
	int topicA{0};

	// "Publish" topic
	for (int i = 0; i < noOfMessagesPublished; ++i)
	{
		aTestComponentMessaging.storeTopicA(topicA);
		// Pass control to subscriber thread
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	//we only want to return this thread when the subscriber is finished processing
	//check if it is, and if it isn't sleep until it is
	while(aTestComponentMessaging.processedAll == false)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

SCENARIO("Subscriber only loops around when there are messages to process")
{
	TestComponentMessaging aTestComponentMessaging;
	const int noOfMessagesPublished = 10; // Arbitrary number

	// Kick off publisher and subscriber threads
	std::thread publisher(publisherThread, std::ref(aTestComponentMessaging), noOfMessagesPublished);
	std::future<int> subscriberLoopCount = std::async(subscriberThread, std::ref(aTestComponentMessaging), noOfMessagesPublished);

	// Wait for threads to finish work
	publisher.join();

	//more than one message may be processed in one iteration of the loop
	//so the value can be <= the number of messages published
	//if >, then fail
	CHECK(noOfMessagesPublished >= aTestComponentMessaging.getWaitCount());
}

SCENARIO("Subscriber waits when there are no mesages and wakes when there are messages")
{

	GIVEN("The subscriber is waiting for messages")
	{
		// Subscriber tries to get topic before anything has been published
		TestComponentMessaging aTestComponentMessaging;
		CHECK(std::nullopt == aTestComponentMessaging.getTopicA());

		// Subscriber waits for new messages on a separate thread
		auto subscriber = std::async(std::launch::async, [&aTestComponentMessaging] {
			aTestComponentMessaging.waitForMessages();
		});
		// Pass control to subscriber thread
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		// Check subscriber thread is waiting and has not finished
		auto status = subscriber.wait_for(std::chrono::milliseconds(0));
		CHECK(status == std::future_status::timeout);

		WHEN("Topic A is published")
		{

			// Publisher pushes new topic
			int topicA{0};
			aTestComponentMessaging.storeTopicA(topicA);
			// Pass control to subscriber thread
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			THEN("Check subscriber thread has woken up and is now finished")
			{
				status = subscriber.wait_for(std::chrono::milliseconds(0));
				CHECK(status == std::future_status::ready);
			}
		}
		WHEN("Topic B is published")
		{

			// Publisher pushes new topic
			int topicB{0};
			aTestComponentMessaging.storeTopicB(topicB);
			// Pass control to subscriber thread
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			THEN("Check subscriber thread has woken up and is now finished")
			{
				status = subscriber.wait_for(std::chrono::milliseconds(0));
				CHECK(status == std::future_status::ready);
			}
		}
		WHEN("Topic A and topic B are published")
		{

			// Publisher pushes new topics
			int topicA{0};
			aTestComponentMessaging.storeTopicA(topicA);
			int topicB{0};
			aTestComponentMessaging.storeTopicB(topicB);
			// Pass control to subscriber thread
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			THEN("Check subscriber thread has woken up and is now finished")
			{
				status = subscriber.wait_for(std::chrono::milliseconds(0));
				CHECK(status == std::future_status::ready);
			}
		}
	}
}