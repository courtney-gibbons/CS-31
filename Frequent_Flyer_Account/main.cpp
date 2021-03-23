// Courtney Gibbons
// 705485300

#include <iostream>
#include <string>
#include <cassert>

#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

using namespace std;

int main()
{
    // sample test code
    PlaneFlight shortleg( "Howard", "LAX", "LAS", 49.00, 285 );
    PlaneFlight longleg( "Howard", "LAS", "NYC", 399.00, 2800 );
    PlaneFlight sample( "Sample", "Sample", "Sample", 0, 1 );
    FrequentFlyerAccount account( "Howard" );

    assert( shortleg.getFromCity( ) == "LAX" );
    assert( shortleg.getToCity( ) == "LAS" );
    assert( shortleg.getName( ) == "Howard" );
    assert( std::to_string( shortleg.getCost( ) ) == "49.000000" );
    assert( std::to_string( shortleg.getMileage( ) ) == "285.000000" );

    // account balance starts at zero...
    assert( std::to_string( account.getBalance( ) ) == "0.000000" );
    assert( account.getName( ) == "Howard" );
    assert( account.canEarnFreeFlight( 3300.00 ) == false );

    // flights add to an account balance
    assert( account.addFlightToAccount( shortleg ) == true );  // returns true because the names match
    assert( account.addFlightToAccount( longleg ) == true );   // returns true because the names match
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
    
    PlaneFlight f( "Howard", "LAX", "LAS", 65.00, 285 );
    FrequentFlyerAccount account_h( "Howard" );
    account_h.addFlightToAccount( f ); // +285
    assert( account_h.getName() == "Howard" );
    assert( std::to_string( account_h.getBalance() ) == "285.000000" );
    account_h.addFlightToAccount( f ); // +285
    assert( account_h.canEarnFreeFlight( 285 ) );
    account_h.freeFlight( "LAS", "LAX", 285, f ); // -285
    assert( f.getName() == "Howard" );
    assert( f.getFromCity() == "LAS" );
    assert( f.getToCity() == "LAX" );
    assert( f.getCost() == 0 );
    assert( f.getMileage() == 285 );
    account_h.addFlightToAccount( f ); // +0 bc this is the free flight, doesn't add miles, miles already been taken off
    assert( std::to_string( account_h.getBalance() ) == "285.000000" );
    
    PlaneFlight f2( "Howard", "LAX", "LAS", 65.00, 285 );
    f2.setToCity( "LAX" );
    f2.setFromCity( "LAS" );
    assert( f2.getToCity() == "LAS" );
    assert( f2.getFromCity() == "LAX" );
    
    PlaneFlight FFF("Howard", "LAX", "LAS", 0, 285);
    FrequentFlyerAccount accountFFF("Howard");
    assert( std::to_string( accountFFF.getBalance() ) == "0.000000"  );
    account.addFlightToAccount(FFF);
    assert( std::to_string( accountFFF.getBalance() ) == "0.000000"  );
    
    PlaneFlight lecture1("Howard", "Somewhere", "Over the Rainbow", 400, 400);
    PlaneFlight lecture2("Pixie", "LAX", "LHR", 999, 5285);
    FrequentFlyerAccount account_lecture("Pixie");
    account_lecture.addFlightToAccount(lecture2);
    assert( to_string(account_lecture.getBalance()) == "5285.000000" );
    account_lecture.freeFlight("LAX", "LAS", 285, lecture1);
    assert( to_string(account_lecture.getBalance()) == "5000.000000" );
    account_lecture.addFlightToAccount(lecture1);
    assert( to_string(account_lecture.getBalance()) == "5000.000000" );
    
    PlaneFlight fh("Howard", "LAX", "LAS", 0, 285);
    FrequentFlyerAccount accounth("Howard");
    assert( std::to_string( accounth.getBalance() ) == "0.000000"  );
    accounth.addFlightToAccount(fh);
    assert( std::to_string( accounth.getBalance() ) == "0.000000"  );
    
    // MY TEST CASES
    
    // cost < 0 => cost = -1 (constructor + mutator)
    PlaneFlight flight1( "Courtney", "SFO", "Aperture Science", -10.00, 1000 );
    assert( flight1.getCost() == -1 );
    PlaneFlight flight2( "Courtney", "Columbia", "Stardew Valley", 100.00, 1000 );
    assert( to_string( flight2.getCost() ) == "100.000000" );
    flight2.setCost( -100.00 );
    assert( flight2.getCost() == -1 );
    
    // mileage < 0 => mileage = -1 (constructor + mutator)
    PlaneFlight flight3( "Courtney", "Aperture Science", "Combine", 10.00, -1000 );
    assert( flight3.getMileage() == -1 );
    PlaneFlight flight4( "Courtney", "Germany", "Combine", 10.00, 1000 );
    assert( to_string( flight4.getMileage() ) == "1000.000000" );
    flight4.setMileage(-20);
    assert( flight4.getMileage() == -1 );
    
    // empty from => ignored (constructor + mutator)
    PlaneFlight flight5( "Courtney", "", "Combine", 10.00, 1000 );
    assert( flight5.getFromCity() == "" ); // bc uninitialized strings are blank - ignoring it
    PlaneFlight flight6( "Courtney", "Germany", "Combine", 10.00, 1000 );
    assert( flight6.getFromCity() == "Germany" );
    flight6.setFromCity( "" );
    assert( flight6.getFromCity() == "Germany" );
    
    // empty to => ignored (constructor + mutator)
    PlaneFlight flight7( "Courtney", "Arkansas", "", 10.00, 1000 );
    assert( flight7.getToCity() == "" ); // bc uninitialized strings are blank - ignoring it
    PlaneFlight flight8( "Courtney", "Germany", "Combine", 10.00, 1000 );
    assert( flight8.getToCity() == "Combine" );
    flight8.setToCity( "" );
    assert( flight8.getToCity() == "Combine" );
    
    // to = from => ignored (constructor + mutator)
    PlaneFlight flight9( "Courtney", "Arkansas", "Arkansas", 10.00, 1000 );
    assert( flight9.getFromCity() == "" ); // bc uninitialized strings are blank - ignoring it
    assert( flight9.getToCity() == "" ); // bc uninitialized strings are blank - ignoring it
    PlaneFlight flight10( "Courtney", "Seattle", "Victoria", 10.00, 1000 );
    assert( flight10.getFromCity() == "Seattle" );
    assert( flight10.getToCity() == "Victoria" );
    flight10.setToCity("Seattle");
    assert( flight10.getFromCity() == "Seattle" );
    assert( flight10.getToCity() == "Victoria" );
    flight10.setFromCity("Victoria");
    assert( flight10.getFromCity() == "Seattle" );
    assert( flight10.getToCity() == "Victoria" );
    
    // empty name => ignored (constructor + mutator)
    PlaneFlight flight11( "", "Alaska", "Michigan", 10.00, 1000 );
    assert( flight11.getName() == "" ); // bc uninitialized strings are blank - ignoring it
    PlaneFlight flight12( "Courtney", "Alaska", "Michigan", 10.00, 1000 );
    assert( flight12.getName() == "Courtney" );
    flight12.setName("");
    assert( flight12.getName() == "Courtney" );
    
    // initial balance = 0
    FrequentFlyerAccount courtney_account( "Courtney" );
    assert( courtney_account.getBalance() == 0 );
    
    // add flight returns true when names match
    PlaneFlight flight13( "Courtney", "SFO", "LAX", 10.00, 300 );
    assert( courtney_account.addFlightToAccount( flight13 ) == true );
    
    // balance increases when adding flights to account
    assert( to_string( courtney_account.getBalance() ) == "300.000000" );
    
    // add flight returns false when names don't match
    PlaneFlight flight14( "Kim", "SFO", "LAX", 10.00, 200 );
    assert( courtney_account.addFlightToAccount( flight14 ) == false );
    
    // balance doesn't change when add flight names don't match
    assert( to_string( courtney_account.getBalance() ) == "300.000000" );
    
    // can earn free flight => true when enough balance
    assert( courtney_account.canEarnFreeFlight( 300 ) == true );
    
    // can earn free flight => false when not enough balance
    assert( courtney_account.canEarnFreeFlight( 500 ) == false );
    
    // check free flight objects => 0 cost
    PlaneFlight flight15( "Courtney", "SFO", "LAX", 10.00, 100 );
    courtney_account.freeFlight( "SFO", "LAX", 100, flight15 );
    assert( flight15.getName() == "Courtney" );
    assert( flight15.getFromCity() == "SFO" );
    assert( flight15.getToCity() == "LAX" );
    assert( flight15.getCost() == 0 );
    assert( to_string( flight15.getMileage() ) == "100.000000" );
    
    // add flight fore a free flight returns true when names match
    assert( courtney_account.addFlightToAccount( flight15 ) == true );
    
    // free flight reduces mileage
    assert( to_string( courtney_account.getBalance() ) == "200.000000" );
    
    // free flight => true when enough balance
    assert( courtney_account.freeFlight( "SFO", "LAX", 100, flight15 ) == true );
    assert( to_string( courtney_account.getBalance() ) == "100.000000" );
    
    // free flight => true when balance decreases to 0
    assert( courtney_account.freeFlight( "SFO", "LAX", 100, flight15 ) == true );
    assert( to_string( courtney_account.getBalance() ) == "0.000000" );
    
    // free flight => false when not enough balance, doesn't affect balance
    assert( courtney_account.freeFlight( "SFO", "LAX", 100, flight15 ) == false );
    assert( to_string( courtney_account.getBalance() ) == "0.000000" );
    
    // set balance to 300 (since that last free flight brought us down to 0)
    PlaneFlight flight16( "Courtney", "SFO", "LAX", 10.00, 300 );
    courtney_account.addFlightToAccount( flight16 );
    assert( to_string( courtney_account.getBalance() ) == "300.000000" );
    
    // free flight => false when to = "", doesn't affect balance
    PlaneFlight flight17( "Courtney", "SFO", "LAX", 10.00, 100 );
    assert( courtney_account.freeFlight( "", "LAX", 100, flight17 ) == false );
    assert( to_string( courtney_account.getBalance() ) == "300.000000" );
    
    // free flight => false when from = "", doesn't affect balance
    PlaneFlight flight18( "Courtney", "SFO", "LAX", 10.00, 100 );
    assert( courtney_account.freeFlight( "SFO", "", 100, flight18 ) == false );
    assert( to_string( courtney_account.getBalance() ) == "300.000000" );
    
    // free flight => false when to = from, doesn't affect balance
    PlaneFlight flight19( "Courtney", "SFO", "LAX", 10.00, 100 );
    assert( courtney_account.freeFlight( "LAX", "LAX", 100, flight19 ) == false );
    assert( to_string( courtney_account.getBalance() ) == "300.000000" );
    
    // adding your free flight doesnt affect mileage
    PlaneFlight flight20( "Courtney", "SFO", "LAX", 10.00, 100 );
    courtney_account.freeFlight( "SFO", "LAX", 100, flight20 );
    assert( to_string( courtney_account.getBalance() ) == "200.000000" );
    courtney_account.addFlightToAccount( flight20 );
    assert( to_string( courtney_account.getBalance() ) == "200.000000" );
    
    // swapping to and from for our free flight (to = from at the start, we don't want this to be an error)
    PlaneFlight flight21( "Courtney", "SFO", "SEA", 10.00, 100 );
    assert( flight21.getName() == "Courtney" );
    assert( flight21.getFromCity() == "SFO" );
    assert( flight21.getToCity() == "SEA" );
    assert( to_string( flight21.getCost() ) == "10.000000" );
    assert( to_string( flight21.getMileage() ) == "100.000000" );
    courtney_account.freeFlight( "SEA", "SFO", 100, flight21 );
    assert( flight21.getName() == "Courtney" );
    assert( flight21.getFromCity() == "SEA" );
    assert( flight21.getToCity() == "SFO" );
    assert( flight21.getCost() == 0 );
    assert( to_string( flight21.getMileage() ) == "100.000000" );
    courtney_account.addFlightToAccount( flight21 );
    
    // roundtrip flights (to = from at the start, we don't want this to be an error)
    PlaneFlight flight22( "Courtney", "SFO", "SEA", 10.00, 100 );
    courtney_account.addFlightToAccount( flight22 );
    PlaneFlight flight23( "Courtney", "SEA", "SFO", 10.00, 100 );
    courtney_account.addFlightToAccount( flight23 );
    
    cerr << "all tests passed!" << endl;

    return( 0 );
    
}
