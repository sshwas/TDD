#include "pch.h"
#include "../VideoRental/Customer.cpp";
#include "../VideoRental/Rental.cpp";
#include "../VideoRental/Movie.cpp";

using std::string;
const string NAME = string("NAME_NOT_IMPORTANT");
const string TITLE = string("TITLE_NOT_IMPORTANT");

class CustimerFixture : public testing::Test
{
public:
    //arrange
    Customer customer = Customer(NAME);

    Rental createRentalFor(int daysRented, int priceCode)
    {
        Movie movie = Movie(TITLE, priceCode);
        Rental rental = Rental(movie, daysRented);
        return rental;
    }
};


TEST_F(CustimerFixture, StatementForNoRental) {
    //arrange

    //act

    //assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("Amount owed is 0.0\n")
        + string("You earned 0 frequent renter points"));
}

TEST_F(CustimerFixture, StatementForRegularMovieRentalForLessThan3Days) {
    // arrange
    customer.addRental(createRentalFor(2, Movie::REGULAR));

    // act

    // assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t2.0\n")
        + string("Amount owed is 2.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustimerFixture, StatementForRegularMovieRentalForMoreThan2Days) {
    // arrange
    customer.addRental(createRentalFor(3, Movie::REGULAR));

    // act

    // assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.5\n")
        + string("Amount owed is 3.5\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustimerFixture, StatementForNewReleaseMovie) {
    // arrange
    customer.addRental(createRentalFor(1, Movie::NEW_RELEASE));

    // act

    // assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 3.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustimerFixture, StatementForChildrensMovieRentalMoreThan3Days) {
    // arrange
    customer.addRental(createRentalFor(4, Movie::CHILDRENS));

    // act

    // assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 3.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustimerFixture, StatementForChildrensMovieRentalMoreThan4Days) {
    // arrange
	customer.addRental(createRentalFor(3, Movie::CHILDRENS));

    // act

    // assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t1.5\n")
        + string("Amount owed is 1.5\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustimerFixture, StatementForNewReleaseMovieRentalMoreThan1Day) {
    // arrange
    customer.addRental(createRentalFor(2, Movie::NEW_RELEASE));

    // act

    // assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t6.0\n")
        + string("Amount owed is 6.0\n")
        + string("You earned 2 frequent renter points"));
}

TEST_F(CustimerFixture, StatementForFewMovieRental) {
    // arrange
    customer.addRental(createRentalFor(1, Movie::REGULAR));
    customer.addRental(createRentalFor(4, Movie::NEW_RELEASE));
    customer.addRental(createRentalFor(4, Movie::CHILDRENS));

    // act

    // assert
    EXPECT_EQ(customer.statement(), string("Rental Record for NAME_NOT_IMPORTANT\n")
        + string("\tTITLE_NOT_IMPORTANT\t2.0\n")
        + string("\tTITLE_NOT_IMPORTANT\t12.0\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 17.0\n")
        + string("You earned 4 frequent renter points"));
}