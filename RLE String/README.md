# RLE Encoding and Decoding

This repository implements a [Run-Length Encoding (RLE)](https://en.wikipedia.org/wiki/Run-length_encoding) compression and decompression solution using [linked lists](https://en.wikipedia.org/wiki/Linked_list).

## Problem Definition

RLE is a simple encoding scheme that compresses a sequence of elements by representing repetitions as ordered pairs (N, X).
For example, the row
```
A, A, A, A, A, A, A, B, A, B, B, B, B, B, B, C, B
```
can be represented by an RLE as the row 
```
(7,A), (1,B), (1,A), (6,B), (1,C), (1,B).
```
## RleString Class

The RleString class represents a string of characters of type char encoded by RLE. Internally, the class stores the information in a linked list, where each node corresponds to one pair of the RLE string. The class implements several methods to manipulate the RLE-encoded string, such as insert, remove, and concatenate.
The description of the RleString class interface can be found in the RleString.h file.

### Usage
To build the project:
```
mkdir build
cd build
cmake ..
cmake --build .
```
To run tests:
```
ctest
```
