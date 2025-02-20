class Book:
    def __init__(self, name, autor, year):
        self.title = name
        self.autor = autor
        self.year = year
        self.available = True
        self.borrow_count = 0

    def information_book(self):
        print(f"Title: {self.title}, Autor: {self.autor}, Year: {self.year}")
    
    def rent_book(self):
        if self.available:
            self.available = False
            print(f"You rent ({self.title})")
            self.borrow_count+=1
        else:
            print(f"You cannot rent ({self.title}), beacuse it's already rent")

    def return_book(self):
        if not self.available:
            self.available = True
            print(f"You returned ({self.title})")
        else:
            print(f"({self.title}) is available")



class Library:
    def __init__(self):
        self.books = []
        self.user_books = {}
    

    def add_book(self,book):
        self.books.append(book)
        print(f"The book ({book.title}) was added in the library")

    def available_books(self):
        books_titles = [book for book in self.books if book.available]
        if books_titles:
            print("Available books:")

            for book in books_titles:
                print(f"- {book.title}")

        else: print("Not availiable books right now!")

    def list_borrowed_books(self):
        borrowed_books = [book for book in self.books if not book.available]
        if borrowed_books:
            print("Заети книги:")
            for book in borrowed_books:
                print(f"- {book.title}, Автор: {book.autor}")
        else:
            print("В момента няма заети книги.")

    def rent(self,user,title):
        if user not in self.user_books:
            self.user_books[user] = []

        if len(self.user_books[user]) >= 3:
            print(f"Потребителят '{user}' не може да наеме повече от 3 книги наведнъж.")
            return
        
        for book in self.books:
            if book.title == title:
                if book.available:
                    book.rent_book()
                    self.user_books[user].append(book)
                else:
                    print(f"Книгата '{title}' вече е заета.")
                return

        print(f"Книга със заглавие '{title}' не беше намерена в библиотеката.")

    def return_book(self,user,title):
        if user in self.user_books:
            for book in self.books:
                if book.title == title: 
                    book.return_book()
                    self.user_books[user].remove(book)
                    return
            print(f"Потребителят '{user}' не е наемал книгата '{title}'.")
        else:
            print(f"Book with title ({title}) was not found in the library")


    def search(self, keyword):
        matches = [book for book in self.books if keyword.lower() in book.title.lower() or keyword.lower() in book.autor.lower()]
        if matches:
            print("Matches:")
            for book in matches:
                book.information_book()
        else:
            print("Books not found!")



library = Library()
book1 = Book("The new neighbor", "Steven King", 2003)
book2 = Book("Story", "Adam Gary", 1977)
book3 = Book("It", "Steven King", 1999)
book4 = Book("The great wall", "Jennifer Grose", 2020)

library.add_book(book1)
library.add_book(book2)
library.add_book(book3)
library.add_book(book4)

library.available_books()

library.rent("Ivan","It")
library.rent("Ivan","Story")
library.rent("Ivan","The new neighbor")

library.rent("Ivan","The great wall")

library.return_book("Ivan","It")

library.list_borrowed_books()

library.search("wall")
library.search("King")
library.search("The")

library.available_books()
