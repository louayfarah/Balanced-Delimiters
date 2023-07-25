# Balanced-Delimiters

Welcome to the balanced delimiters problem.

You are given a text that contains multiple types of delimiters that act like parentheses. Implement a program that checks if all delimiteres in the input text are properly balanced.

The solution provides an implementation of LinkedStack (implementation based on linked lists) and use it to solve the problem. 

Input

First line of input contains numbers N (0≤N≤100) of types of delimiters and K (1≤K≤105). Each of the next N lines contains two tokens — an openning delimiter and closing delimiter of the the same type. The last K lines contain a sequence of tokens (arbitrary, not only delimiters) separated by whitespaces to check for balanced delimiters.

Output

If the input sequence of tokens has properly balanced delimiter, then output: The input is properly balanced.

Otherwise, you must specify the leftmost location in the sequence that contains a mistake in the input. The error message should be one of the following:

Error in line <line>, column <column>: unexpected closing token <token>.

Error in line <line>, column <column>: expected <token> but got <token>.

Error in line <line>, column <column>: expected <token> but got end of input.
