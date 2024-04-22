#include "dictionary_map.h"

auto DictionaryMap::begin() {
	return table.begin();
}

auto DictionaryMap::end() {
	return table.end();
}

DictionaryMap::DictionaryMap(size_t count) :
	table{}
{
	table.rehash(count);
}

void DictionaryMap::insert(const key_type& key) {
	table[key] += 1;
}

bool DictionaryMap::erase(const key_type& key) {
	return table.erase(key);
}

std::size_t DictionaryMap::find(const key_type& key) {
	auto val = table.find(key);
	if (val == table.end())
		return 0;
	return val->second;
}

size_t DictionaryMap::size() noexcept {
	return table.size();
}

bool DictionaryMap::empty() noexcept {
	return table.empty();
}

void DictionaryMap::clear() {
	table.clear();
}

void DictionaryMap::popularWords(std::ostream& out) {
	std::vector<value_type> vec;
	vec.reserve(table.size());
	std::copy(
		std::begin(table),
		std::end(table),
		std::back_inserter(vec)
	);
	std::sort(vec.begin(), vec.end(), [](value_type& left, value_type& right) {
		return left.second > right.second;
		}
	);
	auto iter = vec.begin();
	for (int i = 0; i < 3 && iter != vec.end(); ++i, ++iter) {
		out << "{" << iter->first << ": " << iter->second << "} ";
	}
	out << '\n';
}

void DictionaryMap::print(std::ostream& out) {
	for (auto const& pair : table) {
		out << "{" << pair.first << ": " << pair.second << "} ";
	}
	out << '\n';
}
