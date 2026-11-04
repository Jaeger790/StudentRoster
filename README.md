# Student Roster

C++ console coursework project for parsing student records, checking email formats and reporting course durations.

## Build and run

With a C++17 compiler:

```sh
g++ -std=c++17 -Wall -Wextra StudentRoster/main.cpp StudentRoster/roster.cpp StudentRoster/student.cpp -o student-roster
./student-roster
```

Or open `C867PA.sln` in Visual Studio. Build output and local Visual Studio state are ignored.

## Layout

- `StudentRoster/`: C++ source, headers and Visual Studio project.
- `ConsoleRun.jpg`: original console screenshot.
- `tests/`: focused roster ownership regression test.

## Scope

Uses a fixed roster of five records. Email validation follows the original exercise rules: an address needs `@` and `.`, with no spaces. It is not a full email-address parser.
## Related projects

See the [project index](https://github.com/Jaeger790#projects) for the rest of my work.
