#include "bubble_sort.hpp"

void BubbleSort::sort(Container* container)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < container->size() - 1; ++i)
        {
            if (container->at(i)->evaluate() > container->at(i + 1)->evaluate())
            {
                container->swap(i, i + 1);
                swapped = true;
            }
        }
    }
}