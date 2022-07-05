#include <cstdio>
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

int main()
{
    const auto size = 100;
    vector<int> init;
    vector<int> boxes;

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    for ( int i = 0; i < size; i++ ) {
        init.push_back(i);
    }

    while ( init.size() > 0 ) {
        auto idx = rand() % init.size();
        auto x = init.at(idx);
        boxes.push_back( init.at(idx) );

        init.erase( init.begin() + idx );
    }

    vector<bool> results;

    auto worst = 0;
    for ( int p = 0; p < size; p++ ) {
        auto check = p;
        auto check_count = 0;

        while ( true) {
            auto b = boxes.at(check);
            if ( b == p ) {
                break;
            }

            check = b;
            check_count++;
        }

        printf("Person %d one took %d tries\n", p + 1, check_count);
        if ( worst < check_count ) {
            worst = check_count;
        }
    }

    printf("Worst check was %d\n", worst);
}