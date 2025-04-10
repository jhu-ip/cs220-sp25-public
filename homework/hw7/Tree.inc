template<typename T>
std::string Tree<T>::toString() {

    // traverse root
    std::ostringstream os;
    os << data << '\n';
    std::string result(os.str());

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
