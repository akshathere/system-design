#include <iostream>

using namespace std;
class DatabaseInterface {
    public:
    virtual void saveToDb()=0;
};
class mongoDb : public DatabaseInterface {
    public:
    void saveToDb() override{
        cout<<"Saving to MongoDB"<<endl;
    }
};
class mysqlDb : public DatabaseInterface {
    public:
    void saveToDb() override{
        cout<<"Saving to MySQL"<<endl;
    }
}  ;

class Application {
    DatabaseInterface* database; //dependency injection
    public:
    Application(DatabaseInterface* db) {database=db;}
    void saveData() {
        // Saving data to the database
        database->saveToDb();
    }

};

int main() {
    mysqlDb mysqldb;
    Application app(&mysqldb);
    app.saveData();

    mongoDb mongodb;
    Application app2(&mongodb);
    app2.saveData();
    return 0;
}

/// high level modules do not depend on low level modules
/// both depend on abstractions