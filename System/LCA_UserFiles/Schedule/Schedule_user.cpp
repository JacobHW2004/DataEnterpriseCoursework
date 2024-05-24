/********************************************************************************
*
* This software has been developed by Leonardo MW Ltd.and is wholly owned
* by Leonardo MW Ltd.
*
* The copyright in this software is the property of Leonardo MW Ltd.The software
* is supplied by Leonardo MW Ltd.on the express understanding that it is treated
* as confidentialand that it may not be copied, used or disclosed to others in
* whole or in part for any purpose except as authorised in writing by
* Leonardo MW Ltd.
*
* (c)Leonardo MW Limited 2022
* Proprietary Information - All Rights Reserved.
*
********************************************************************************/
/********************************************************************************
* CLASSIFICATION   : UK OFFICIAL
* FUNCTION         : Sheduler User
* Example		   : http://descldwas099v.des.grplnk.net:8090/confluence/display/LCA/LCA+How+do+I+use+the+LCA+scheduler
********************************************************************************/
#ifndef SCHEDULE_USER_H
#define SCHEDULE_USER_H

#include "SchedulerRuntime.h"
#include "Executors/ThreadPoolExecutor.h"
#include "TickSources/SimpleTicker.h"
#include "ScheduleLayer.h"

lca::schedule::SchedulerRuntime::SchedulerRuntime() 
{
	std::shared_ptr<lca::schedule::ThreadPoolExecutor> exec = lca::schedule::ThreadPoolExecutor::create();

	std::shared_ptr<lca::schedule::SimpleTicker> tick = lca::schedule::SimpleTicker::create();
}

#endif // !SCHEDULE_USER_H