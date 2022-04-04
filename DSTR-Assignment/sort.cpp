#include <iostream>
#include "data_type.h"

int CompareNumeric(int a, int b) {
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int CompareFloat(float a, float b) {
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int CompareString(std::string s1, std::string s2) {
    size_t shortest = std::min<size_t>(s1.length(), s2.length());
    for (size_t i = 0; i < shortest; i++) {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }
    return s1.length() - s2.length();
}
