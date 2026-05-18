from seat import Seat
from user import User
from screen import Screen
from payment import PaymentStrategy
from enums import SeatStatus, SeatType
from movie import Movie
from theater import Theater

class BookingManager:
    def bookSeat(self, user:User, theater:Theater, movie:Movie, screen:Screen, seatList:list[Seat], paymentStrategy:PaymentStrategy, totalAmount:float):
        # here we will implement locks and unlocks to avoid race conditions and ensure thread safety
        for seat in seatList:
            if seat.seatStatus != SeatStatus.AVAILABLE:
                print(f"Seat {seat.id} is not available for booking")
                return False

        paymentStrategy.pay(totalAmount)
        for seat in seatList:
            seat.seatStatus = SeatStatus.BOOKED
            print(f"Seat {seat.id} booked successfully for movie {movie.name} at {theater.name} and user {user.name}")
        return True

class Booking:
    id:str
    user:User
    theater:Theater
    movie:Movie
    screen:Screen
    seatList:list[Seat]
    paymentStrategy:PaymentStrategy
    totalAmount:float
    def __init__(self, id:str, user:User, theater:Theater, movie:Movie, screen:Screen, seatList:list[Seat], paymentStrategy:PaymentStrategy, totalAmount:float):
        self.id = id
        self.user = user
        self.theater = theater
        self.movie = movie
        self.screen = screen
        self.seatList = seatList
        self.paymentStrategy = paymentStrategy
        self.totalAmount = totalAmount
    def calculateTotalAmount(self):
        for seat in self.seatList:
            if seat.seatType == SeatType.REGULAR:
                self.totalAmount += 10
            elif seat.seatType == SeatType.VIP:
                self.totalAmount += 30
    def book(self, bookingManager:BookingManager):
        return bookingManager.bookSeat(self.user, self.theater, self.movie, self.screen, self.seatList, self.paymentStrategy, self.totalAmount)

class BookingFactory:
    def createBooking(self, id:str, user:User, theater:Theater, movie:Movie, screen:Screen, seatList:list[Seat], paymentStrategy:PaymentStrategy):
        booking = Booking(id=id, user=user, theater=theater, movie=movie, screen=screen, seatList=seatList, paymentStrategy=paymentStrategy, totalAmount=0)
        booking.calculateTotalAmount()
        return booking
