#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Publication {
private:
    struct Author {
        string firstName;
        string lastName;
    };

    vector <Author> authors;

protected:
    string publicationName;
    int publicationPrice;

public:
    int setPrice(int price) {
        publicationPrice = price;
        return price;
    }

    int getPrice()  {
        return publicationPrice;
    }

    vector <Author> setAuthors(string F1, string L1) {
        authors = {{F1,L1}};
        return authors;
    }

    vector <Author> setAuthors(string F1, string L1, string F2, string L2) {
        authors = {{F1,L1},{F2,L2}};
        return authors;
    }

    vector <Author> setAuthors(string F1, string L1, string F2, string L2, string F3, string L3) {
        authors = {{F1,L1},{F2,L2},{F3, L3}};
        return authors;
    }

    string listAuthors() {

        if (authors.size() == 1) {
            string myAuthorFName1 = authors[0].firstName;
            string myAuthor1 = authors[0].lastName + ", " + myAuthorFName1[0] + ".,";
            return myAuthor1;

        } else if (authors.size() == 2) {
            string myAuthorFName1 = authors[0].firstName;
            string myAuthorFName2 = authors[1].firstName;
            string myAuthors = authors[0].lastName + ", " + myAuthorFName1[0] + "., " + authors[1].lastName + ", " + myAuthorFName2[0] + "., ";
            return myAuthors;

        } else if (authors.size() == 3) {
            string myAuthorFName1 = authors[0].firstName;
            string myAuthorFName2 = authors[1].firstName;
            string myAuthorFName3 = authors[2].firstName;
            string myAuthors = authors[0].lastName + ", " + myAuthorFName1[0] + "., " + authors[1].lastName + ", " + myAuthorFName2[0] + "., " + authors[2].lastName + ", " + myAuthorFName3[0] + ".,";
            return myAuthors;

        } else {
            cout << "Error";
            return "Error";
        }
    }
};

class Book: public Publication {
public:
    string ISBN;
    string bookName;
    int pages;
    int year;
    int bookPrice;

    string setBookName(string Name) {
        bookName = Name;
        return bookName;
    }

    string getBookName() {
        string getName = bookName;
        return getName;
    }
    Publication price (int x) {
        bookPrice = x;
    };
};

class Journal: public Publication {
public:
    string ISSN;
    string journalName;

    string setJournalName(string Name) {
        journalName = Name;
        return Name;
    }
    string getJournalName() {
        string getName = journalName;
        return getName;
    }


};

class Article: public Journal {
public:
    int volumeNumber, issueNumber, year, firstPage, lastPage;
    string title;

    string citation() {
        string journalName = getJournalName();
        string yearString = to_string (year);
        string volumeNumberString = to_string(volumeNumber);
        string issueNumberString = to_string(issueNumber);
        string firstPageString = to_string(firstPage);
        string lastPageString = to_string(lastPage);

        string myAuthor = listAuthors();

        string myString = myAuthor + " (" + yearString + ")" + ". " + title + ". " + journalName + ", " +
                volumeNumberString + "(" + issueNumberString + "), " + firstPageString + " - " + lastPageString;

        return myString;

    }

};



int main() {
    Publication P;
    Article A;
    Book B;

    //Publication object creation & value assignment
    P.setPrice(24);
    //End of Publication object creation & value assignment

    //Book object creation & value assignment
    B.setAuthors("Manuel", "Oliveira", "Julia", "Roberts");
    B.setBookName("History of Cinematography");
    B.ISBN = "9876543210";
    int bookPages = B.pages = 123;
    int bookYear = B.year = 1995;
    B.setPrice(12);
    //End of Book object creation & value assignment

    //Article object creation & value assignment
    A.setAuthors("Joan", "Rider");
    A.setJournalName("International Journal of Computation");
    A.ISSN = "1234567890";
    A.title = "A Novel C++ program";
    int articleYear = A.year = 1996;
    int articleVolumeNumber = A.volumeNumber = 4;
    int articleIssueNumber = A.issueNumber = 2;
    int articleFirstPage = A.firstPage = 45;
    int articleLastPage = A.lastPage = 99;
    A.setPrice(60);
    A.citation();
    //End of Article object creation & value assignment

    //Price int assignment
    int pubPrice = P.getPrice();
    int bookPrice = B.getPrice();
    int articlePrice = A.getPrice();
    //End of Price int assignment

    //Price to_string methods
    string pubPriceString = to_string(pubPrice);
    string bookPriceString = to_string(bookPrice);
    string articlePriceString = to_string(articlePrice);
    //End of Price to_string methods

    //Book to_string Methods
    string bookPagesString = to_string(bookPages);
    string bookYearString = to_string(bookYear);
    //end Book to_string methods


    //Article to_string methods
    string articleYearString = to_string(articleYear);
    string articleVolumeNumberString = to_string(articleVolumeNumber);
    string articleIssueNumberString = to_string(articleIssueNumber);
    string articleFirstPageString = to_string(articleFirstPage);
    string articleLastPageString = to_string(articleLastPage);
    //End Article to_string methods

    //Creation of bookInfo & articleInfo for works array
    string bookInfo = B.listAuthors() + B.getBookName() + ", "  + B.ISBN + ", "  + bookPagesString + ", "  + bookYearString + ", "  + bookPriceString;
    string articleInfo = A.listAuthors() + A.getJournalName() + ", " + A.ISSN + ", " + A.title + ", " + articleYearString + ", " + articleVolumeNumberString + "(" + articleIssueNumberString + "), " + articleFirstPageString + "-" + articleLastPageString;
    //end of Creation of bookInfo & articleInfo for works array

    //Works array creation and loop
    string works[20] = {};
    works[0] = "0. " + pubPriceString;
    for (int i = 2; 20 > i; i++) {
        string num = to_string(i);
        works[i] = num + ". " + bookInfo;
        i++;
    }
    for (int i = 1; 20 > i; i++) {
        string num = to_string(i);
        works[i] = num + ". " + articleInfo;
        i++;
    }
    //End of Works array creation and loop

    //Works array print loop
    for (int i = 0; i < 20; i++) {
        if (i == 0) {
            cout << works[i] << endl;
        } else if ((i & 1) == 0) {
            cout << works[i] << endl;
        } else {
            cout << works[i] << endl;
        }
    }
    //End of Works array print loop


    cout << "" << endl;
    cout << "Citation: " + A.citation() << endl;
    return 0;

}
