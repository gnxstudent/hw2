#include "book.h"
#include "util.h"
#include <sstream>

Book::Book(const std::string name, double price, int qty, const std::string& isbn, const std::string& author)
    : Product("book", name, price, qty), isbn_(isbn), author_(author) {}

Book::~Book() {}

std::set<std::string> Book::keywords() const {
    std::set<std::string> kw = parseStringToWords(name_);
    std::set<std::string> authorKw = parseStringToWords(author_);
    kw.insert(authorKw.begin(), authorKw.end());
    kw.insert(isbn_);
    return kw;
}

std::string Book::displayString() const {
    std::stringstream ss;
    ss << name_ << "\n" << "Author: " << author_ << " ISBN: " << isbn_ << "\n" << price_ << " " << qty_ << " left.";
    return ss.str();
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << std::endl;
}
