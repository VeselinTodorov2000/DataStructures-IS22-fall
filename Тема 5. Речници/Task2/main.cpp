#include <iostream>
#include <unordered_map>

template<typename T>
class Counter
{
private:
    std::unordered_map<T,int> map;
public:


    T& operator +=(const T& key)
    {
        if(map.count(key) == 0) // key doesn't exist
        {
            map[key] = 1;
        } else
        {
            map[key] += 1;
        }
        return map[key];
    }

    T& operator -=(const T& key)
    {
        if(map.count(key) == 0)
        {
            throw "Key doesn't exist";
        }else
        {
            map[key] -= 1;
        }
        return map[key];
    }

    int operator-(const T& key)
    {
        if(map.count(key) == 0)
        {
            return -1;
        } else {
            return map[key] - 1;
        }
    }

    int operator+(const T& key)
    {
        if(map.count(key) == 0) {
            return 1;
        } else
        {
            return map[key] + 1;
        }
    }

    T& operator[](const T& key)
    {
        if(map.count(key) == 0) {
            throw "No such key";
        }
        return map[key];
    }

    int count()
    {
        int result = 0;
        for (auto i : map) {
            if(i.second > 0) result ++;
        }
        return result;
    }


};



int main() {
    //std::cout << "Hello, World!" << std::endl;

    Counter<int> c;
    c+= 1;
    c+= 1;
    std::cout<<c[1];
     //c -= 3;
     c -= 1;
     std::cout<<c[1];
    return 0;
}
