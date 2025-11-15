#include <iostream>
#include "json.hpp"
using json = nlohmann::json;

class Book {
    std::string m_title{};
    int m_year{};
    bool m_available{};
    json m_jsonBook;

public:
    Book(const std::string_view title, const int year, const bool available)
    : m_title{title}, m_year{year}, m_available{available} {
    }

    void setBookInfoToJSON() {
        m_jsonBook["title"] = m_title;
        m_jsonBook["year"] = m_year;
        m_jsonBook["available"] = m_available;
        std::cout << "Book now in JSON format" << '\n';
    }

    const json& getBookJSON() {
        std::cout << "Returning JSON book: " << m_title << '\n';
        return m_jsonBook;
    }
};

class Library {
    json m_jsonBooks;
public:
    Library() = default;

    void addBookToJSONList(json& j) {
        if (!j.empty()) {
            m_jsonBooks.emplace_back(j);
        }
    }

    void getAllBooksFromJSON() const {
        for (auto& book : m_jsonBooks.items()) {
            std::cout << book.key() << " : " << book.value() << '\n';
        }
    }
};

int main() {
    Book harry("Harry Potter", 1985, true);
    harry.setBookInfoToJSON();
    Book superMan("Superman", 1979, true);
    superMan.setBookInfoToJSON();

    json harryJSON = harry.getBookJSON();
    json superManJSON = superMan.getBookJSON();

    Library library{};
    library.addBookToJSONList(harryJSON);
    library.addBookToJSONList(superManJSON);

    library.getAllBooksFromJSON();

    return 0;
}