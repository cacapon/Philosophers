import os
from pykka import ThreadingActor as Actor
from pykka import ActorRef as ref
from dataclasses import dataclass
from actors.fork import ForkActor as Fork
from actors.philo import (
	PhiloActor as Philo,
	PhiloSts,
)
from actors.msg import (
	UpdateMsg,
	MonitorMsg,
)


@dataclass
class MonitorData:
	no: int = 0
	sts: PhiloSts = PhiloSts.WAITING
	hp: dict = None
	l_fork: ref[Fork] = False
	r_fork: ref[Fork] = False


class SuperVisorActor(Actor):
	def __init__(self, num_of_philos: int, t_die: int, t_eat: int, t_slp: int):
		self.forks_ref: list[ref[Fork]] = self._create_forks(num_of_philos)
		self.philos_ref: list[ref[Philo]] = self._create_philos(
			num_of_philos, self.forks_ref, t_die, t_eat, t_slp
		)
		self.monitor_data: list[MonitorData] = self._init_monitor()

	def _create_forks(self, num: int) -> list[ref[Fork]]:
		forks: list[ref[Fork]] = []
		for _ in range(num):
			forks.append(Fork.start())
		return forks

	def _create_philos(
		self, num: int, forks: list[ref[Fork]], t_die: int, t_eat: int, t_slp: int
	) -> list[ref[Philo]]:
		philos: list[ref[Philo]] = []
		for i in range(num):
			philos.append(
				Philo.start(
					sv=self.actor_ref,
					l_fork=forks[(i - 1) % len(forks)],
					r_fork=forks[i % len(forks)],
					no=i + 1,
					t_die=t_die,
					t_eat=t_eat,
					t_slp=t_slp,
				)
			)
		return philos

	def _init_monitor(self):
		monitor_data = []
		for i in range(len(self.philos_ref)):
			monitor_data.append(MonitorData(no=i + 1))
		return monitor_data

	def on_receive(self, msg):
		match msg:
			case UpdateMsg():
				self._update_philos()
				self._show_monitor()
			case MonitorMsg():
				self._update_monitor(msg)
		pass

	def _update_philos(self):
		for philo in self.philos_ref:
			philo.tell(UpdateMsg())

	def _update_monitor(self, msg: MonitorMsg):
		ins = msg.args.get("instance")
		if type(ins) is Philo:
			index = (ins.no - 1) % len(self.monitor_data)
			self.monitor_data[index].sts = ins.sts
			self.monitor_data[index].hp = ins.hp
			self.monitor_data[index].l_fork = ins.has_fork["l"]
			self.monitor_data[index].r_fork = ins.has_fork["r"]

	def _show_monitor(self):
		sts_face = {
			PhiloSts.THINKING: "🧐",
			PhiloSts.EATING: "😋",
			PhiloSts.SLEEPING: "😴",
			PhiloSts.WAITING: "⏳",
			PhiloSts.DEAD: "💀",
		}
		os.system("clear")
		for data in self.monitor_data:
			strs = [
				f"[{data.no}]",
				f"{sts_face.get(data.sts, '❌')}",
				f"{data.hp.get('now', 'XXX')}/{data.hp.get('max', 'XXX')}",
				f"L{'🟢' if data.l_fork else '🔴'}",
				f"R{'🟢' if data.r_fork else '🔴'}",
			]
			print(":".join(strs))
