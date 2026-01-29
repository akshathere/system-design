#include <iostream>
#include <vector>

using namespace std;

class NonWithdrawableAccount {
public:
    virtual void deposit(int) = 0;
};
class WithdrawableAccount : public NonWithdrawableAccount {
public:
    virtual void withdraw(int) = 0;
};

class SavingsAccount : public WithdrawableAccount {
    int amount=0;
public: 
    void withdraw(int a) override {
        if(a > amount) {
            cout<<"Cannot withdraw"<<endl;
            return;
        }
        cout<<"Withdrawing "<<a<<endl;
        amount-=a;
    }
    void deposit(int a) override {
        amount+=a;
        cout<<"Deposited "<<a<<endl;
    }
};

class CurrentAccount : public WithdrawableAccount {
    int amount=0;
public: 
    void withdraw(int a) override {
        if(a > amount) {
            cout<<"Cannot withdraw"<<endl;
            return;
        }
        cout<<"Withdrawing "<<a<<endl;
        amount-=a;
    }
    void deposit(int a) override {
        amount+=a;
        cout<<"Deposited "<<a<<endl;
    }
};

class fixedDepositAccount : public NonWithdrawableAccount {
    int amount=0;
public: 
    void deposit(int a) override {
        amount+=a;
        cout<<"Deposited "<<a<<endl;
    }
};

class BankAccountClient{
    vector<NonWithdrawableAccount*> account1;
    vector<WithdrawableAccount*> account2;
public:
    BankAccountClient(vector<NonWithdrawableAccount*> account1,vector<WithdrawableAccount*> account2) {
        this->account1 = account1;
        this->account2 = account2;
    }   
    void processAccount() {
        for(auto i=0; i<account1.size(); i++) {
            account1[i]->deposit(100);
        }
        for(auto i=0; i<account2.size(); i++) {
            account2[i]->deposit(100);
                try{
                account2[i]->withdraw(50);
            } catch(...) {
                cout<<"Exception occurred during withdrawal"<<endl;
            }
        }
}
};

int main(){
    vector<WithdrawableAccount*> s;
    vector<NonWithdrawableAccount*> t;
    s.push_back(new  SavingsAccount());
    s.push_back(new  CurrentAccount());
    t.push_back(new  fixedDepositAccount());
    BankAccountClient* client = new BankAccountClient(t,s);
    client->processAccount();
    return 0;
}