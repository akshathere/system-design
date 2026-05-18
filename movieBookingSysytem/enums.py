from enum import Enum

class SeatType(Enum):
    REGULAR = 1
    VIP = 2

class SeatStatus(Enum):
    BOOKED = 1
    AVAILABLE = 2

class PaymentStatus(Enum):
    PENDING = 1
    SUCCESS = 2
    FAILED = 3
