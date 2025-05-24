from pykka import ThreadingActor as Actor
from pykka import ActorRef as ref
from enum import Enum, auto
from actors.msg import (
	UpdateMsg,
	ActorDeadMsg,
	RequestForkMsg,
	GrantForkMsg,
	ReleaseForkMsg,
	ForkReleasedMsg,
	MonitorMsg,
)


class PhiloSts(Enum):
	THINKING = auto()
	EATING = auto()
	WAITING = auto()
	SLEEPING = auto()
	DEAD = auto()


sts = PhiloSts


class PhiloActor(Actor):
	def __init__(self, sv: ref, l_fork: ref, r_fork: ref, no, t_die, t_eat, t_slp):
		super().__init__()
		self.no = no
		self.time = 0
		self.hp = {"max": t_die, "now": t_die}
		self.eat_bar = {"max": t_eat, "now": 0}
		self.slp_bar = {"max": t_slp, "now": 0}
		self.sts = sts.THINKING
		self.fork_ref = {"l": l_fork, "r": r_fork}
		self.has_fork = {"l": False, "r": False}
		self.sv = sv

	def on_receive(self, msg):
		match msg:
			case UpdateMsg():
				if self.sts == sts.DEAD:
					return
				self._common_update()
				if self.sts == sts.THINKING:
					self._thinking()
				elif self.sts == sts.EATING:
					self._eating()
				elif self.sts == sts.SLEEPING:
					self._sleeping()
			case GrantForkMsg():
				self._confirm_fork(msg.sender)
			case ForkReleasedMsg():
				self._on_fork_released(msg.sender)
		self.sv.tell(MonitorMsg(args={"instance": self}))

	def _common_update(self):
		self.hp["now"] -= 1
		if self.hp["now"] == 0:
			self.sts = sts.DEAD
			self.sv.tell(ActorDeadMsg(sender=self.actor_ref, args={"id": self.no}))

	def _thinking(self):
		if not self.has_fork["l"]:
			self.fork_ref["l"].tell(RequestForkMsg(sender=self.actor_ref))
		if not self.has_fork["r"]:
			self.fork_ref["r"].tell(RequestForkMsg(sender=self.actor_ref))
		if self.has_fork["l"] and self.has_fork["r"]:
			self.sts = sts.EATING
			self.hp["now"] = self.hp["max"]

	def _eating(self):
		self.eat_bar["now"] += 1
		if self.eat_bar["now"] >= self.eat_bar["max"]:
			self.eat_bar["now"] = 0
			self.fork_ref["l"].tell(ReleaseForkMsg(sender=self.actor_ref))
			self.fork_ref["r"].tell(ReleaseForkMsg(sender=self.actor_ref))
			self.sts = sts.WAITING

	def _sleeping(self):
		self.slp_bar["now"] += 1
		if self.slp_bar["now"] >= self.slp_bar["max"]:
			self.slp_bar["now"] = 0
			self.sts = sts.THINKING

	def _confirm_fork(self, sender: ref):
		if sender == self.fork_ref["l"]:
			self.has_fork["l"] = True
		if sender == self.fork_ref["r"]:
			self.has_fork["r"] = True

	def _on_fork_released(self, sender: ref):
		if sender == self.fork_ref["l"]:
			self.has_fork["l"] = False
		if sender == self.fork_ref["r"]:
			self.has_fork["r"] = False
		if self.has_fork["l"] and self.has_fork["r"]:
			self.sts = sts.SLEEPING
