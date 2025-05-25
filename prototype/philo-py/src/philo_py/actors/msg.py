from dataclasses import dataclass, field
from abc import ABC
from enum import Enum, auto
from pykka import ActorRef as ref
from typing import Optional

@dataclass
class MsgBase(ABC):
    sender:Optional[ref] = None
    args: dict = field(default_factory=dict)

@dataclass
class PhiloReadyMsg(MsgBase):
    pass

@dataclass
class GrantEatMsg(MsgBase):
    pass

@dataclass
class MonitorMsg(MsgBase):
    pass

@dataclass
class UpdateMsg(MsgBase):
    pass

@dataclass
class PhiloEatDoneMsg(MsgBase):
    pass

@dataclass
class ActorDeadMsg(MsgBase):
    pass

@dataclass
class RequestForkMsg(MsgBase):
    pass

@dataclass
class GrantForkMsg(MsgBase):
    pass

@dataclass
class ReleaseForkMsg(MsgBase):
    pass

@dataclass
class ForkReleasedMsg(MsgBase):
    pass