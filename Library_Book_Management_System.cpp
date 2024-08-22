#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <map>

class Book
{
private:
    std::string id;
    std::string title;
    std::string author;
    std::string genre;
    int yearOfPublication;
    bool isAvailable;
    int borrowCount;

public:
    // Constructor
    Book(std::string id, std::string title, std::string author, std::string genre, int year)
        : id(id), title(title), author(author), genre(genre), yearOfPublication(year), isAvailable(true) {}

    // Getter và Setter
    std::string getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getGenre() const { return genre; }
    int getYearOfPublication() const { return yearOfPublication; }

    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool status) { isAvailable = status; }

    int getBorrowCount() const { return borrowCount; }
    void incrementBorrowCount() { ++borrowCount; }
    // In thông tin sách
    void printBookInfo() const
    {
        std::cout << "ID: " << id << ", Title: " << title << ", Author: " << author
                  << ", Genre: " << genre << ", Year: " << yearOfPublication
                  << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
};

class User
{
private:
    std::string id;
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::vector<std::string> borrowedBooks;

public:
    // Constructor
    User(std::string id, std::string name, std::string email, std::string phoneNumber)
        : id(id), name(name), email(email), phoneNumber(phoneNumber) {}

    // Getter và Setter
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::vector<std::string> getBorrowedBooks() const { return borrowedBooks; }

    // Mượn sách
    void borrowBook(const std::string &bookId)
    {
        // Thêm phần tử bookId vào cuối vector.
        borrowedBooks.push_back(bookId);
    }

    // Trả sách
    void returnBook(const std::string &bookId)
    {
        // Xoá phần tử bookId và đưa các phần tử khác bookId ra trước,hàm remove trả về giá trị bookId vừa xoá,
        // Hàm erase sẽ xóa các phần tử từ iterator mà std::remove trả về đến  vị trí ngay sau phần tử cuối cùng của vector
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
    }

    // In thông tin người dùng
    void printUserInfo() const
    {
        std::cout << "User ID: " << id << ", Name: " << name << ", Email: " << email
                  << ", Phone: " << phoneNumber << std::endl;
        std::cout << "Borrowed Books: ";
        // In từng phần tử bookId
        for (const auto &bookId : borrowedBooks)
        {
            std::cout << bookId << " ";
        }
        std::cout << std::endl;
    }
};

class LibrarySystem
{
private:
    std::vector<Book> books;
    std::vector<User> users;
    int nextBookId = 1; // Biến lưu trữ ID tiếp theo cho sách
    int nextUserId = 1; // Biến lưu trữ ID tiếp theo cho người dùng

public:
    // Thêm sách vào hệ thống
    void addBook(const std::string &title, const std::string &author, const std::string &genre, int year)
    {
        // Tạo ID mới từ biến nextBookId
        std::string bookId = "B" + std::to_string(nextBookId++);
        // Thêm sách vào hệ thống
        books.emplace_back(bookId, title, author, genre, year);
    }

    // Thêm người dùng vào hệ thống
    void addUser(const std::string &name, const std::string &email, const std::string &phoneNumber)
    {

        // Tạo ID mới cho người dùng
        std::string userId = "U" + std::to_string(nextUserId++);
        // Thêm người dùng vào hệ thống
        users.emplace_back(userId, name, email, phoneNumber);
    }

    // Truy cập danh sách sách
    std::vector<Book> getBooks() const
    {
        return books;
    }

    // Truy cập danh sách người dùng
    std::vector<User> getUsers() const
    {
        return users;
    }
    // Mượn sách
    void borrowBook(const std::string &userId, const std::string &bookId)
    {
        // Tìm kiếm người dùng trong danh sách users
        auto userIt = std::find_if(users.begin(), users.end(), [&](const User &u)
                                   { return u.getId() == userId; });
        // Tìm kiếm sách trong danh sách books:
        auto bookIt = std::find_if(books.begin(), books.end(), [&](const Book &b)
                                   { return b.getId() == bookId; });

        // Đảm bảo rằng cả người dùng và sách đều được tìm thấy trong hệ thống
        if (userIt != users.end() && bookIt != books.end())
        {
            // Kiểm tra xem sách có sẵn để mượn không
            if (bookIt->getAvailability())
            {
                userIt->borrowBook(bookId);
                bookIt->setAvailability(false);
                bookIt->incrementBorrowCount();
                std::cout << "Book borrowed successfully." << std::endl;
            }
            else
            {
                std::cerr << "Book is not available." << std::endl;
            }
        }
        else
        {
            std::cerr << "User or Book not found." << std::endl;
        }
    }

