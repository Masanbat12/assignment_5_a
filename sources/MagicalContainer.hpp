#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <string>
#include <algorithm>
#pragma once

#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;
        std::vector<int>::const_iterator current;
        bool isPrime(int num);

    public:
        MagicalContainer() = default;
        ~MagicalContainer() = default;
        void addElement(int elem);
        int size() const;
        void removeElement(int elem);
        const std::vector<int> &getElements() const;

    public:
        class AscendingIterator
        {
        private:
            std::vector<int> &elements;
            std::vector<int>::const_iterator current;

        public:
            //  AscendingIterator() : elements({}), current(elements.begin()) {}

            AscendingIterator(ariel::MagicalContainer &container)
                : elements(container.elements), current(elements.begin()) {}

            std::vector<int>::const_iterator begin()
            {
                return current;
            }

            std::vector<int>::const_iterator end()
            {
                return elements.end();
            }

            AscendingIterator &operator++()
            {
                ++current;
                return *this;
            }

            int operator*() const
            {
                return *current;
            }

            AscendingIterator ascIter()
            {
                return AscendingIterator(*this);
            }
        };  

        class SideCrossIterator
        {
        private:
            std::vector<int> &elements;
            std::vector<int>::iterator current;

        public:
            SideCrossIterator(ariel::MagicalContainer &container)
                : elements(container.elements), current(elements.begin()) {}

            std::vector<int>::iterator begin()
            {
                return elements.begin();
            }

            std::vector<int>::iterator end()
            {
                return elements.end();
            }

            SideCrossIterator &operator++()
            {
                if (current != elements.end())
                {
                    std::advance(current, 2);
                }
                return *this;
            }

            int operator*()
            {
                return *current;
            }
        };

        class PrimeIterator
        {
        private:
            std::vector<int> &elements;
            std::vector<int>::iterator current;

            bool isPrime(int num)
            {
                if (num < 2)
                {
                    return false;
                }
                for (int i = 2; i * i <= num; ++i)
                {
                    if (num % i == 0)
                    {
                        return false;
                    }
                }
                return true;
            }

        public:
            PrimeIterator(ariel::MagicalContainer &container)
                : elements(container.elements), current(elements.begin()) {}

            std::vector<int>::iterator begin()
            {
                while (current != elements.end() && !isPrime(*current))
                {
                    ++current;
                }
                return current;
            }

            std::vector<int>::iterator end()
            {
                return elements.end();
            }

            PrimeIterator &operator++()
            {
                do
                {
                    ++current;
                } while (current != elements.end() && !isPrime(*current));
                return *this;
            }

            int operator*()
            {
                return *current;
            }
        };
    };

}

#endif // MAGICALCONTAINER_HPP