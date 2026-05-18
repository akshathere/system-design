
from enums import SeatStatus, SeatType
from seat import Seat
from screen import Screen
from user import User
from bookingManager import BookingManager, Booking
from movieBookingService import MovieBookingService
from payment import UpiPaymentStrategy, CreditCardPaymentStrategy, PaymentStrategy
from movie import Movie

if __name__ == "__main__":
    print("This is the main module for the movie booking system.")
    seats = [Seat(id="1", seatType=SeatType.REGULAR, seatStatus=SeatStatus.AVAILABLE), Seat(id="2", seatType=SeatType.VIP, seatStatus=SeatStatus.AVAILABLE)]
    screen = Screen(id="1", seats=seats)
    movie = Movie(id="1", name="Inception", duration="2h 28m")
    user = User(id="1", name="John Doe", email="john.doe@example.com")
    paymentStrategy = UpiPaymentStrategy(upiId="john.doe@example.com")
    creditCardStrategy = CreditCardPaymentStrategy(cardNumber="1234567890123456", cardHolderName="John Doe", expiryDate="12/25", cvv="123")
    bookingManager = BookingManager()
    movieBookingService = MovieBookingService(theaters=[], movies=[movie], bookingManager=bookingManager, paymentStrategies=[paymentStrategy, creditCardStrategy], users=[user], screens=[screen], seats=seats, bookings=[])
    movieBookingService.bookSeat(user, movie, screen, seats[0], paymentStrategy)
    movieBookingService.bookSeat(user, movie, screen, seats[1], paymentStrategy)
    movieBookingService.cancelBooking(movieBookingService.bookings[0])
