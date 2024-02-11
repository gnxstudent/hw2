#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <set>
#include <string>

class Movie : public Product {
public:
    Movie(const std::string name, double price, int qty, const std::string& genre, const std::string& rating);
    ~Movie() override;

    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

protected:
    std::string genre_;
    std::string rating_;
};

#endif // MOVIE_H
