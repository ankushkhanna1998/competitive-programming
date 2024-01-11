/**
 *   Author: ankushkhanna (Ankush Khanna)
 *  Created: Tuesday, 01 June 2021, 03:46:54 PM IST
**/
#include <bits/stdc++.h>

using namespace std;

inline void generate_case(ofstream &cout) {
  /* Generate a test case here... */

  cout.flush();
}

atomic<uint64_t> tests_run(0);

void signal_handler(const int signal_code) {
  cerr << endl << "Keyboard Interrupt!" << endl;
  cerr << " Tests Run: " << tests_run << endl;
  exit(signal_code);
}

int main() {
  signal(SIGINT, signal_handler);

  char buf[64];
  mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

  while (true) {
    ofstream fout("in.txt", ios_base::out);
    generate_case(fout);
    fout.close();

    string a, b;

    FILE *fp = popen("(./A < in.txt) 2> /tmp/stderr.txt", "r");  // Your Code
    if (fp == nullptr) {
      cerr << "File Problem at line " << __LINE__ << endl;
      exit(0);
    }
    while (fgets(buf, sizeof(buf), fp) != nullptr) {
      a += buf;
    }
    pclose(fp);

    fp = popen("(./B < in.txt) 2> /tmp/stderr.txt", "r");  // Correct Code
    if (fp == nullptr) {
      cerr << "File Problem at line " << __LINE__ << endl;
      exit(0);
    }
    while (fgets(buf, sizeof(buf), fp) != nullptr) {
      b += buf;
    }
    pclose(fp);

    remove("/tmp/stderr.txt");
    ++tests_run;

    if (a != b) {
      cout << "\n  Me: " << a;
      cout << "Them: " << b << "\nCounter Case:\n\n";
      if (system("cat in.txt") != 0) {
        cerr << "Unexpected Error at line " << __LINE__ << endl;
        exit(0);
      }
      cout << endl;
      break;
    }
  }
  return 0;
}
