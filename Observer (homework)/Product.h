#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
class Forex;
__interface ISubscriber
{
	void update(Forex* product);
	void buying(Forex* product);
	void selling(Forex* product);
	const string& getName()const;
};
class Bidder : public ISubscriber	// "Buyer"
{
public:
	string name;
	double accountBalance;
	Bidder(const string& name = "NoNamed", const double& accountBalance = 0)
		:name(name), accountBalance(accountBalance)
	{}
	void update(Forex* product) override;
	void buying(Forex* product) override;
	void selling(Forex* product) override;
	const string& getName() const
	{
		return name;
	}
	const double& getAccountBalance() const
	{
		return accountBalance;
	}
};
class Forex		// asset that is traded on the market
{
	string name;
	float price;
	vector<ISubscriber*> bidders;
public:
	Forex(const string& name = "USD/UAH", const float& price = 27.85)
		:name(name), price(price)
	{}
	void subscribe(ISubscriber* subscriber);
	void unsubscribe(ISubscriber* subscriber);
	void setPrice(const float& newPrice);		//delete method?
	void raisePrice(const float& addend);
	void lowerPrice(const float& substractor);


	const string& getName() const
	{
		return name;
	}
	const float& getPrice() const
	{
		return price;
	}
protected:
	void notify(const char operation);
};