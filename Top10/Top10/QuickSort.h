#pragma once
#include "HashKeyValue.h"

template<typename K, typename V>

#pragma once
class QuickSort
{

public:

	QuickSort() {}

	void swap(HashKeyValue<K, V>** a, HashKeyValue<K, V>** b) {

		HashKeyValue<K, V>* temp = *a;
		*a = *b;
		*b = temp;

	}

	int partition(HashKeyValue<K, V>* arrayy[], int low, int high)
	{

		int pivot = arrayy[high]->value; 

		int i = (low - 1);  

		for (int j = low; j <= high - 1; j++)
		{
		 
			if (arrayy[j]->value <= pivot)
			{
				i++; 
				swap(&arrayy[i], &arrayy[j]);
			}
		}

		swap(&arrayy[i + 1], &arrayy[high]);

		return (i + 1);
	}


	void quickSort(HashKeyValue<K, V>* arrayy[], int low, int high)
	{
		if (low < high)
		{
			
			int pi = partition(arrayy, low, high);

			quickSort(arrayy, low, pi - 1);
			quickSort(arrayy, pi + 1, high);
		}
	}
};

