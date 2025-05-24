from dataclasses import dataclass
from abc import ABC
from enum import Enum, auto
from pykka import ActorRef as ref

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
    cmd: e_cmd
    sender: ref
    args: dict

@dataclass
class MonitorMsg(MsgBase):
    cmd = e_cmd.MONITOR

@dataclass
class UpdateMsg(MsgBase):
    cmd = e_cmd.UPDATE

@dataclass
class ActorDeadMsg(MsgBase):
    cmd = e_cmd.ACTOR_DEAD

@dataclass
class RequestForkMsg(MsgBase):
    cmd = e_cmd.REQUEST_FORK

@dataclass
class GrantForkMsg(MsgBase):
    cmd = e_cmd.GRANT_FORK

@dataclass
class ReleaseForkMsg(MsgBase):
    cmd = e_cmd.RELEASE_FORK

@dataclass
class ForkReleasedMsg(MsgBase):
    cmd = e_cmd.FORK_RELEASED