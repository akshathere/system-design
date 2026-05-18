from theater import Theater
from bookingManager import BookingManager, Booking
from seat import Seat
from screen import Screen
from user import User
from payment import PaymentStrategy
from enums import SeatStatus


class MovieBookingService:
    theaters:list[Theater]
    bookingManager:BookingManager
    paymentStrategies:list[PaymentStrategy]
    users:list[User]
    screens:list[Screen]
    seats:list[Seat]
    bookings:list[Booking]
    def __init__(self, theaters:list[Theater], bookingManager:BookingManager, paymentStrategies:list[PaymentStrategy], users:list[User], screens:list[Screen], seats:list[Seat], bookings:list[Booking]):
        self.theaters = theaters
        self.bookingManager = bookingManager
        self.paymentStrategies = paymentStrategies
        self.users = users
        self.screens = screens
        self.seats = seats
        self.bookings = bookings
    def bookSeat(self, user:User, screen:Screen, seat:Seat, paymentStrategy:PaymentStrategy):
        booking = Booking(id="1", user=user, screen=screen, seatList=[seat], paymentStrategy=paymentStrategy, totalAmount=0)
        booking.calculateTotalAmount()
        booking.book()
        self.bookings.append(booking)
    def cancelBooking(self, booking:Booking):
        for seat in booking.seatList:
            seat.seatStatus = SeatStatus.AVAILABLE
        self.bookings.remove(booking)
        print(f"Booking {booking.id} cancelled successfully for user {booking.user.name}")
    