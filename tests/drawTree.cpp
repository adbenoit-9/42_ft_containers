/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawTree.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:29:30 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/23 04:03:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

VECT	getTreeDrawing(TREE::Node* node, VECT drawing, int l, int y = 0,
        int level = 0, int side = 0)
{
    if (node)
    {
        ++level;
        y += (side * (l / pow(2, level)));
        if (side == 1)
            ++y;
        drawing = getTreeDrawing(node->right, drawing, l, y, level, 1);
        drawing = getTreeDrawing(node->left, drawing, l, y, level, -1);;
        drawing[(level - 1) * l + y].first = node->value.first;
        drawing[(level - 1) * l + y].second = -1;
        if (node->parent && node->value.first > node->parent->value.first)
            drawing[(level - 1) * l + y].second = 1;
    }
    
    return drawing;
}

void		drawTree(TREE tree)
{
    int 	treeHeight = tree.height(tree.root());
    int		l = pow(2, treeHeight - 1) * 2 - 1;
    VECT    drawing(treeHeight * l);
    
    drawing = getTreeDrawing(tree.root(), drawing, l, l / 2);
    for (size_t i = 0; i < drawing.size(); i++)
    {
        if (i % l == 0 && i != 0)
        {
            std::cout << std::endl;
            std::string link;
            int draw = 0;
            for (int j = 0; j < l; j++)
            {
                if (!drawing[i - l + j].first.empty())
                {
                    link += '^';
                    int n = l / (pow(2, i / l + 1)) + 1;
                    draw = (drawing[i + j + n].second == 1) ? 1 : 0;
                }
                else if (drawing[i + j].first.empty())
                    link += (draw == 1) ? '-' : ' ';
                else
                {
                    link += '|';
                    draw = (drawing[i + j].second == -1) ? 1 : 0;
                }
            }

            std::cout << "\033[32m" << link << "\033[0m" << std::endl;
        }
        if (drawing[i].first.empty())
            std::cout << " ";
        else
            std::cout << "\033[35m" <<  drawing[i].first << "\033[0m";
    }
    std::cout << std::endl << std::endl;
}

// template <class T>	
// std::ostream&	operator<<(std::ostream& os, const Tree<T>& tree)
// {
//     os << "\n\033[1;32m"
//     << "┌┬┐┬─┐┌─┐┌─┐" << std::endl
//     << " │ ├┬┘├┤ ├┤ " << std::endl 
//     << " ┴ ┴└─└─┘└─┘" << std::endl
//     << "~~~~~~~~~~~~~" << "\033[0m" << std::endl << std::endl;
//     os	<< "\033[2mheight : " << tree.height(tree.root()) << "\033[0m\n"
//         << "\033[2msize : " << tree.size(tree.root()) << "\033[0m\n" << std::endl;
//     drawTree(tree.root());
//     return os;
// }
