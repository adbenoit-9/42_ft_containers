/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/23 03:59:52 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template<class T, class T1>
void    checkStack(T& stdS, T1& ftS)
{
	if (!stdS.empty() && stdS.top() != ftS.top())
	{
		std::cout << "❌";
		return ;
	}
    if (stdS.empty() == ftS.empty() && stdS.size() == ftS.size())
		std::cout << "✅";
	else
		std::cout << "❌";
}

template<class T, class T1>
void	checkOperators(T& stdStack, T1& ftStack)
{
	std::cout << "operators\t⬜";
	
	T stdCopy(stdStack);
	T1 ftCopy(ftStack);
	compareRet((stdStack == stdCopy), (ftStack == ftCopy)); // #0
	compareRet((stdStack != stdCopy), (ftStack != ftCopy)); // #1
	compareRet((stdStack < stdCopy), (ftStack < ftCopy)); // #2
	compareRet((stdStack <= stdCopy), (ftStack <= ftCopy)); // #3
	compareRet((stdStack > stdCopy), (ftStack > ftCopy)); // #4
	compareRet((stdStack >= stdCopy), (ftStack >= ftCopy)); // #5
	
	stdCopy.pop();
	ftCopy.pop();
	compareRet((stdStack == stdCopy), (ftStack == ftCopy)); // #6
	compareRet((stdStack != stdCopy), (ftStack != ftCopy)); // #7
	compareRet((stdStack < stdCopy), (ftStack < ftCopy)); // #8
	compareRet((stdStack <= stdCopy), (ftStack <= ftCopy)); // #9
	compareRet((stdStack > stdCopy), (ftStack > ftCopy)); // #10
	compareRet((stdStack >= stdCopy), (ftStack >= ftCopy)); // #11
}

void    stackTests(void)
{
	title("Stack");

	std::cout << "Test n˚\t\t⬜0️⃣ 1️⃣ 2️⃣ 3️⃣ 4️⃣ 5️⃣ 6️⃣ 7️⃣ 8️⃣ 9️⃣ 🔟\n" 
			<< "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<< std::endl;
	{
					/* EMPTY */
		// #0
		std::stack<int, std::vector<int> > stdStack;
		ft::stack<int, std::vector<int> > ftStack;
		std::cout << "empty()\t\t⬜";
		checkStack(stdStack, ftStack);
		// #1
		stdStack.push(1);
		ftStack.push(1);
		checkStack(stdStack, ftStack);
		// #2
		stdStack.pop();
		ftStack.pop();
		checkStack(stdStack, ftStack);
		std::cout << std::endl;
	}
	{
					/* SIZE */
		// #0
		std::stack<int, std::vector<int> > stdStack;
		ft::stack<int, std::vector<int> > ftStack;
		std::cout << "size()\t\t⬜";
		checkStack(stdStack, ftStack);
		// #1
		stdStack.push(1);
		ftStack.push(1);
		checkStack(stdStack, ftStack);
		// #2
		stdStack.pop();
		ftStack.pop();
		checkStack(stdStack, ftStack);
		std::cout << std::endl;
	}
	{
					/* TOP */
		// #0
		std::stack<int, std::vector<int> > stdStack;
		ft::stack<int, std::vector<int> > ftStack;
		std::cout << "top()\t\t⬜";
		checkStack(stdStack, ftStack);
		// #1
		stdStack.push(1);
		ftStack.push(1);
		checkStack(stdStack, ftStack);
		// #2
		stdStack.pop();
		ftStack.pop();
		checkStack(stdStack, ftStack);
		std::cout << std::endl;
	}
	{
					/* PUSH */
		// #0
		std::stack<int, std::vector<int> > stdStack;
		ft::stack<int, std::vector<int> > ftStack;
		std::cout << "push()\t\t⬜";
		checkStack(stdStack, ftStack);
		// #1
		for (int i = 0; i < 5; i++)
		{
			stdStack.push(i);
			ftStack.push(i);
			checkStack(stdStack, ftStack);
		}
					/* POP */
		// #0
		std::cout << std::endl;
		std::cout << "pop()\t\t⬜";
		checkStack(stdStack, ftStack);
		for (int i = 0; i < 5; i++)
		{
			// #i+1
			stdStack.pop();
			ftStack.pop();
			checkStack(stdStack, ftStack);
		}
		std::cout << std::endl;
	}
	{
		std::stack<int, std::vector<int> > stdStack;
		ft::stack<int, std::vector<int> > ftStack;
		for (int i = 0; i < 5; i++)
		{
			stdStack.push(i);
			ftStack.push(i);
		}
		checkOperators(stdStack, ftStack);
		std::cout << std::endl;
	}
}
