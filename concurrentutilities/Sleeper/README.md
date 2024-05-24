@page Sleeper

# Sleeper API

## wait
Check if the predicate says there is no work to do.  
If so sleep until `wake` is called by another thread.  
This would live in the while(true) loop of the LCA component entry.  

## wake  
Check if previously there were no messages ready (and therefore component thread would be sleeping).  
If so wake up sleeping thread.  
This would live in the store function of the ComponentMessaging and it would be run by the publishers thread. 

# Rationale
## Why is this needed
Some Components in our ecosystem are purely event driven. If there are no messages coming in for them to process they have no reason to be alive.
Their thread can be sleeping and be woken up by the publishers thread when there is work to do.
This is better than the busy waiting and polling the queues because it chews up CPU cycles.