#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void generate_nums (ofstream& nums);
    // generates a random number (110-240) of random numbers (-100-100)
    // uses ofstream to put the number in randNums.txt
void fill_array (ifstream& in_fs, int[], int&, int&);
    // reads all the numbers in randNums.txt and fills an array with those integers

const int SIZE = 240; // max array size

int main() {
    // declare variables
    ofstream nums_fs("randNums.txt");
    int nums_array [SIZE];
    int pos_count = 0,
        neg_count = 0;

    // check if there was an error while trying to open file
    if (!nums_fs.is_open()) {
        cout << "randNums.txt: error while trying to open file.\n";
        return 1;
    }

    // call generate_nums to generate numbers into randNums.txt
    generate_nums (nums_fs);
    nums_fs.close();    // close file after being done with it

    // declare input FS to read numbers from randNums.txt
    ifstream in_fs("randNums.txt");

    // check for errors
    if (!in_fs.is_open()) {
        cout << "randNums.txt: error while trying to open file.\n";
        return 1;
    }

    // call fill_array to read numbers from file and put it into the array
    fill_array (in_fs, nums_array, pos_count, neg_count);

    // output positive and negative numbers count
    cout << "Positive Numbers Count: " << pos_count << "\n";
    cout << "Negative Numbers Count: " << neg_count << "\n";

    in_fs.close();  // close the file after being done with it

    return 0;
}

void generate_nums (ofstream& nums) {
    // to generate within a given range using rand(),
    // use: rand() % (max - min + 1) + min
    srand(time(0));
    int file_size = (rand() % 131) + 110;
    int counter = 0;

    for (int i = 0; i < file_size; i++) {
        int rand_num = (rand() % 201) - 100;
        nums << rand_num << " ";
        counter++;

        if (counter == 20) {
            nums << "\n";
            counter = 0;
        }
    }

    return;
}

void fill_array (ifstream& in_fs, int nums_array[], int& pos, int& neg) {
    int index = 0;
    int number;

    while (in_fs >> number) {
        nums_array [index] = number;

        if (number >= 0) {
            pos++;
        }
        else {
            neg++;
        }

        index++;
    }

    return;
}
