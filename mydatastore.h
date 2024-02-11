#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"
#include <map>
#include <set>
#include <vector>

class MyDataStore : public DataStore {
public:
    MyDataStore();
    ~MyDataStore() override;

    void addProduct(Product* p) override;
    void addUser(User* u) override;

    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;

    // Additional functionalities specific to MyDataStore
    // Example: void viewCart(const std::string& userName);
    // Example: void buyCart(const std::string& userName);
    void addToCart(const std::string& username, Product* p);
    void viewCart(const std::string& username);
    void buyCart(const std::string& username);

private:
    std::map<std::string, std::set<Product*>> keywordsToProducts;
    std::map<std::string, User*> users;
    // Additional data structures as needed for carts, etc.
    std::map<std::string, std::vector<Product*>> userCarts;
};

#endif // MYDATASTORE_H
