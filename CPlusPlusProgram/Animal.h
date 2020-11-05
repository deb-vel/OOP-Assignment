#ifndef CPLUSPLUSPROGRAM_ANIMAL_H
#define CPLUSPLUSPROGRAM_ANIMAL_H


#include <string>
using namespace std;

//CLASS ANIMAL
class Animal{

public:
    string name;
    string species;
    double length;

    Animal();
    virtual ~Animal()=0; //destructor

    //setters
    void setName(string);
    void setLength(double);

    //getters
    string getName();
    double getLength();
    string getSpecies();

    //the below make Animal class an Abstract class
    virtual string getVenomous()=0;
    virtual string getFly()=0;
    virtual double getLitterSize()=0;
};

//THE FOLLOWING ARE ALL DERIVED CLASSES FROM THE ANIMALS CLASS

//CLASS MAMMAL
class Mammal: public Animal {
private:
    string noReturn = "";
    double averageLitterSize;
public:

    Mammal(string , double ,double );
    ~Mammal()override;
    void setLitterSize(double);
    double getLitterSize() override;
    string getVenomous() override;
    string getFly()override;

};

//CLASS REPTILE
class Reptile: public Animal{
private:
    string noReturn = "";
    double noReturn1 = 0;
    string venom;

public:
    Reptile(string, double, string);
    ~Reptile()override;
    void setVenomous(string);
    string getVenomous() override;
    string getFly()override;
    double getLitterSize() override;
};

//CLASS BIRD
class Bird: public Animal{
private:
    string noReturn = "";
    double noReturn1 = 0;
    string fly;

public:
    Bird(string, double, string);
    ~Bird()override;
    void setFly(string);
    string getFly() override;
    double getLitterSize() override;
    string getVenomous() override;
};



#endif //CPLUSPLUSPROGRAM_ANIMAL_H
