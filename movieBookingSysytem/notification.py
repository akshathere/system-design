from abc import ABC, abstractmethod
from bookingManager import Booking

class BookingObserver(ABC):
    @abstractmethod
    def update(self, eventType:str, booking:Booking):
        pass

class EmailNotificationObserver(BookingObserver):
    def update(self, eventType:str, booking:Booking):
        print(f"Email sent to {booking.user.email}: Booking {eventType} for {booking.movie.name} at {booking.theater.name}")
