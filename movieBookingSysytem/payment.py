from abc import ABC, abstractmethod

class PaymentStrategy(ABC):
    @abstractmethod
    def pay(self, amount:float):
        pass
class UpiPaymentStrategy(PaymentStrategy):
    def __init__(self, upiId:str):
        self.upiId = upiId
    def pay(self, amount:float):
        print(f"Processing UPI payment of {amount} using UPI ID: {self.upiId}")

class CreditCardPaymentStrategy(PaymentStrategy):
    def __init__(self, cardNumber:str, cardHolderName:str, expiryDate:str, cvv:str):
        self.cardNumber = cardNumber
        self.cardHolderName = cardHolderName
        self.expiryDate = expiryDate
        self.cvv = cvv
    def pay(self, amount:float):
        print(f"Processing credit card payment of {amount} for card holder: {self.cardHolderName}")