from seat import Seat
class Screen:
    id:str
    seats:list[Seat]
    def __init__(self, id:str, seats:list[Seat]):
        self.id = id
        self.seats = seats
    