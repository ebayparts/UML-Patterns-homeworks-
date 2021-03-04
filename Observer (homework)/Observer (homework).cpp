#include <iostream>
#include "Product.h"

int main()
{
    Forex UsdUah("USD/UAH", 27.85);

    Bidder bankA("BNP Paribas Group",100);
    UsdUah.subscribe(&bankA);

    Bidder bankB("Bank Of America",200);
    UsdUah.subscribe(&bankB);

    Bidder broker("Saxo Bank",40);     // this bank is working like a broker
    UsdUah.subscribe(&broker);

    UsdUah.raisePrice(0.35);
    UsdUah.lowerPrice(0.4);
    UsdUah.unsubscribe(&bankA);
    UsdUah.lowerPrice(0.2);




}
