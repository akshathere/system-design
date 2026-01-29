
class mongoDb{
    public:
    void saveToDb(){}
};
class mysqlDb{
    public:
    void saveToDb(){}
}  ;

class Application {
    mongoDb mongodb;
    mysqlDb mysqldb;
    public:
    void saveDataInSql() {
        // Saving data to MySQL
        mysqldb.saveToDb();
    }
    void saveDataInMongo() {
        // Saving data to MongoDB
        mongodb.saveToDb();
    }

};

/// tightly coupled code where high level modules depend on low level modules
/// violation of dependency inversion principle