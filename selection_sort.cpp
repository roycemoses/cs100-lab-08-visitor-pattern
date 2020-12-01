#include "selection_sort.hpp"

void SelectionSort::sort(Container* container)
{
    int minIndex = 0;
    for (int i = 0; i < container->size() - 1; ++i)
    {
        minIndex = i;
        for (int j = i + 1; j < container->size(); ++j)
        {
            if (container->at(j)->evaluate() < container->at(minIndex)->evaluate())
            {
                minIndex = j;
            }
        }
        container->swap(minIndex, i);
    }
}