#include <iostream>
#include <vector>

using namespace std;

class Account {
public:
    virtual void withdraw(int) = 0;
    virtual void deposit(int) = 0;
};

class SavingsAccount : public Account {
    int amount=0;
public: 
    void withdraw(int a) override {
        if(a > amount) {
            cout<<"Cannot withdraw"<<endl;
            return;
        }
        amount-=a;
    }
    void deposit(int a) override {
        amount+=a;
    }
};

class CurrentAccount : public Account {
    int amount=0;
public: 
    void withdraw(int a) override {
        if(a > amount) {
            cout<<"Cannot withdraw"<<endl;
            return;
        }
        amount-=a;
    }
    void deposit(int a) override {
        amount+=a;
    }
};

class fixedDepositAccount : public Account {
    int amount=0;
public: 
    void withdraw(int a) override {
        cout<<"Cannot withdraw"<<endl;
        return;
    }
    void deposit(int a) override {
        amount+=a;
    }
};

class BankAccountClient{
    vector<Account*> account;
public:
    BankAccountClient(vector<Account*> account) {
        this->account = account;
    }   
    void processAccount() {
        for(auto i=0; i<5; i++) {
            account[i]->deposit(100);
            if(typeid(*account[i]) == typeid(fixedDepositAccount)) {
                    cout<<"skipping withdrawal for fixed deposit account"<<endl;
            }else{
                try{
                
                account[i]->withdraw(50);
            } catch(...) {
                cout<<"Exception occurred during withdrawal"<<endl;
            }
            }
    }
}
};

int main(){
    vector<Account*> s;
    s.push_back(new  SavingsAccount());
    s.push_back(new  CurrentAccount());
    s.push_back(new  fixedDepositAccount());
    BankAccountClient* client = new BankAccountClient(s);
    client->processAccount();
    return 0;
}