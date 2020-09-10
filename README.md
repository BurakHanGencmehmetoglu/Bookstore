There are two main classes which are BookStore and Book.

BookStore class holds linkedlist of books.

Book class holds ISBN,price and next book in the linkedlist.

HardCopy class which is derived from Book class represents physically sold books.

SoftCopy class which is derived from Book class represents the books sold online.

SoftCopy class holds data in its pages as a binary tree structure.

Each SoftCopy object contains two subtree such that one of them represents initial half while other one represents second half of the parent.

Each leaf of the tree represents SoftCopy which contains a single page.

Detailed explanations about functions can be found in '.h' files. 