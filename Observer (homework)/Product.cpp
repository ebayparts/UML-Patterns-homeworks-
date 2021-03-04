#include "Product.h"

void Forex::subscribe(ISubscriber* subscriber)
{
	if (subscriber != nullptr) {
		bidders.push_back(subscriber);
		cout << "\t\t\t" << subscriber->getName() << " was subscribed to trades on "<<getName()<<endl;
	}
}

void Forex::unsubscribe(ISubscriber* subscriber)
{
	if (subscriber != nullptr) {
		auto it = find(begin(bidders), end(bidders), subscriber);
		if (it != end(bidders))
		{
			cout << "\t----" << subscriber->getName() << "---- was unsubscribed \n";
			bidders.erase(it);
		}
	}
}

void Forex::notify(const char operation)
{
	if (operation == '-')
	{
		for (auto& buyers : bidders)
		{
			buyers->selling(this);
		}
	}
	else if (operation == '+')
	{
		for (auto& buyers : bidders)
		{
			buyers->buying(this);
		}
	}
}

void Forex::raisePrice(const float& addend)
{
	this->price += addend;
	notify('+');
}

void Forex::lowerPrice(const float& substractor)
{
	if (this->price - substractor >= 0)
	{
		this->price -= substractor;
		notify('-');
	}
}

void Bidder::update(Forex* product)
{
	cout << "Buyer " << name << " notified about price changing: " << product->getName()
		<< " has new price " << product->getPrice() << endl;
}

void Bidder::buying(Forex* product)
{
	cout << "Buyer " << name << " notified about price lowering: " << product->getName()
		<< " has new price " << product->getPrice() << endl;
	accountBalance--;
	cout << "\tAs a result, buyer: " << name << " brought: " << product->getName()
		<< "\nin the ammount of 1 billion $, account balance is now: $" << getAccountBalance() << " billions.\n\n";
}

void Bidder::selling(Forex* product)
{
	cout << "Buyer " << name << " notified about price raising: " << product->getName()
		<< " has new price " << product->getPrice() << endl;
	accountBalance++;
	cout << "\tAs a result, seller: " << name << " sold: " << product->getName()
		<< "\nin the ammount of 1 billion $, account balance is now: $" << getAccountBalance() << " billions.\n\n";
}