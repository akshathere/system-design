from enums import SeatStatus, SeatType
class Seat:
    id:str
    seatType:SeatType
    seatStatus:SeatStatus
    def __init__(self, id:str, seatType:SeatType, seatStatus:SeatStatus):
        self.id = id
        self.seatType = seatType
        self.seatStatus = seatStatus
        

    