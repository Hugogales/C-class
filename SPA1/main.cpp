// SPA 1, Spring 2024, Hugo Garrido-Lestache
#include <iostream>
#include <string>

/*
 * HUGO
 *
 * WHAT DID I LEARN:
 *  I learnt and got acustomed to the sintax of C++
 *  I got better using esubmit
 *  nothing else other than that
 *
 * WHAT DID YOU FIND CHALLENGING:
 *  I found dealing with gather input from esubmit hard as I did not understand how it worked
 *  other than that most hurdels where quickly fixed by simple google searches
 *
 * WHAT WOULD I RECOMMEND CHANGING:
 *  Not much, it gets us accustomed to C++ syntax and reminds us of simple coding concepts
 *  Good light starting point.
 *
 */


int main() {
    //values
    std::string time;
    std::string item;
    int volume;

    //tracking variable
    int differential = 0;


    if(!std::cin.eof()) {//ensures there is input

        std::cin >> time;
        std::cin >> item;
        std::cin >> volume;

        while (!std::cin.eof()) {//while there is input

            if (item == "bloodloss" || item == "diarrhea" || item == "urine") {
                //losing fluid
                differential = differential - volume;
            } else {
                //gaining fluid
                differential = differential + volume;

                if (differential >= 1000) {
                    std::cout << "after consuming " << item << " at " << time
                              << ", intake exceeds output by " << differential << " ml" << std::endl;
                }
            }

            std::cin >> time;
            std::cin >> item;
            std::cin >> volume;
        }
    }

    //final output
    std::cout << "the final fluid differential is " << differential << " ml" << std::endl;

    return 0;
}
