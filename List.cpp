#include "List.h"

#include <iostream>

List::List() : Sequence("list"), _elements({}) {}

void List::push(std::shared_ptr<Type> const& element) {
    this->_elements.emplace_back(element);
}

bool List::isPrintable() const {
    return true;
}

std::string List::toString() const {
    std::string result = "[";
    bool first = true;

    for (auto const& element : this->_elements) {
        if (first) {
            first = false;
        } else {
            result += ", ";
        }

        result += element->toString();
    }

    result += ']';
    return result;
}

std::vector<std::shared_ptr<Type>> const& List::get_ref() const {
    return this->_elements;
}

int List::len() const {
    return this->_elements.size();
}
