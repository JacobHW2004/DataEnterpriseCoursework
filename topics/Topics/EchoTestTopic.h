#ifndef ECHO_TEST_TOPIC_H
#define ECHO_TEST_TOPIC_H

#include <string>
#include "Fabric/Utils/LCA_Macros.h"

namespace TestingInfrastructure {

/**
* @brief Topic - Used to configure/control the single repeater test component that receives it
*
*/
class EchoTestTopic {

public:
    /// The timestamp when the trigger messages is sent
    uint64_t startTime;
    /// The timestamp that the received topic was sent at
    uint64_t timeStamp;
    /// This indicates if this is the first message sent by RepeaterResults
	uint8_t triggerMessage;

    /// propagation - this is a simple multiplier of the number of topics to send in response to receiving one
	int8_t propagation; // 1 * propagation
    /// propagation counter
    uint64_t propCounter;

    /// How long to wait before publishing any topic
    uint64_t preDelayCount;
    /// How long to delay after publishing and checking for new messages
    uint64_t postDelayCount;
    /// Message index that reflects the number that have been round the loop
    uint64_t messageCount;


    /// 'S'top on error, "C"ontinue as is, "T"ry remove error and continue
    /// Every error will be sent back to the RepeaterResults component,
    /// - if 'S' then the Topic will not be forwarded and the sequence will stop
    /// - if 'C' then the Topic will be passed on unmodified with no attempt to correct the error
    /// - if 'T' then the failing value will be set to the expected one before sending on
    enum class ErrorHandling_enum
    {
        Stop,
        Continue,
        TryFix
    };
    ErrorHandling_enum errorHandling;


    /// Time to live will indicate the number of time that the Topic should be forwarded:
    ///     - if zero when received then this will be forwarded without limit
    ///     - if non-zero when received then it will be forwaded, subtracting 1 each time, 
    ///       until it reaches zero
	unsigned short timeToLive; 

	union EchoUnion_t
	{
		struct EchoStruct_t
		{
			double myDouble;
            uint64_t myUint64;
            uint32_t myUint32;
			uint16_t myUint16;
			uint8_t myUint8;
			float myFloat;
			int64_t myInt64;
			int32_t myInt32;
			int16_t myInt16;
			int8_t myInt8;
		}echoStruct;
		uint8_t echoUnionBuffer[sizeof(EchoStruct_t)];
	};
	union EchoUnion_t echoUnion;
	unsigned char checksum;

	/**
	* @brief Serialise function required for communications
	*/
	template <class T>
	void Serialise(T& archive) {
        int errHandling = static_cast<int>(errorHandling);
		archive.Serialise(timeStamp, "timeStamp");
		archive.Serialise(startTime, "startTime");
		archive.Serialise(triggerMessage, "triggerMessage");
		archive.Serialise(propagation, "propagation");
        archive.Serialise(propCounter, "propCounter");
        archive.Serialise(preDelayCount, "preDelayCount");
		archive.Serialise(postDelayCount, "postDelayCount");
		archive.Serialise(messageCount, "messageCount");
		archive.Serialise(errHandling, "errorHandling");
		archive.Serialise(timeToLive, "timeToLive");
		archive.Serialise(echoUnion.echoStruct.myDouble, "myDouble");
		archive.Serialise(echoUnion.echoStruct.myUint64, "myUint64");
		archive.Serialise(echoUnion.echoStruct.myUint32, "myUint32");
		archive.Serialise(echoUnion.echoStruct.myUint16, "myUint16");
		archive.Serialise(echoUnion.echoStruct.myUint8,  "myUint8");
		archive.Serialise(echoUnion.echoStruct.myFloat,  "myFloat");
		archive.Serialise(echoUnion.echoStruct.myInt64,  "myInt64");
		archive.Serialise(echoUnion.echoStruct.myInt32,  "myInt32");
		archive.Serialise(echoUnion.echoStruct.myInt16,  "myInt16");
		archive.Serialise(echoUnion.echoStruct.myInt8,   "myInt8");
		archive.Serialise(checksum, "checksum");
	}

    LCA_TOPIC("EchoTestTopic", 1, 0)

};

}  // namespace Topics

#endif