from pykka import ThreadingActor as Actor
from pykka import ActorRef as ref
from typing import Optional
from enum import Enum, auto
from actors.msg import (
	RequestForkMsg,
	GrantForkMsg,
	ReleaseForkMsg,
	ForkReleasedMsg,
)


class ForkSts(Enum):
	AVAILABLE = (auto(),)
	HELD = auto()


sts = ForkSts


class ForkActor(Actor):
	def __init__(self):
		super().__init__()
		self.sts = sts.AVAILABLE
		self.holder: Optional[ref] = None

	def on_receive(self, msg):
		match msg:
			case RequestForkMsg():
				self._on_request_fork(msg.sender)
			case ReleaseForkMsg():
				self._on_release_fork(msg.sender)

	def _on_request_fork(self, sender: ref):
		if self.holder == sender:
			return
		if self.sts == sts.AVAILABLE:
			self.sts = sts.HELD
			self.holder = sender
			sender.tell(GrantForkMsg(sender=self.actor_ref))

	def _on_release_fork(self, sender: ref):
		if self.holder != sender:
			return
		if self.sts == sts.HELD:
			self.sts = sts.AVAILABLE
			self.holder = None
			sender.tell(ForkReleasedMsg(sender=self.actor_ref))
