# Competitive Programming
Contains Data Structures and Algorithms for Competitive Programming

### Compiling ```C++``` Code

```bash
g++ -no-pie -fno-pie -fsanitize=address -fno-omit-frame-pointer -fno-common -Wall -Wextra -Wpedantic -g -pthread -D LOCAL -O3 -std=c++20 -o A A.cpp
```

### Using ```gedit``` Snippets

Copy the snippets to ```gedit```'s **snippets** directory. They'll be ready to be used then.  
(Run this command from this project's root directory)

```bash
cp .gedit_snippets/cpp.xml .gedit_snippets/global.xml ~/.config/gedit/snippets/
```

**Note:** If you have already made your own ```gedit``` snippets, and still want to have (some, or all of) these snippets, then you'll have to merge these snippets to your respective snippet files. You can just manually copy those snippets which you want (from a ```<snippet>``` to ```</snippet>```) to your respective snippet files (before the ```</snippets>```). Do not run the above command in such a case.
