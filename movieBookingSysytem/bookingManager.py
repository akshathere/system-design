from seat import Seat
from user import User
from screen import Screen
from payment import PaymentStrategy
from enums import SeatStatus, SeatType

class BookingManager:
    def bookSeat(self, user:User, screen:Screen, seatList:list[Seat], paymentStrategy:PaymentStrategy, totalAmount:float):
        # here we will implement locks and unlocks to avoid race conditions and ensure thread safety
        for seat in seatList:
            if seat.seatStatus == SeatStatus.AVAILABLE:
                paymentStrategy.pay(totalAmount)
                seat.seatStatus = SeatStatus.BOOKED
                print(f"Seat {seat.id} booked successfully for user {user.name}")
        else:
            print(f"Seat {seat.id} is not available for booking")
class Booking:
    id:str
    user:User
    screen:Screen
    seatList:list[Seat]
    paymentStrategy:PaymentStrategy
    totalAmount:float
    def __init__(self, id:str, user:User, screen:Screen, seatList:list[Seat], paymentStrategy:PaymentStrategy, totalAmount:float):
        self.id = id
        self.user = user
        self.screen = screen
        self.seatList = seatList
        self.paymentStrategy = paymentStrategy
        self.totalAmount = totalAmount
    def calculateTotalAmount(self):
        for seat in self.seatList:
            if seat.seatType == SeatType.REGULAR:
                self.totalAmount += 10
            elif seat.seatType == SeatType.PREMIUM:
                self.totalAmount += 20
            elif seat.seatType == SeatType.VIP:
                self.totalAmount += 30
    def book(self):
        bookingManager = BookingManager()
        bookingManager.bookSeat(self.user, self.screen, self.seatList, self.paymentStrategy, self.totalAmount)