    // Trả sách
    void returnBook(const std::string &userId, const std::string &bookId)
    {
        // Tìm kiếm người dùng trong danh sách users
        auto userIt = std::find_if(users.begin(), users.end(), [&](const User &u)
                                   { return u.getId() == userId; });
        // Tìm kiếm sách trong danh sách books
        auto bookIt = std::find_if(books.begin(), books.end(), [&](const Book &b)
                                   { return b.getId() == bookId; });

        // Đảm bảo rằng cả người dùng và sách đều được tìm thấy trong hệ thống
        if (userIt != users.end() && bookIt != books.end())
        {
            userIt->returnBook(bookId);
            bookIt->setAvailability(true);
            std::cout << "Book returned successfully." << std::endl;
        }
        else
        {
            std::cerr << "User or Book not found." << std::endl;
        }
    }

    // Tìm kiếm sách theo từ khoá
    void searchBooks(const std::string &query) const
    {
        for (const auto &book : books)
        {
            if ((book.getTitle() == query) ||
                (book.getAuthor() == query) ||
                (book.getGenre() == query))
            {
                book.printBookInfo();
            }
        }
    }

    // Liệt kê tất cả các sách
    void listAllBooks() const
    {
        for (const auto &book : books)
        {
            book.printBookInfo();
        }
    }

    // Liệt kê tất cả người dùng và sách họ đang mượn
    void listAllUsers() const
    {
        for (const auto &user : users)
        {
            user.printUserInfo();
        }
    }
    // Báo cáo các cuốn sách đang được mượn nhiều nhất
    void reportMostBorrowedBooks() const
    {
        if (books.empty())
        {
            std::cout << "No books in the system." << std::endl;
            return;
        }

        // Tìm số lần mượn lớn nhất
        int maxBorrowCount = 0;
        for (const auto &book : books)
        {
            if (book.getBorrowCount() > maxBorrowCount)
            {
                maxBorrowCount = book.getBorrowCount();
            }
        }

        if (maxBorrowCount == 0)
        {
            std::cout << "No books have been borrowed yet." << std::endl;
            return;
        }

        std::cout << "Most Borrowed Books (Borrowed " << maxBorrowCount << " times):" << std::endl;

        // In ra danh sách các sách có số lần mượn bằng maxBorrowCount
        for (const auto &book : books)
        {
            if (book.getBorrowCount() == maxBorrowCount)
            {
                book.printBookInfo();
            }
        }
    }
};

int main()
{
    LibrarySystem library;

    // Thêm sách
    library.addBook("To Kill a Mockingbird", "Harper Lee", "Novel", 1960);
    library.addBook("1984", "George Orwell", "Dystopian", 1949);
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 1925);
    library.addBook("Pride and Prejudice", "Jane Austen", "Romance", 1813);
    library.addBook("Moby-Dick", "Herman Melville", "Adventure", 1851);
    library.addBook("The Catcher in the Rye", "J.D. Salinger", "Novel", 1951);
    library.addBook("Brave New World", "Aldous Huxley", "Science Fiction", 1932);
    library.addBook("The Hobbit", "J.R.R. Tolkien", "Fantasy", 1937);
    library.addBook("Fahrenheit 451", "Ray Bradbury", "Dystopian", 1953);
    library.addBook("War and Peace", "Leo Tolstoy", "Historical Fiction", 1869);

    // Thêm người dùng
    library.addUser("Alice", "alice@example.com", "123456789");
    library.addUser("Bob", "bob@example.com", "987654321");

    // mươn sách
    library.borrowBook("U1", "B1");
    library.borrowBook("U2", "B2");
    bool running = true;

    while (running)
    {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Search for books\n";
        std::cout << "2. List all books\n";
        std::cout << "3. Browse books\n";
        std::cout << "4. Return a book\n";
        std::cout << "5. List all users\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        // Tìm kiếm sách
        case 1:
        {
            std::string query;
            std::cout << "Enter search query (author/title/genre): ";
            std::cin.ignore(); // Để bỏ qua ký tự newline còn lại trong bộ đệm
            std::getline(std::cin, query);
            library.searchBooks(query);
            break;
        }
        // In ra danh sách sách có trong thư viện
        case 2:
            library.listAllBooks();
            break;
        // mượn sách
        case 3:
        {
            std::string userId, bookId;
            std::cout << "Enter user ID: ";
            std::cin >> userId;
            std::cout << "Enter book ID: ";
            std::cin >> bookId;
            library.borrowBook(userId, bookId);
            break;
        }
        // Trả sách
        case 4:
        {
            std::string userId, bookId;
            std::cout << "Enter user ID: ";
            std::cin >> userId;
            std::cout << "Enter book ID: ";
            std::cin >> bookId;
            library.returnBook(userId, bookId);
            break;
        }
        // In ra danh sách user
        case 5:
            library.listAllUsers();
            break;
        case 6:
            running = false;
            std::cout << "Exiting the system. Goodbye!" << std::endl;
            break;

        default:
            std::cerr << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
