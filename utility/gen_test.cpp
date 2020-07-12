/**
 *     Author: ankushkhanna (Ankush Khanna)
 *    Created: Tuesday, 08 December 2019, 06:33:17 AM IST
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    char buf[64];
    random_device rng;
    while (true) {

        ofstream fout("in.txt", ios_base::out);
        /* Generate a test case here... */
        fout.close();

        string a, b;

        FILE *fp = popen("(./A < in.txt) 2> /tmp/stderr.txt", "r"); // Your Code
        if (fp == nullptr) {
            cerr << "File Problem at line " << __LINE__ << endl;
            exit(0);
        }
        while (fgets(buf, sizeof(buf), fp) != nullptr) {
            a += buf;
        }
        pclose(fp);

        fp = popen("(./B < in.txt) 2> /tmp/stderr.txt", "r"); // Correct Code
        if (fp == nullptr) {
            cerr << "File Problem at line " << __LINE__ << endl;
            exit(0);
        }
        while (fgets(buf, sizeof(buf), fp) != nullptr) {
            b += buf;
        }
        pclose(fp);

        remove("/tmp/stderr.txt");

        if (a != b) {
            cout << "\n  Me: " << a;
            cout << "Them: " << b << "\nCounter Case:\n\n";
            if (system("cat in.txt")) {
                cerr << "Unexpected Error at line " << __LINE__ << endl;
                exit(0);
            }
            cout << '\n';
            break;
        }

    }
    return 0;
}
