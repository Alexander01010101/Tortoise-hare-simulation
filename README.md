# Tortoise-hare-simulation

This program is a C++ simulation of the classic "Tortoise and the Hare" race, run on a 70-square course. Both animals start at square 1, and the program uses randomly generated numbers to decide how each one moves every second (each iteration of the main loop), following a set of weighted probabilities: the Tortoise usually plods forward but occasionally slips backward, while the Hare alternates between sleeping, taking small hops, or making big (and sometimes risky) leaps that can also send it sliding back.

Two functions, moveTortoise and moveHare, handle the movement logic. Each takes a pointer to that animal's position variable, so it can update the animal's location directly in memory rather than returning a value — this is the pointer-based pass-by-reference approach the assignment calls for.

After each tick of the clock, the program prints a line representing the 70-square track, marking the Tortoise's position with a T and the Hare's with an H. If both animals land on the same square, it prints OUCH!!! instead, since the Tortoise bites the Hare. The race continues, tick by tick, until one animal reaches or passes square 70. Whoever gets there first is declared the winner (TORTOISE WINS!!!YAY!!! or Hare wins. Yuch.); if both would cross the finish line on the same tick, the Tortoise wins as the underdog.
