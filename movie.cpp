#include "movie.h"
#include "util.h"
#include <sstream>

Movie::Movie(const std::string name, double price, int qty, const std::string& genre, const std::string& rating)
    : Product("movie", name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const {
    std::set<std::string> kw = parseStringToWords(name_);
    kw.insert(genre_);
    return kw;
}

std::string Movie::displayString() const {
    std::stringstream ss;
    ss << name_ << "\n" << "Genre: " << genre_ << " Rating: " << rating_ << "\n" << price_ << " " << qty_ << " left.";
    return ss.str();
}

void Movie::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << std::endl;
}
