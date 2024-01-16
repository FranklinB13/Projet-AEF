# Projet-AEF
Introduction
The purpose of this program is to implement a finite automaton in the C programming language. The automaton is defined by its number of states, alphabet, transition function, initial state, and set of final states. The program facilitates the creation, filling, display, transition input, word recognition, and memory deallocation for the automaton.

Code Structure
The file autom.c comprises the implementation of various functionalities. A Automaton structure is utilized to store details about the automaton, such as the number of states, symbols, transitions, and a three-dimensional matrix to represent the transition function.

Implemented Features
Automaton Creation (creerAutomate): Allows the user to specify the number of states, symbols, and transitions for the automaton. Dynamically allocates memory for the transition matrix.

Transition Input (saisirtransition): Prompts the user to input transitions by specifying the starting state, symbol, and ending state. Includes checks to ensure the indices are valid.

Filling the Automaton (remplirAutomate): Prompts the user to specify the values of the transition matrix for each possible transition.

Displaying the Automaton (afficherAutomate): Displays the transition matrix in the form of triples (starting state, symbol, ending state) if the transition exists.

Checking a Word (verifierMot): Takes a word represented as a linked list of symbols and checks if the automaton recognizes it. Displays the result.

Memory Management (libererListe, supprimerAutomate): The libererListe and supprimerAutomate functions are used to free dynamically allocated memory.

Program Usage
The program employs a straightforward user interface, allowing users to specify the automaton's characteristics, input transitions, fill the matrix, and check if a word is recognized. Checks are implemented to prevent index overflow.

Conclusion
This program provides a basic implementation of a finite automaton in C, enabling users to define an automaton, input transitions, fill the matrix, and check if a word is recognized. Additionally, it incorporates memory cleanup mechanisms to prevent memory leaks.





