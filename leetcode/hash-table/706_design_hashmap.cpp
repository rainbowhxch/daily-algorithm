#include <vector>

using std::vector;

class MyHashMap {
public:
    enum Status {
        Empty, Deleted, Filled
    };

    struct Bucket {
        Status status = Status::Empty;
        int key;
        int value;
    };

    MyHashMap() {
        vec.resize(17); // Arbitrary small prime number
        num = 0;
    }

    /** value will always be non-negative. */
    void put(int key_in, int value_in) {
        grow_and_rehash();

        int hash = key_in % vec.size();
        int index = hash;
        int desired = hash;
        int times = 0;
        bool found = false;

        while (vec[index].status != Status::Empty && times < vec.size()) {
            if (vec[index].status == Status::Filled && vec[index].key == key_in) {
                vec[index].value = value_in;
                return;
            }
            else if (!found && vec[index].status == Status::Deleted) {
                found = true;
                desired = index;
            }

            index = (index + 1) % vec.size();
            ++times;
        }

        if (found) {
            index = desired;
        }

        vec[index].status = Status::Filled;
        vec[index].key = key_in;
        vec[index].value = value_in;
        ++num;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key_in) {
        int hash = key_in % vec.size();
        int times = 0;

        while (vec[hash].status != Status::Empty && times < vec.size()) {
            if (vec[hash].status == Status::Filled && vec[hash].key == key_in) {
                return vec[hash].value;
            }

            hash = (hash + 1) % vec.size();
            ++times;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key_in) {
        int hash = key_in % vec.size();
        int times = 0;

        while (vec[hash].status != Status::Empty && times < vec.size()) {
            if (vec[hash].status == Status::Filled && vec[hash].key == key_in) {
                vec[hash].status = Status::Deleted;
                --num;
                return;
            }

            hash = (hash + 1) % vec.size();
            ++times;
        }
    }

private:
    vector<Bucket> vec;
    int num;

    void grow_and_rehash() {
        if (num * 2 >= vec.size()) {
            vector<Bucket> vec1;
            vec1.resize(vec.size() * 2);
            vec.swap(vec1);

            for (int i = 0, num1 = 0; i < vec1.size() && num1 < num; ++i) {
                if (vec1[i].status == Status::Filled) {
                    put(vec1[i].key, vec1[i].value);
                    ++num1;
                }
            }
        }
    }
};
