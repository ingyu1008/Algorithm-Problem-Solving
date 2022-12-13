#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
/*
    "1 0 0 1 0": "a",
    "1 1 0 2 0": "b",
    "2 0 0 1 1": "c",
    "2 1 0 1 2": "d",
    "1 1 0 1 1": "e",
    "2 1 0 2 1": "f",
    "2 2 0 2 2": "g",
    "1 2 0 2 1": "h",
    "1 2 0 1 2": "j",
    "1 0 1 2 0": "k",
    "1 1 1 3 0": "l",
    "2 0 1 2 1": "m",
    "2 1 1 2 2": "n",
    "1 1 1 2 1": "o",
    "2 1 1 3 1": "p",
    "2 2 1 3 2": "q",
    "1 2 1 3 1": "r",
    "1 2 1 2 2": "t",
    "1 0 2 2 1": "u",
    "1 1 2 3 1": "v",
    "1 2 1 1 3": "w",
    "2 0 2 2 2": "x",
    "2 1 2 2 3": "y",
    "1 1 2 2 2": "z"
    */
int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::map<std::string, char> mp;

    mp.insert({"1 0 0 1 0", 'a'});
    mp.insert({"1 1 0 2 0", 'b'});
    mp.insert({"2 0 0 1 1", 'c'});
    mp.insert({"2 1 0 1 2", 'd'});
    mp.insert({"1 1 0 1 1", 'e'});
    mp.insert({"2 1 0 2 1", 'f'});
    mp.insert({"2 2 0 2 2", 'g'});
    mp.insert({"1 2 0 2 1", 'h'});
    mp.insert({"1 2 0 1 2", 'j'});
    mp.insert({"1 0 1 2 0", 'k'});
    mp.insert({"1 1 1 3 0", 'l'});
    mp.insert({"2 0 1 2 1", 'm'});
    mp.insert({"2 1 1 2 2", 'n'});
    mp.insert({"1 1 1 2 1", 'o'});
    mp.insert({"2 1 1 3 1", 'p'});
    mp.insert({"2 2 1 3 2", 'q'});
    mp.insert({"1 2 1 3 1", 'r'});
    mp.insert({"1 2 1 2 2", 't'});
    mp.insert({"1 0 2 2 1", 'u'});
    mp.insert({"1 1 2 3 1", 'v'});
    mp.insert({"1 2 1 1 3", 'w'});
    mp.insert({"2 0 2 2 2", 'x'});
    mp.insert({"2 1 2 2 3", 'y'});
    mp.insert({"1 1 2 2 2", 'z'});

    std::string s;
    std::getline(std::cin,s);

    while(std::getline(std::cin, s)){
        std::cout << mp[s];
    }

    return 0;
}