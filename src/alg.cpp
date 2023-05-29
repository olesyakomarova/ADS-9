// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Mytree;
    std::ifstream file(filename);
    std::string p;
    std::string p1 = "";
    std::string p2 = "";
    while (!file.eof()) {
        file >> p;
        p1 = p2 = "";
        if (p.find(",") != -1) {
                int l = p.length();
                int f = p.find(",");
                if ((f != l - 1) && ((p[f + 1] >= 'A' && p[f + 1] <= 'Z') ||
                    (p[f + 1] >= 'A' && p[f + 1] <= 'z'))) {
                for (int i = 0; i < f; i++) {
                    p1 += p[i];
                }
                for (int i = f+1; i < l; i++) {
                    p2 += p[i];
                }
            }
        }
        if (p1 != "" && p2 != "") {
            p1 = get_corr_word(p1);
            p2 = get_corr_word(p2);
            Mytree.add(p1);
            Mytree.add(p2);
        } else {
            p = get_corr_word(p);
            Mytree.add(p);
        }
    }
    return Mytree;
}
std::string get_corr_word(std::string s) {
    if (s[0] < '0' || s[0] > '9') {
        while ((s[0] >= 32 && s[0] <= 64) || (s[0] >= 91 && s[0] <= 96))
        s.erase(0, 1);
        if (s != "") {
            char c = s[s.length() - 1];
            while ((c >= 32 && c <= 64) || (c >= 91 && c <= 96)) {
                s.pop_back();
                c = s[s.length() - 1];
            }
        }
        int it = 0;
        if (s != "") {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '\'') {
                    it = i;
                }
            }
            if (it != 0)
                s.erase(it);
        }
        if (s != "") {
            for (int i = 0; i < s.length(); i++) {
                s[i] = tolower(s[i]);
            }
        }
        } else {
        s.clear();
    }
    return s;
}
