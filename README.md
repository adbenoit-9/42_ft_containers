# FT_CONTAINERS (@42Paris)
*"The multiple available containers in C++ all have very different usage. To make sure you understand them, let’s re-implement them!"*

## Objective

The objective of this project is to implement the various container types of the C++ standard template library.
- [vector](#vector) : same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted.
- [map](#map) : an associative container/array that store elements formed by a combination of a key value and a mapped value.
My map is made from an avl tree, is a self-balancing binary search tree.
It balances at each insertion and deletion.
You will find my rotation system in the `rotations_avl.txt` file.
- [stack](stack) : a type of container adaptor with LIFO(Last In First Out) type of working, where a new element is added at one end (top) and an element is removed from that end only.  

## TESTER
```
$ git clone https://github.com/adbenoit-9/42_ft_containers.git
$ cd 42-ft-containers/
$ make help
```
![Example](img/help.png)

### Execution
```
$ make run
```
![Example](img/screenshot.png)
