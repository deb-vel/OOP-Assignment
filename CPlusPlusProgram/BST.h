#ifndef CPLUSPLUSPROGRAM_BST_H
#define CPLUSPLUSPROGRAM_BST_H


//includes
#include "Animal.h"
#include <iostream>

//class for Nodes
template <class T>
class BstNode {
public:
    T* animal;    //will store objects
    //will store the address to the node on the right and left
    BstNode<T>* left;
    BstNode<T>* right;
};

template <class T>
class BST{
private:
    BstNode<T> * root = NULL; //set root equal to NULL
public:

    BST();
    ~BST();
    void Traversals(int); //called from main to run BST traversal
    void startInsert(T*); //called from main to start the insertion of object process
    void startSearch(string);// called from main to start finding the sepcies read from file
    void startDeletion(string);
    BstNode<T>* CreateNode(T*); //creates a new node whenever needed
    BstNode<T>* Insert(BstNode<T>*, T*); //carries out the process to insert data in a node
    BstNode<T>* Find(BstNode<T>*, string);//performs the searching
    BstNode<T>* RemoveNode(BstNode<T>*, string); //deletes data and its respective node from the bst
    BstNode<T>* GetMinimum(BstNode<T>*);//gets smallest data inside the bst

    //The below perform the tree traversals
    void OutputInOrder(BstNode<T>*);
    void OutputPostOrder(BstNode<T>*);
    void OutputPreOrder(BstNode<T>*);
    //called to output the details found in each root while traversing the tree
    void outputDetails(BstNode<T>*);
};

#endif //CPLUSPLUSPROGRAM_BST_H


template <class T>
BST<T>::BST(){

}

template <class T>
BST<T>::~BST(){}

template <class T>
void BST<T>::startInsert(T* animal){ //called from main whenever an object is to be added to the tree
    //this method is called first instead of the Insert() so that information of the root stays inside BST.h file
    root = Insert(root, animal); //update root with new root
}

template <class T>
//Inserts objects in the tree. Uses Recursion to do so
BstNode<T>* BST<T>::Insert(BstNode<T>* root,T *animal) {

    if(root == nullptr) { //no node exists at the address to which the root points to
        root = CreateNode(animal); //therefore, create a new node and pass the data to store in it
    }
        // if the name of the animal to be inserted is less than the data inside the current root
    else if(animal->getName() <= root->animal->getName()) {
        root->left = Insert(root->left,animal); //recursive call to Insert and update the left child of the root
    }
        // else, recursive call to insert in right subtree.
    else {
        root->right = Insert(root->right,animal);
    }
    return root;
}

template <class T>
BstNode<T>* BST<T>::CreateNode(T *animal) { //called when data needs to be added in a new node
    BstNode<T>* newNode = new BstNode<T>(); //points to the Node created
    newNode->animal = animal; //set the animal in node to the object passed
    newNode->left = newNode->right = nullptr; //children pointing to NULL
    return newNode;
}

template <class T>
void BST<T>:: startSearch(string species){ //called from main to start the search
    BstNode<T>* nodeFound = Find(root, species); //gets the address where the species is, if found
    if(nodeFound!=nullptr) { //if it is not null then it means it was found
        cout<<species<<" was found"<<endl;
        cout<<"Length: "<<nodeFound->animal->getLength(); //get length and species type
        cout<<"\tSpecies: "<<nodeFound->animal->getSpecies();

        if(nodeFound->animal->getSpecies() == "Mammal"){
            cout<<"\tLitter Size: "<<nodeFound->animal->getLitterSize()<<"\n"<<endl;
        }else if(nodeFound->animal->getSpecies() == "Reptile"){
            cout<<"\tVenomous: "<<nodeFound->animal->getVenomous()<<"\n"<<endl;
        }else{
            cout<<"\tFly: "<<nodeFound->animal->getFly()<<"\n"<<endl;
        }
    }
    else cout<<species<<" could Not be Found!\n"<<endl; //output error message
}

template <class T>
BstNode<T>* BST<T>::Find(BstNode<T>* root,string animal) { //searches for the species
    if(root == nullptr) { //no tree
        return nullptr;
    }
    else if(root->animal->getName() == animal) { //if found
        return root; //returns address of the node which contains the searched animal
    }
    else if(animal <= root->animal->getName()) { //traversing the tree
        return Find(root->left,animal); //search in the left subtree of the current root
    }
    else {
        return Find(root->right,animal);//search in the right subtree of the current root
    }
}

