// SPA 2, Spring 2024, Hugo Garrido-Lestache
#include <iostream>
#include <cassert>

using namespace std;
const int MAX_DICTIONARY_SIZE = 3000;
const int MAX_GUESSES = 3000;

/**
 * checks if letter is in word
 * @param word
 * @param letter
 * @return true if letter is in word
 */
bool is_letter_in_word(string word, char letter){
    for (int i = 0; i < 5; i++ ){
        if (word.at(i) == letter) return true;
    }
    return false;
}

/**
 * checks if possible guess is a guess which fits the know information of guess.
 * This allows us to check if this guess is a good guess
 * @param possible_guess string to check
 * @param guess which has been done and information is know off
 * @param letter_matches data on word
 * @return true if it is a possible guess knowing the result of the previous guess
 */
bool can_match(string possible_guess, string guess, string letter_matches){
    for(int i =0 ; i < 5; i++){
        if(letter_matches.at(i) == '.'){
            if (guess.at(i) != possible_guess.at(i)) return false;
        }
        if(letter_matches.at(i) == '?'){
            if (guess.at(i) == possible_guess.at(i)) return false;
        }
        if(letter_matches.at(i) == '\?'){
            if (!is_letter_in_word(possible_guess, guess.at(i))) return false;
        }
        if(letter_matches.at(i) == '-'){
            if (is_letter_in_word(possible_guess, guess.at(i))) return false;
        }
    }
    return true;
}

/**
 * reduces the size of dictionary to only the words which could be a valid guess
 * @param dictionary of potencial words to be guessed
 * @param dict_size of dictioanry
 * @param guess to check with words of dictionary
 * @param refrence to check wirht words of dictionary
 * @return
 */
int reduce_potential_guesses(string dictionary[],int dict_size, string guess, string refrence){
    int index_read = 0;
    int index_write = 0;

    while (index_read < dict_size){
        if(can_match(dictionary[index_read], guess, refrence)){
            dictionary[index_write] = dictionary[index_read];
            index_write++;
        }
        index_read++;
    }
    return index_write;
}

/**
 * ouputs resulting possible guesses
 * final thing to be called
 * @param guess array of all guesses word
 * @param guess_size size of said array
 * @param dict array of all possible guesses
 * @param dict_size size of said array
 */
void output_result(string guess[], int guess_size, string dict[], int dict_size){
    //outputing first line
    string first_line = "Possible guesses after " + guess[0];
    for (int i = 1; i < guess_size; i++){
        first_line = first_line + ", " + guess[i];
    }
    cout << first_line << ": " << dict_size << endl;

    //ouputing valid guesses
    for (int i = 0; i < dict_size; i++){
        cout << dict[i] << endl;
    }
}

/**
 * reads user input and stores it in array
 * additionally counts all the words in the array
 * @param dictionary, empty array of string
 * @return size of filled array (not capacity)
 */
int fill_dictionary(string dictionary[MAX_DICTIONARY_SIZE]){
    int index = 0;
    cin >> dictionary[index];
    while(dictionary[index] != "END" && index < MAX_DICTIONARY_SIZE - 1){
        index++;
        cin >> dictionary[index];
    }
    return index; //do not to add 1 as END would be included
}

/**
 * fills guess and refrences arrays with corresponding words and letter matches
 * does not handle edge case of incorrectly foramtted input
 * @param guess, string array
 * @param refrence, string array
 * @return size of both arrays
 */
int fill_guesses_array(string guess[], string refrence[]){
    if(!cin.eof()) {
        int index = 0;
        cin >> guess[index];
        cin >> refrence[index];

        while (!cin.eof() and index < MAX_GUESSES) {
            index++;
            cin >> guess[index];
            cin >> refrence[index];
        }
        return index;
    }
    return 0;//error
}

/**
 * calculates potencial guesses and stores values into dictionary
 * @param dictionary , array of potencial words
 * @param dict_size of said array
 * @param guess , array of guesses
 * @param refrence , array of results to guesses
 * @param guess_size , size of both of arrays.
 * @return new size of dictionary after it being reduced to only potencial guesses
 */
int calculate_guesses(string dictionary[], int dict_size, string guess[], string refrence[],int guess_size){
    for (int i = 0; i < guess_size; i ++){
        dict_size = reduce_potential_guesses
                (dictionary, dict_size, guess[i], refrence[i]);
    }
    return dict_size;
}

void run_checks(){
    assert( can_match("abcde", "axbxf", ".-\?--"));
    assert(!can_match("abcde", "axbxd", ".-\?--"));
    assert( can_match("abcde", "easty", "\?\?---"));
    assert(!can_match("abcde", "abcdf", "....."));
    assert( can_match("abcde", "uvwxy", "-----"));
}

int main() {
    run_checks();

    string dictionary[MAX_DICTIONARY_SIZE];
    int size = fill_dictionary(dictionary);

    string guess[MAX_GUESSES];
    string refrence[MAX_GUESSES];
    int guess_size = fill_guesses_array(guess, refrence);

    int new_dict_size = calculate_guesses(dictionary, size, guess, refrence, guess_size);
    output_result(guess,guess_size, dictionary, new_dict_size);

    return 0;
}
