# FT_CONTAINERS (@42Paris)
*"The multiple available containers in C++ all have very different usage. To make sure you understand them, let’s re-implement them!"*

## Objective

The objective of this project is to implement the various container types of the C++ standard template library.
- vector
- map
- stack

## Containers

### map

My map is made from an avl tree, is a self-balancing binary search tree.
At each insertion and each deletion, I balance the tree. For that I use a rotation system :

                  top
balance tree :    / \
  (result)       x   y

rotate left: put the first under the left side of the second
rotate right: put the first under the right side of the second

|       case 1      |     rotation     | |       case 2      |     rotation     |
|-------------------|------------------| |-------------------|------------------|
|  x                |                  | |      y            | rotate right     |
|   \               |   rotate left    | |     /             |                  |
|   top             |                  | |   top             |                  |
|     \             |                  | |   /               |                  |
|      y            |                  | |  x                |                  |

|       case 3      |     rotation     | |       case 4      |     rotation     |
|-------------------|------------------| |-------------------|------------------|
|  x                |                  | |    y              |                  |
|   \               | rotate left      | |   /               | rotate right     |
|    y              | rotate right     | |  x                | rotate left      |
|   /               |                  | |   \               |                  |
| top               |                  | |   top             |                  |

## Usage
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
