import pykka
from enum import Enum, auto

class PhiloSts(Enum):
	THINKING = auto()
	EATING = auto()
	SLEEPING = auto()
	DEAD = auto()

class PhiloActor(pykka.ThreadingActor):
	def __init__(self, no, t_die, t_eat, t_slp):
		super().__init__()
		self.no = no
		self.time = 0
		self.hp = {"max": t_die, "now": t_die}
		self.eat_bar = {"max": t_eat, "now": 0}
		self.slp_bar = {"max": t_slp, "now":0}
		self.sts = PhiloSts.THINKING

	def on_receive(self, message:dict):
		if message.get("update"):
			self.time += 1
			if self.status == PhiloStatus.THINKING:
				self._thinking()
		pass

	def _thinking(self):
		pass
