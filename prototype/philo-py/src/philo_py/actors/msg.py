from dataclasses import dataclass, field
from abc import ABC
from enum import Enum, auto
from pykka import ActorRef as ref
from typing import Optional

# FIXME: Messageの型ではんていできるのでぶっちゃけ要らないかも
class EnumMsgCmd(Enum):
    UPDATE = auto()
    MONITOR = auto()
    ACTOR_DEAD = auto()
    REQUEST_FORK = auto()
    GRANT_FORK = auto()
    RELEASE_FORK = auto()
    FORK_RELEASED = auto()

e_cmd = EnumMsgCmd

@dataclass
class MsgBase(ABC):
    sender:Optional[ref] = None
    args: dict = field(default_factory=dict)

@dataclass
class MonitorMsg(MsgBase):
    pass

@dataclass
class UpdateMsg(MsgBase):
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