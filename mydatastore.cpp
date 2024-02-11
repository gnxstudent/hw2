#include "mydatastore.h"
#include "util.h"
#include <iostream>

MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore() {
    // Remember to deallocate any dynamic memory you allocate
}

void MyDataStore::addProduct(Product* p) {
    std::set<std::string> keywords = p->keywords();
    for (const std::string& keyword : keywords) {
        keywordsToProducts[keyword].insert(p);
    }
}

void MyDataStore::addUser(User* u) {
    users[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    std::set<Product*> results;
    if (type == 0) { // AND search
        for (auto& term : terms) {
            if (results.empty() && keywordsToProducts.find(term) != keywordsToProducts.end()) {
                results = keywordsToProducts[term];
            } else {
                results = setIntersection(results, keywordsToProducts[term]);
            }
        }
    } else if (type == 1) { // OR search
        for (auto& term : terms) {
            if (keywordsToProducts.find(term) != keywordsToProducts.end()) {
                results = setUnion(results, keywordsToProducts[term]);
            }
        }
    }
    return std::vector<Product*>(results.begin(), results.end());
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>" << std::endl;
    for (auto& pair : keywordsToProducts) {
        for (auto& product : pair.second) {
            product->dump(ofile);
        }
    }
    ofile << "</products>" << std::endl;

    ofile << "<users>" << std::endl;
    for (auto& pair : users) {
        pair.second->dump(ofile);
    }
    ofile << "</users>" << std::endl;
}

void MyDataStore::addToCart(const std::string& username, Product* p) {
    userCarts[username].push_back(p);
}

void MyDataStore::viewCart(const std::string& username) {
    if (userCarts.find(username) != userCarts.end()) {
        for (auto* p : userCarts[username]) {
            std::cout << p->displayString() << std::endl;
        }
    } else {
        std::cout << "Cart is empty or user not found" << std::endl;
    }
}

void MyDataStore::buyCart(const std::string& username) {
    if (userCarts.find(username) != userCarts.end()) {
        auto& cart = userCarts[username];
        auto it = cart.begin();
        while (it != cart.end()) {
            Product* p = *it;
            if (p->getQty() > 0) {
                p->subtractQty(1);
                // Assuming you have a method to update the user's balance
                // updateUserBalance(username, p->getPrice());
                it = cart.erase(it); // Remove the bought item from the cart
            } else {
                ++it;
            }
        }
    } else {
        std::cout << "Cart is empty or user not found" << std::endl;
    }
}
