#include "CTree.h"

std::string CTree::toString() {

    // traverse root
    std::string result;
    result.push_back(data);
    result.push_back('\n');

    // traverse children
    if (kids != nullptr) {
        result += kids->toString();
    }

    // traverse siblings
    if (sibs != nullptr) {
        result += sibs->toString();
    }

    return result;

}
