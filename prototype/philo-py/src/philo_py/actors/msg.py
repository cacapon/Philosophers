from dataclasses import dataclass
from abc import ABC
from enum import Enum, auto
from pykka import ActorRef as ref

class EnumMsgCmd(Enum):
    REQUEST_FORK = auto()
    GRANT_FORK = auto()
    RELEASE_FORK = auto()

e_cmd = EnumMsgCmd

@dataclass
class MsgBase(ABC):
    cmd: e_cmd
    sender: ref
    args: dict

@dataclass
class RequestForkMsg(MsgBase):
    cmd = e_cmd.REQUEST_FORK

@dataclass
class GrantForkMsg(MsgBase):
    cmd = e_cmd.GRANT_FORK

@dataclass
class ReleaseForkMsg(MsgBase):
    cmd = e_cmd.RELEASE_FORK
