#include <iostream>
#include <cstring>

using namespace std;

//Main class with all cummon params and methods
class Unit
{
public:
	Unit() :																//Defoult constructor
		_population(0),
		_square(0),
		_name("")
	{}
	Unit(const int population, const double square, const string name) :	//Contructor of the abstract class 
		_population(population),
		_square(square)
	{}

	virtual int GetPopulation()												//Check population of the unit
	{
		return _population;
	}
	virtual void ChangePopulation(const int& change)						//Change value of the population
	{
		_population += change;
	}
	virtual double GetSquare()												//Check square of the unit
	{
		return _square;
	}
	virtual string GetName()											//Get name of the unit
	{
		return _name;
	}
	virtual const Unit& operator+(const Unit& value) const = 0;				//Operator overloading to union units

protected:
	string _name;			//Name of the unit
	int _population;		//Value of the population of the unit
	double _square;			//Value of the square of the unit
};

//Class City, child of the Unit
class City : public Unit
{
public:
	//Defoult constructor
	City() : Unit(),
		_crime(0),
		_mayor("")
	{
	}
	//Constructor of the class City
	City(const int population, const double square, const string name, const int crime, const string mayor) :
		Unit(_population, _square, _name),
		_crime(crime),
		_mayor(mayor)
	{	}
	//Joining the city
	const Unit& operator+(const Unit& other) const override
	{
		Unit* result = new City(*this);

		//Operation

		return *result;
	}
	//Change mayor of the City or elections
	void Elections(const string& other)
	{
		_mayor = other;
	}

	//Check level of crime
	int GetLevelOfCrime()
	{
		return _crime;
	}

private:
	string _mayor;		//Name of the mayor of the City
	int _crime;			//Level of crime in the City
};

//Class Country, child of the Unit
class Country : public Unit
{
public: 
	//Defoult constructor
	Country() : Unit(),
		_capital(""),
		_regnumber(0)
	{	
	}
	//Constructor of the class Country
	Country(const int population, const double square, const string name, const string capital, const int regnumber) : 
		Unit(_population, _square, _name),
		_capital(capital),
		_regnumber(regnumber)
	{
	}
	//Union of Countries
	const Unit& operator+(const Unit& other) const override
	{
		Unit* result = new Country(*this);

		//Operation

		return *result;
	}
	//Check the Capital of the Country
	string GetCapital()
	{
		return _capital;
	}
	//Get Numbers of Regions in the Country
	int GetRegNumber()
	{
		return _regnumber;
	}

private:
	string _capital;		//Name of the Capital of the Country
	int _regnumber;			//Numbers of Regions in the Country
};

//Class Region, child of the Unit
class Region : public Unit
{
public:
	//Defoult constructor
	Region() : Unit(),
		_center(""),
		_citynumb(0)
	{
	}
	//Constructor of the class Region
	Region(const int population, const double square, const string name, const string center, const int citynumb) :
		Unit(_population, _square, _name),
		_center(center),
		_citynumb(citynumb)
	{
	}
	//Union of Regions
	const Unit& operator+(const Unit& other) const override
	{
		Unit* result = new Region(*this);

		//Operation

		return *result;
	}
	//Check the Center of the Region
	string GetRegionalCenter()
	{
		return _center;
	}
	//Check number of Cities in this region
	int GetCityNumb()
	{
		return _citynumb;
	}

private:
	string _center;		//Name of the regional center of the Region
	int _citynumb;		//Numer of cities in this Region
};

int main()
{
	system("pause");
	return 0;
}