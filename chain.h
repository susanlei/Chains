// Include your name here.
// Shu Xin (Susan) Lei
// Place comments describing the class Chain (two lines).
//
//

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <sstream> 
using namespace std;

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain() {
    size_ = 0;
    array_ = new Object[size_];
  };

  // Copy-constructor.
  Chain(const Chain &rhs) {
    size_ = rhs.size_; 
    array_ = new Object[size_];
    for (int i = 0; i < size_ ; i++) { //store each element from rhs into new array
      array_[i] = rhs.array_[i];
    }
  };

  // Copy-assignment. 
  Chain& operator=(const Chain &rhs) {
    if (this != &rhs) { //ensure Chain object is not copying itself
      Chain copy = rhs; 
      std::swap(*this, copy); 
    }
    return *this;
  };

  // Move-constructor. 
  Chain(Chain &&rhs) {
    //copy data from rhs into new array & clear old array
    size_ = rhs.size_;
    array_ = new Object[size_]; 
    for (int i = 0; i < size_; i++) { //store each element into the new array
        array_[i] = rhs.array_[i];
    }

    //clear data from rhs 
    rhs.size_ = 0;
    rhs.array_ = nullptr;
  };

  // Move-assignment.
  // Just use std::swap() for all variables.
  Chain& operator=(Chain &&rhs) {
    //swap the two Chain objects
    std::swap(size_, rhs.size_);
    std::swap(array_, rhs.array_);
    //clear data from rhs 
    rhs.size_ = 0;
    rhs.array_ = nullptr;
    return *this;
  };

  ~Chain() { // Provide destructor.
    delete [] array_;
  }

  // End of big-five.

  // One parameter constructor.
  Chain(const Object& item) {
    size_ = 1;
    array_ = new Object[size_]; //initalize array with size of 1
    array_[0] = item;
  }

  // Read a chain from standard input.
  void ReadChain() {
    string line;
    getline (cin, line); //store entire user input into line

    if (line[0]=='[' && line[1]==']') { //if user entires empty chain, abort
      abort();
    }

    string trimmedLine; // store the trimmed user input
    for (int i = 1; i < line.length()-1; i++) { //removes brackets from the chain
      trimmedLine = trimmedLine + line[i];
    }

    stringstream ss(trimmedLine);

    string sizeOfChainStr; //holds the string of the chain size
    string tempStr; //holds the untrimmed string of the chain size [has ":" in the end]

    ss >> tempStr; //store the string of chain size + ":"

    for (int i = 0; i < tempStr.length()-1; i++) { //removes the ":" from the string holding the chain size
      sizeOfChainStr = sizeOfChainStr + tempStr[i];
    }

    size_ = stoi(sizeOfChainStr); //convert string to int

    Object *newArray = new Object[size_]; //initalize new array of size inputed by user

    Object eachElement;
    for (int i = 0; i < size_; i++) {
      ss >> eachElement; //take in each element from stringstream
      newArray[i] = eachElement; //store each element taken from stringstream into new array
    }
    array_ = newArray; //set new array into original Chain object
  }

  size_t size() const { //return size of chain object 
    return size_;
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const { 
    if (location > size_ - 1) {
      abort();
    }
    return array_[location];
  }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location) { 
    if (location > size_ - 1) {
      abort();
    }
    return array_[location];
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2) {
  int sizeOfBothChains = c1.size() + c2.size(); //set chain of this size to sum of both size
  Object *newArray = new Object[sizeOfBothChains]; //initialize array of Objects
  Chain<Object> newChain; //Chain of Objects that would be returned

  for (int i = 0; i < c1.size(); i++) { //store chain 1's elements into new chain
    newArray[i] = c1.array_[i];
  }
  int counter = 0; //counter for index of chain 2
  for (int i = c1.size(); i < sizeOfBothChains; i++) { //starts at where chain 1 left off
    //store chain 2's elements into new array
    newArray[i] = c2.array_[counter];
    counter++; //increment index for chain 2 by 1
  }

  //set the new chain's array and size
  newChain.array_ = newArray;
  newChain.size_ = sizeOfBothChains;

  return newChain;
 }

//  @c1: A chain.
//  @newStr: A string
//  @return the concatenation of the chain and Object.
friend Chain operator+(const Chain &c1, const Object &newObj) {
  Object *newArray = new Object[c1.size()+1]; //initialize array of Objects by new size
  Chain<Object> newChain; //Chain of Objects that would be returned

  for (int i = 0; i < c1.size(); i++) { //store chain 1 elements into new chain
    newArray[i] = c1.array_[i];
  }
  newArray[c1.size()] = newObj; //store the string into the last index of new array

  //set the new chain's array and size
  newChain.array_ = newArray; 
  newChain.size_ = c1.size()+1;

  return newChain;
}

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
  if (a_chain.size() == 0) { //if size of chain is 0
    cout << "[]" << endl;
  }
  else if (a_chain.array_ == nullptr){ //if array is empty
    cout << "[]" << endl;
  }
  else {
   cout << "[";
   for (int i = 0; i < a_chain.size()-1; i++) { //prints out each element int the array
     cout << a_chain.array_[i] << " ";
   }
   //prints out the last element with the bracket
   cout << a_chain.array_[a_chain.size()-1] << "]" << endl; 
  }
  
   return out;
 }
 
 private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
