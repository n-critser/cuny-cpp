

Input File Format
The input data will be in a file whose name is given on the program's command line. The file will
consist of a number of lines, each of which contains a sttring representing the name of an organism,
followed by some amount of white space, followed by a decimal number representing the organism's
score in some evolutionary weighting scheme. We will call the string the organism's name and the
numeric value its score.

ape 11.0
tiger 50.0
lion 55.0
human 9.0
elephant 76.0
monkey 14.0

Algorithm:
1. each (name,score) pair becomes a tree
2. find closest number subtrees and join them with their root being
	the average of their scores
3. recursively build subtree pairs (right and left) until a single tree exists

How man levels of joining will we need for a N distinct organisms?


Output Format
Once the tree has been constructed, the program must write a representation of it as a string in the
language of balanced parentheses. The output will be written to standard output (i.e. cout in C++). A
binary tree like the one in the figure above, in which every node has either two children or no children,
can be represented unambiguously using nothing but left and right parentheses, the strings in the leavenodes, and commas as separators. We can describe this string recursively as a function of the height of
the tree:

1. A tree of height 1 consisting of a root and a left node containing the string 'a' and a right node
containing the string 'b' is represented by the string “(a,b)”.
2. If T1 and T2 are non-empty trees whose string representations are s1 and s2 respectively, then the
tree T which has T1 as its left subtree and T2 as its right subtree has the string representation
“(s1,s2)”.
Using this recursive definition, the above representation would be represented by the string:
(((ape,human),monkey),((tiger,lion),elephant)))
