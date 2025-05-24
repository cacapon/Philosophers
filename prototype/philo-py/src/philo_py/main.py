#!/usr/bin/env python3
import sys
import time
from actors.supervisor import SuperVisorActor
from actors.msg import UpdateMsg

if __name__ == "__main__":
	if len(sys.argv) != 5:
		print("error")
		sys.exit(1)
	num_of_philos = int(sys.argv[1])
	time_to_die = int(sys.argv[2])
	time_to_eat = int(sys.argv[3])
	time_to_sleep = int(sys.argv[4])
	sv = SuperVisorActor.start(num_of_philos, time_to_die, time_to_eat, time_to_sleep)
	while not sv.actor_stopped.is_set():
		sv.tell(UpdateMsg())
		time.sleep(0.05)
	sv.stop()