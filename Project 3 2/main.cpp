//
// Kelly Tran
// 405808641
// CS31
// Project 5 Report
//

#include <iostream>
#include <string>
#include <cassert>

#include "PlaneFlight.hpp"
#include "FrequentFlyerAccount.hpp"

using namespace std;

int main()
{
    // sample test code
    PlaneFlight laxnyc( "Kelly", "LAX", "NYC", 49.00, 285 );
    PlaneFlight nyclax( "Kelly", "NYC", "LAX", 399.00, 2800 );
    PlaneFlight sample( "Kelly", "Sample", "Sample", 0, 1 );
    FrequentFlyerAccount account( "Kelly" );
    assert( laxnyc.getFromCity( ) == "LAX" );
    assert( laxnyc.getToCity( ) == "NYC" );
    assert( laxnyc.getName( ) == "Kelly" );
    assert( std::to_string( laxnyc.getCost( ) ) == "49.000000" );
    assert( std::to_string( nyclax.getMileage( ) ) == "285.000000" );
    
    // account balance starts at zero...
    assert( std::to_string( account.getBalance( ) ) == "0.000000" );
    assert( account.getName( ) == "Howard" );
    assert( account.canEarnFreeFlight( 3300.00 ) == false );
    
    // flights add to an account balance
    assert( account.addFlightToAccount( laxnyc ) == true );  // returns true because the names match
    assert( account.addFlightToAccount( nyclax ) == true );   // returns true because the names match
    assert( std::to_string( account.getBalance( ) ) == "3085.000000" );
    // free flights reduce an account balance
    if (account.canEarnFreeFlight( 285 ))
    {
        assert( account.freeFlight( "LAS", "LAX", 285, sample ) == true );
        // Howard earned a free flight...
        assert( sample.getName( ) == "Howard" );
        assert( std::to_string( sample.getCost( ) ) == "0.000000" );
        assert( sample.getFromCity( ) == "LAS" );
        assert( sample.getToCity( ) == "LAX" );
        assert( std::to_string( sample.getMileage( ) ) == "285.000000" );
        // account has been reduced for this free flight...
        assert( std::to_string( account.getBalance( ) ) == "2800.000000" );
    }
    else
    {
        assert( false );  // there are enough miles in the account...
    }
    // non-matching names are ignored
    PlaneFlight muffin( "Muffin", "LAX", "Doggie Heaven", 500, 500 );
    assert( account.addFlightToAccount( muffin ) == false );
    assert( std::to_string( account.getBalance( ) ) == "2800.000000" );
    cout << "all tests passed!" << endl;
    return( 0 );
}
