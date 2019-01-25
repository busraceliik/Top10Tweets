#pragma once
template<typename K, typename V>

class HashKeyValue
{
public:

	V value;
	K key;

	HashKeyValue(K key, V value)
	{
		this->value = value;
		this->key = key;
	}
};
