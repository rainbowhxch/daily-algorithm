#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;

class Bucket {
	public:
		void insert(int key) {
			if (!exists(key))
				_data.insert(_data.begin(), key);
		}

		void remove(int key) {
			if (exists(key))
				_data.remove(key);
		}

		bool exists(int key) {
			if (std::find(_data.begin(), _data.end(), key) != _data.end()) {
				return true;
			};

			return false;
		}
	private:
		list<int> _data;
};

class MyHashSet {
	public:
		MyHashSet() {
			_key_range = 997;
			for (int i = 0;i < _key_range;++i) {
				Bucket *tmp = new Bucket();
				_data.emplace_back(tmp);
			}
		}

		void add(int key) {
			_data[_hash(key)]->insert(key);
		}

		void remove(int key) {
			_data[_hash(key)]->remove(key);
		}

		bool contains(int key) {
			return _data[_hash(key)]->exists(key);
		}
	private:
		vector<Bucket *> _data;
		int _key_range;

		int _hash(int key) {
			return key % _key_range;
		}
};
