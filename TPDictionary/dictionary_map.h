#ifndef DICTIONARY_MAP
#define DICTIONARY_MAP

#include <iostream>
#include <algorithm>
#include <unordered_map>

class DictionaryMap {
public:
	using key_type = std::string;
	using mapped_type = size_t;
	using value_type = std::pair<key_type, mapped_type>;

	DictionaryMap(size_t count = 1);
	DictionaryMap(const DictionaryMap& copy) = default;
	DictionaryMap(DictionaryMap&& move) = default;
	DictionaryMap& operator=(const DictionaryMap& copy) = default;
	DictionaryMap& operator=(DictionaryMap&& move) noexcept = default;
	~DictionaryMap() = default;

	auto begin();
	auto end();

	void insert(const key_type& key);
	bool erase(const key_type& key);
	std::size_t find(const key_type& key);

	size_t size() noexcept;
	bool empty() noexcept;
	void clear();

	void popularWords(std::ostream& out);
	void print(std::ostream& out);

private:
	std::unordered_map<key_type, size_t> table;
};


#endif
