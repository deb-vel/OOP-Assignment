#include<iostream>
#include "BST.h"
#include "fstream"
#include "Animal.h"
using namespace std;

int main(int argc, char* argv[]) {

    BST<Animal> bst;

    if (argc > 1) {
            ifstream file(argv[1]);
            if (!file) {
                throw "could not open file";
            }

            string speciesName;
            double length;
            double litterSize;
            string venom;
            string fly;
            string animalSearch;

            for (string word; file >> word;) { //loops through all the words inside the file
                if (word == "Insert") { //if word is Insert

                    file >> word; //read the next word which specifies what type of animal it is

                    //start checking if the word is mammal, reptile or bird
                    if (word == "mammal") {

                        file >> word;
                        speciesName = word; //storing the word inside species variable
                        file >> word; // reads next word
                        length = stod(word);//stores the length
                        file >> word; //reads next word
                        litterSize = stod(word);// stores the average litter size

                        Mammal *mammal = new Mammal(speciesName, length, litterSize);
                        bst.startInsert(mammal);

                    } else if (word == "reptile") {

                        file >> word;
                        speciesName = word; //storing the word inside species variable
                        file >> word; // reads next word
                        length = stod(word);//stores the length
                        file >> word; //reads next word
                        venom = word;// stores the average litter size

                        Reptile *reptile = new Reptile(speciesName, length, venom);
                        bst.startInsert(reptile);

                    } else if (word == "bird") {
                        file >> word;
                        speciesName = word; //storing the word inside species variable
                        file >> word; // reads next word
                        length = stod(word);//stores the length
                        file >> word; //reads next word
                        fly = word;// stores the average litter size

                        Bird *bird = new Bird(speciesName, length, fly);
                        bst.startInsert(bird);
                    }
                } else if (word == "Find") { //if the word read is Find then start the search for the animal

                    file >> word;
                    animalSearch = word;
                    bst.startSearch(animalSearch);

                } else if (word == "Remove") {//if the word is Remove start the deletion
                    file >> word;
                    bst.startDeletion(word);

                }
            }

            cout << "Binary Search tree printed with InOrder Traversal:" << endl;

            bst.Traversals(1);
            file.close();

    } else { //if argc is <1
        throw "No file was passed as an argument!";

    }

    return 0;
}