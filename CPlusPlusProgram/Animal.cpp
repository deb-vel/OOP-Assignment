#include <iostream>
#include "Animal.h"
//FOR BASE CLASS ANIMAL

Animal::Animal(){}

Animal::~Animal() { //destructor
}

//SETTERS
void Animal::setName(string nameIn){
    name = nameIn;
}

void Animal::setLength(double lengthIn){
    length = lengthIn;
}

//GETTERS
string Animal::getName(){
    return name;
}

double Animal::getLength(){
    return length;
}

string Animal::getSpecies(){
    return species;
}

//FOR CLASS MAMMAL
Mammal::~Mammal() {}


Mammal::Mammal(string nameIn, double lengthIn,double averageLitterSizeIn){
    this->name=nameIn;
    this->length=lengthIn;
    averageLitterSize = averageLitterSizeIn;
    species = "Mammal";
}

void Mammal::setLitterSize(double litterSizeIn){
    averageLitterSize = litterSizeIn;
}
string Mammal:: getVenomous() {
    return noReturn;
}

string Mammal::getFly(){
    return  noReturn;
}

double Mammal:: getLitterSize(){
    return averageLitterSize;
}

//FOR CLASS REPTILE

Reptile::Reptile(string nameIn, double lengthIn,string venomIn){
    this->name=nameIn;
    this->length=lengthIn;
    venom = venomIn;
    species = "Reptile";
}

Reptile::~Reptile() {}

void Reptile::setVenomous(string venomIn){
    venom = venomIn;
}

string Reptile::getVenomous(){
    return venom;
}

string Reptile::getFly(){
    return  noReturn;
}
double Reptile::getLitterSize() {
    return noReturn1;
}


//FOR CLASS BIRD

Bird::Bird(string nameIn, double lengthIn,string flyIn){
    this->name=nameIn;
    this->length=lengthIn;
    fly = flyIn;
    species = "Bird";
}

Bird::~Bird(){}

void Bird::setFly(string flyIn) {
    fly = flyIn;
}

string Bird::getFly(){
    return fly;
}

double Bird::getLitterSize() {
    return noReturn1;
}
string Bird::getVenomous() {
    return noReturn;
}