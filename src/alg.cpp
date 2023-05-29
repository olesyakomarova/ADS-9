// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string> bst;
  std::ifstream file(filename);
  std::string word = "";
  if (!file.is_open()) {
    throw std::string("Error! Can not open file!");
  }
  while (!file.eof()) {
    word = "";
    while (true) {
      char dop = file.get();
      if ((dop >= 65 && dop <= 90) || (dop >= 97 && dop <= 122)) {
        word += tolower(dop);
      } else {
        break;
      }
    }
    bst.Add(word);
  }
  return bst;
}
