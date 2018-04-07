#ifndef MAP_GET_H
#define MAP_GET_H

#include <map>

using namespace std;

template<class K, class V>
bool map_get(map<K,V> *src_map, K *key_source, V *dest_var) {
    try {
        *dest_var = src_map->at(*key_source);
        return true;
    } catch(out_of_range oor) {
        return false;
    }
}

template<class K, class V>
bool map_get(map<K,V> *src_map, const K key_source, V *dest_var) {
    try {
        *dest_var = src_map->at(key_source);
        return true;
    } catch(out_of_range oor) {
        return false;
    }
}

#endif //MAP_GET_H