template <class T>
void BST<T>:: startDeletion(string species) { //called from main to start the search
    RemoveNode(root, species);
}

template <class T>
BstNode<T>* BST<T>::RemoveNode(BstNode<T>* root, string species){
    if(root == nullptr) //animal not found in tree
    {   cout<<species<<" could not be deleted! Make sure it is written correctly in .txt file\n"<<endl;
        return root;
    }
    else if (species > root->animal->getName()) { //if animal passed is greater than that found in root
        root->right = RemoveNode(root->right,species); //search in right child recursively
    }
    else if(species < root->animal->getName()){//if animal passed is less than animal in root
        root->left = RemoveNode(root->left,species); //search in left child recursively
    }
    //when animal is found execute following code
    else{

        if (root->left == nullptr && root->right == nullptr) { //if the node has no children (leaf node)
            delete root; //deallocate memory of root from heap
            root = nullptr; //set the root to now point to NULL
        }
        else if (root->left == nullptr) { //if the node has one child in this case right child
            BstNode<T>* temporaryNode = root;//store address of node that will be deleted in a temporary pointer to root
            root = root->right; //make the right child the root of the subtree
            delete temporaryNode; //deallocate memory of temporaryNode from heap
        }
        else if (root->right == nullptr) { //if the node has one child in this case left child
            BstNode<T>* temporaryNode = root;//store address of node that will be deleted in a temporary pointer to root
            root = root->left; //make the left child the root of the subtree
            delete temporaryNode; //deallocate memory of temporaryNode from heap
        }

        else { //when the node has 2 children
            BstNode<T>* temporaryNode = GetMinimum(root->right); //search for minimum data in the right subtree
            root->animal = temporaryNode->animal; //set the data to be deleted to the minimum value found
            string species = root->animal->getName();
            root->right = RemoveNode(root->right, species);
        }
    }
    return root;
}

template <class  T>
BstNode<T>* BST<T>::GetMinimum(BstNode<T>* root)
{
    while(root->left != NULL){
        root = root->left; //gets the bottom most node on the left side of the root
        //i.e gets the far left leaf node
    }
    return root; //returns leaf node
}



template <class T>
void  BST<T>::Traversals(int num){ //called from main
    if(num==1) {
        OutputInOrder(root); //only calls the method that performs the inOrder traversal as only that should be printed throughout the whole program
    }
    if (num == 2){
        OutputPostOrder(root);
    }
    if(num == 3){
        OutputPreOrder(root);
    }
}

//traverse subtree, then the root of the subtree, then right subtree
template <class T>
void BST<T>::OutputInOrder(BstNode<T>* root){
    if(root != nullptr){
        OutputInOrder(root->left); //recursive call to traverse the left subtree
        outputDetails(root);
        OutputInOrder(root->right);//recursive call to traverse the right subtree
    }
}

//traverse the left subtree followed by all nodes in the right subtree, then the root
template <class T>
void BST<T>::OutputPostOrder(BstNode<T>* root) {
    if(root!= nullptr){
        OutputPostOrder(root->left);//recursive call to traverse the left subtree
        OutputPostOrder(root->right);//recursive call to traverse the right subtree
        outputDetails(root);
    }
}

//traverse the root then left subtree then right subtree
template <class T>
void BST<T>::OutputPreOrder(BstNode<T>* root){
    if(root!= nullptr){
        outputDetails(root);
        OutputPreOrder(root->left);//recursive call to traverse the left subtree
        OutputPreOrder(root->right);//recursive call to traverse the right subtree
    }
}

template <class T>
void BST<T>::outputDetails(BstNode<T>* root){

    cout<<"Name: "<<root->animal->getName()<<"\tLength: "<<root->animal->getLength();
    cout<<"\tSpecies: "<<root->animal->getSpecies();
    if(root->animal->getSpecies() == "Mammal"){
        cout<<"\tLitter Size: "<<root->animal->getLitterSize()<<endl;
    }else if(root->animal->getSpecies() == "Reptile"){
        cout<<"\tVenomous: "<<root->animal->getVenomous()<<endl;
    }else{
        cout<<"\tFly: "<<root->animal->getFly()<<endl;
    }
}

