#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

struct hourly_data {
    string time;
    int power;
    int no_of_miners;
};

struct calculation_data
{
    int n;
    hourly_data array_of_hours[9000];
};

void tokenize(string s, string del, string ret[6])
{
    int start, end = -1 * del.size();
    int i = 0;
    do {
        start = end + del.size();
        end = s.find(del, start);
        ret[i++] = s.substr(start, end - start);
    } while (end != -1);
}

hourly_data new_data(string separated_data[6]) {
    hourly_data hd;

    hd.time = separated_data[0];
    hd.power = floor(stod(separated_data[1]));

    return hd;
}

int readFile(string file_path, hourly_data* data) {
    //iterator
    int i = 0;

    // Open the text file named "input.txt"
    ifstream f(file_path);

    // Check if the file is successfully opened
    if (!f.is_open()) {
        cerr << "Error opening the file!";
    }

    // String variable to store the read data
    string s;

    //array for separated elements of each line
    string ret[6];

    // Read each line of the file and print it to the
    // standard output stream till the whole file is
    // completely read
    while (getline(f, s)) {
        tokenize(s, ",", ret);
        data[i] = new_data(ret);
        i++;
    }


    // Close the file
    f.close();

    return i;
}

void number_of_miners_each_hour(hourly_data* array_of_hours, int n, int miner_power) {
    for (int i = 0; i < n; i++) {
        array_of_hours[i].no_of_miners = array_of_hours[i].power / miner_power;
    }
}


int main()
{

    string input_file_path = "hourly_data.txt";
    hourly_data* array_of_hours = new hourly_data[9000];
    int n = readFile(input_file_path, array_of_hours);

    cout << "br clanova: " << n << endl;

    number_of_miners_each_hour(array_of_hours, n, 3);


    for (int i = 0; i < n; i++) {
        cout << array_of_hours[i].time << ", " << array_of_hours[i].power << ", " << array_of_hours[i].no_of_miners << endl;
    }

    delete[] array_of_hours;

    return 0;
}
