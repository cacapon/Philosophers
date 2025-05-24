#!/usr/bin/env python3
import sys
import pykka
from actors.philo import PhiloActor

def init_philo_actors(num_of_philos:int) -> list[pykka.ActorRef[PhiloActor]]:
	philo_actors = []
	for i in range(num_of_philos):
		philo_actors.append(PhiloActor.start(i+1))

if __name__ == "__main__":
	if len(sys.argv) != 5:
		print("error")
		sys.exit(1)
	num_of_philos = sys.argv[1]
	time_to_die = sys.argv[2]
	time_to_eat = sys.argv[3]
	time_to_sleep = sys.argv[4]
	print(f"num_of_philos:{num_of_philos}")
	print(f"time_to_die:{time_to_die}")
	print(f"time_to_eat:{time_to_eat}")
	print(f"time_to_sleep:{time_to_sleep}")
	my_actor_ref = PhiloActor.start(
		id=num_of_philos,
		t_die=time_to_die,
		t_eat=time_to_eat, 
		t_slp=time_to_sleep)
