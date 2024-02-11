#include "clothing.h"
#include "util.h"
#include <sstream>

Clothing::Clothing(const std::string name, double price, int qty, const std::string& size, const std::string& brand)
    : Product("clothing", name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const {
    std::set<std::string> kw = parseStringToWords(name_);
    std::set<std::string> brandKw = parseStringToWords(brand_);
    kw.insert(brandKw.begin(), brandKw.end());
    return kw;
}

std::string Clothing::displayString() const {
    std::stringstream ss;
    ss << name_ << "\n" << "Size: " << size_ << " Brand: " << brand_ << "\n" << price_ << " " << qty_ << " left.";
    return ss.str();
}

void Clothing::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << std::endl;
}
