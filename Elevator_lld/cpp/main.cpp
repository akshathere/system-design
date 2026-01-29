#include <iostream>
#include <vector>
using namespace std;
class Product{
    public:
    int price;
    int name;
    Product(int p, int n):price(p), name(n){}
};

class ShoppingCart{
    vector<Product*>& products;
    public:
    ShoppingCart():products(*(new vector<Product*>())){}
    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }
    void removeProduct(Product* p){
        for(auto it = products.begin(); it != products.end(); ++it){
            if(*it == p){
                products.erase(it);
                break;
            }
        }
    }
    void calculateTotalPrice(){
        int totalPrice = 0;
        for(auto p: products){
            totalPrice += p->price;
        }
        cout<<"total price = "<<totalPrice<<endl;
    }
};

class InvoicePrinters{
    ShoppingCart* cart;
public: 
    InvoicePrinters(ShoppingCart* cart){
        this->cart = cart;
    }
    void printInvoice(){
        int totalPrice = 0;
        for(auto p: cart->getProducts()){
            totalPrice += p->price;
        }
        cout<<"invoice ="<<totalPrice<<endl;
    }
};
class DbPersistence{
    ShoppingCart* cart;

    public:
    virtual void  saveCart()=0;
};

class saveToSql : public DbPersistence{
    ShoppingCart* cart;
    public:
    saveToSql(ShoppingCart* cart){
        this->cart = cart;
    }
    void saveCart() override{
        cout<<"saving cart to sql db"<<endl;
    }
};
class saveToNoSql : public DbPersistence{
    ShoppingCart* cart;
    public:
    saveToNoSql(ShoppingCart* cart){
        this->cart = cart;
    }
    void saveCart() override{
        cout<<"saving cart to nosql db"<<endl;
    }
};
class saveToMongoDb : public DbPersistence{
    ShoppingCart* cart;
    public:
    saveToMongoDb(ShoppingCart* cart){
        this->cart = cart;
    }
    void saveCart() override{
        cout<<"saving cart to mongodb db"<<endl;
    }
};
int main(){
    ShoppingCart* cart = new ShoppingCart();
    Product* p1 = new Product(100, 1);
    Product* p2 = new Product(200, 2);
    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->calculateTotalPrice();
    InvoicePrinters* printer = new InvoicePrinters(cart);
    printer->printInvoice();
    DbPersistence* storageToSql = new saveToSql(cart);
    DbPersistence* storageTonoSql = new saveToNoSql(cart);
    DbPersistence* storageTomongo = new saveToMongoDb(cart);
    storageToSql->saveCart();
    storageTonoSql->saveCart();
    storageTomongo->saveCart();
    return 0;
}