#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

struct hourly_data {
    string time;
    double power;
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



void readFile(string file_path, string data[9000]) {
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

    // Read each line of the file and print it to the
    // standard output stream till the whole file is
    // completely read
    while (getline(f, s)) {
        data[i] = s;
        i++;
    }


    // Close the file
    f.close();
}

int main()
{
    string data[9000];
    string input_file_path = "C:\\Users\\daki\\Desktop\\hourly_data.txt";
    readFile(input_file_path, data);

    /*for (int i = 0; i < 9000; i++) {
        cout << data[i] << endl;
    }*/
    string ret[6];
    tokenize("20050101:0010,0.0,0.0,0.3,1.03,0.0", ",", ret);

    for (int i = 0; i < 6; i++) {
        cout << ret[i] << endl;
    }
    return 0;
}
