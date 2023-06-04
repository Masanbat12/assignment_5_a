#include "MagicalContainer.hpp"

namespace ariel
{
    void MagicalContainer::addElement(int elem)
    {
         elements.push_back(elem);
    }
    const std::vector<int> &MagicalContainer::getElements()const
    {
        // static std::vector<int> emptyVector;
        // return emptyVector;
         return elements;
    }
    int MagicalContainer::size() const
    {
        return elements.size();
        //return 0;
    }
    void MagicalContainer::removeElement(int elem)
    {
    auto it = std::find(elements.begin(), elements.end(), elem);
    if (it == elements.end()) {
        throw std::runtime_error("Element not found in container");
    }

    elements.erase(it);    
    }
}