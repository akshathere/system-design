from theater import Theater
from bookingManager import BookingManager, Booking, BookingFactory
from seat import Seat
from screen import Screen
from user import User
from payment import PaymentStrategy
from enums import SeatStatus
from movie import Movie
from notification import BookingObserver


class MovieBookingService:
    theaters:list[Theater]
    movies:list[Movie]
    bookingManager:BookingManager
    paymentStrategies:list[PaymentStrategy]
    users:list[User]
    screens:list[Screen]
    seats:list[Seat]
    bookings:list[Booking]
    observers:list[BookingObserver]
    bookingFactory:BookingFactory
    def __init__(self, theaters:list[Theater], movies:list[Movie], bookingManager:BookingManager, paymentStrategies:list[PaymentStrategy], users:list[User], screens:list[Screen], seats:list[Seat], bookings:list[Booking], observers:list[BookingObserver]):
        self.theaters = theaters
        self.movies = movies
        self.bookingManager = bookingManager
        self.paymentStrategies = paymentStrategies
        self.users = users
        self.screens = screens
        self.seats = seats
        self.bookings = bookings
        self.observers = observers
        self.bookingFactory = BookingFactory()
    def addObserver(self, observer:BookingObserver):
        self.observers.append(observer)
    def notifyObservers(self, eventType:str, booking:Booking):
        for observer in self.observers:
            observer.update(eventType, booking)
    def bookSeat(self, user:User, theater:Theater, movie:Movie, screen:Screen, seat:Seat, paymentStrategy:PaymentStrategy):
        if screen not in theater.screens:
            print(f"Screen {screen.id} does not belong to theater {theater.name}")
            return

        booking = self.bookingFactory.createBooking(id="1", user=user, theater=theater, movie=movie, screen=screen, seatList=[seat], paymentStrategy=paymentStrategy)
        if booking.book(self.bookingManager):
            self.bookings.append(booking)
            self.notifyObservers("confirmed", booking)
    def cancelBooking(self, booking:Booking):
        for seat in booking.seatList:
            seat.seatStatus = SeatStatus.AVAILABLE
        self.bookings.remove(booking)
        print(f"Booking {booking.id} cancelled successfully for movie {booking.movie.name} at {booking.theater.name} and user {booking.user.name}")
        self.notifyObservers("cancelled", booking)
    
