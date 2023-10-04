/*
 Kelly Tran
 405808641
 CS31
*/

#include <iostream>
#include <cassert>
#include "BloodDonation.h"
#include "VacationAccount.h"

int main() {
    BloodDonation doner1( 752401, 45, 150);
    BloodDonation doner5( 752401, 45, 150);

    BloodDonation doner2( 889543, 55, 109.50);

    BloodDonation doner3( 89643244, 65, 187.55);

    BloodDonation doner4( 855565, 17, 127.00);

    VacationAccount account(752401);

    assert( doner1.getID( ) == 752401);
    
    assert( doner3.getID() == -1 );

    assert(doner2.getAge( ) ==55);

    assert(doner3.getWeight( ) == 187.550000 );

    // account balance starts at zero...
    assert( account.addVacationToAccount( doner1 ) == true );
    assert( account.addVacationToAccount( doner5 ) == true );

    assert( account.getBalance( ) == 8 );

    assert( account.getID( ) ==  752401);

    // Vacation adds to vacation balance

    assert( account.addVacationToAccount( doner2 ) == false );

    assert( account.addVacationToAccount( doner1 ) == true );

    assert( account.getBalance( ) == 12 );
    
    cout << "end lol " << endl;
}

