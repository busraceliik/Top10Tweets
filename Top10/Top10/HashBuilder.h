#include <string>
#include "HashKeyValue.h"
#include "StopWords.h"
#include "QuickSort.h"

template<typename K, typename V>

#pragma once
class HashBuilder
{
	HashKeyValue<K, V> **csvWords;
	HashKeyValue<K, V> **stopWords;

	int capacity;

	int size;

public:

	HashBuilder()
	{
		capacity = 300000;
		size = 0;

		csvWords = new HashKeyValue<K, V>*[capacity];  
		stopWords = new HashKeyValue<K, V>*[capacity]; 

		for (int i = 0; i < capacity; i++) 
		{
			csvWords[i] = NULL;
			stopWords[i] = NULL;
		}

		StopWords* stopWordsInstance = new StopWords;

		for (int i = 0; i < stopWordsInstance->size; i++)
		{
			if (!stopWordsInstance->stopWords[i].empty())
			{
				unsigned int index = HashCode(stopWordsInstance->stopWords[i]);      
																					
				stopWords[index] = new HashKeyValue<K, V>(stopWordsInstance->stopWords[i], 1);
			}
		}
	}

	unsigned int HashCode(string const& key)
	{
		unsigned int hashValue = 0;

		for (int x = 0; x < key.length(); ++x)
		{
			hashValue ^= (hashValue << 5) +
				(hashValue >> 2) + key[x];
		}

		return hashValue % capacity;
	}

	void InsertNode(K key, V value)
	{
		unsigned int index = HashCode(key);

		if (csvWords[index] != NULL) 
		{
			csvWords[index]->value++;
		}
		else 
		{
			if (stopWords[index] == NULL && size < capacity) 
			{ 
				csvWords[index] = new HashKeyValue<K, V>(key, value);
				size++;
			}
		}
	}

	void DisplayWithQuickSort()
	{
		int topWordCount = 11;

		HashKeyValue<K, V> **topTenArray = new HashKeyValue<K, V>*[topWordCount];

		for (int i = 0; i < topWordCount; i++)
		{
			topTenArray[i] = new HashKeyValue<K, V>("", 0);
		}

		QuickSort<string, int>* quickSortInstance = new QuickSort<string, int>;

		for (int i = 0; i < capacity; i++)
		{
			if (csvWords[i] != NULL)
			{
				topTenArray[0] = csvWords[i];
				quickSortInstance->quickSort(topTenArray, 0, topWordCount - 1);
			}
		}

		for (int i = topWordCount - 1; i > 0; i--)
		{
			if (topTenArray[i] != NULL && !topTenArray[i]->key.empty())
			{
				cout << "\n" << " " << topWordCount - i << " Key = [" << topTenArray[i]->key << "]            \t"
					<< "Value = [" << topTenArray[i]->value << "] \t" << endl;
			}
		}
	}

	int SizeofMap()
	{
		return size;
	}

	bool IsEmpty()
	{
		return size == 0;
	}
};

