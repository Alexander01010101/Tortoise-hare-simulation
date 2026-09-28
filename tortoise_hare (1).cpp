// Simulation: The Tortoise and the Hare
// A random-number-driven race simulation between a Tortoise and a Hare
// on a 70-square course, using pointer-based pass-by-reference.

#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

const int FINISH = 70;

// Moves the tortoise. Takes a pointer to the tortoise's position so the
// caller's variable is modified directly (pointer-based pass-by-reference).
void moveTortoise(int *tortoisePosition) {
    int i = 1 + rand() % 10; // random integer 1 <= i <= 10

    if (i >= 1 && i <= 5) {
        // Fast plod: 3 squares to the right (50%)
        *tortoisePosition += 3;
    } else if (i >= 6 && i <= 7) {
        // Slip: 6 squares to the left (20%)
        *tortoisePosition -= 6;
    } else { // i is 8, 9, or 10
        // Slow plod: 1 square to the right (30%)
        *tortoisePosition += 1;
    }

    // Cannot slip back before the starting gate.
    if (*tortoisePosition < 1) {
        *tortoisePosition = 1;
    }
}

// Moves the hare. Takes a pointer to the hare's position for the same
// pointer-based pass-by-reference reason as moveTortoise.
void moveHare(int *harePosition) {
    int i = 1 + rand() % 10; // random integer 1 <= i <= 10

    if (i >= 1 && i <= 2) {
        // Sleep: no move at all (20%)  (i == 1 or 2)
    } else if (i >= 3 && i <= 4) {
        // Big hop: 9 squares to the right (20%)
        *harePosition += 9;
    } else if (i == 5) {
        // Big slip: 12 squares to the left (10%)
        *harePosition -= 12;
    } else if (i >= 6 && i <= 8) {
        // Small hop: 1 square to the right (30%)
        *harePosition += 1;
    } else { // i is 9 or 10
        // Small slip: 2 squares to the left (20%)
        *harePosition -= 2;
    }

    if (*harePosition < 1) {
        *harePosition = 1;
    }
}

// Prints one 70-position line of the race course, showing T, H, OUCH!!!
// (for a tie), or blank spaces everywhere else.
void printPositions(int tortoisePosition, int harePosition) {
    // Clamp printed positions to the board so an animal that has already
    // won (position > 70) does not print past the course on its final line.
    int tPos = tortoisePosition;
    int hPos = harePosition;
    if (tPos > FINISH) {
        tPos = FINISH;
    }
    if (hPos > FINISH) {
        hPos = FINISH;
    }

    if (tPos == hPos) {
        // Tie: the tortoise bites the hare; print OUCH!!! starting there.
        for (int square = 1; square < tPos; square++) {
            cout << ' ';
        }
        cout << "OUCH!!!" << endl;
    } else {
        for (int square = 1; square <= FINISH; square++) {
            if (square == tPos) {
                cout << 'T';
            } else if (square == hPos) {
                cout << 'H';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // seed the random number generator

    int tortoisePosition = 1;
    int harePosition = 1;
    int raceOver = 0; // 0 = still racing, 1 = someone has won

    cout << "BANG!!!!!" << endl;
    cout << "AND THEY ARE OFF!!!!!" << endl << endl;

    while (raceOver == 0) {
        moveTortoise(&tortoisePosition);
        moveHare(&harePosition);

        printPositions(tortoisePosition, harePosition);

        // Check whether either animal reached or passed the finish line.
        // If both did on the same tick, favor the tortoise (the underdog).
        if (tortoisePosition >= FINISH) {
            cout << endl << "TORTOISE WINS!!!YAY!!!" << endl;
            raceOver = 1;
        } else if (harePosition >= FINISH) {
            cout << endl << "Hare wins. Yuch." << endl;
            raceOver = 1;
        }
        // Otherwise, neither has won yet: loop again for the next clock tick.
    }

    return 0;
}
