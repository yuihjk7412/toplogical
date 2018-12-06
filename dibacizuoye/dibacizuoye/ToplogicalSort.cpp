#include "pch.h"
#include "ToplogicalSort.h"
#include <iostream>


ToplogicalSort::ToplogicalSort()
{
}


ToplogicalSort::~ToplogicalSort()
{
}

void ToplogicalSort::createGraph(void)
{
	std::cout << "PLEASE INPUT THE NUMBER OF THE VEXNUM:";
	std::cin >> vexnum;
	a = new struct nodehead [vexnum+1];
	for (int i = 1; i <= vexnum; i++)
	{
		int sonNum = 0;
		std::cout << "THE NUMBER OF SON VEXNUMS OF THE VEXNUM " << i << ":";
		std::cin >> sonNum;
		if (!sonNum)
		{
			continue;
		}
		else
		{
			a[i].link = new struct node;
			struct node * p = a[i].link;
			std::cout << "NO. 1" << " SON VEXNUM OF TEH VEXNUM " << i << ":";
			std::cin >> p->index;
			a[p->index].count = a[p->index].count + 1;
			for (int j = 1; j < sonNum; j++)
			{
				p->next = new struct node;
				p = p->next;
				std::cout << "NO. " << j + 1 << " SON VEXNUM OF TEH VEXNUM " << i << ":";
				std::cin >> p->index;
				a[p->index].count = a[p->index].count + 1;
			}
		}		
	}
	for (int i = 1; i <= vexnum; i++)
	{
		std::cout << "VEXNUM " << i << "COUNT: "<<a[i].count << "\t";
		struct node * p = a[i].link;
		while (p != NULL)
		{
			std::cout << p->index << "\t";
			p = p->next;
		}
	}
}

void ToplogicalSort::toplogical(void)
{
	top = 0;
	int j = 0;
	struct node * p;
	for (int i = 1; i <= vexnum; i++)
	{
		if (a[i].count == 0)
		{
			a[i].count = top;
			top = i;
		}
	}
	std::cout << "\nTHE RESULT OF TOPLOGICAL SORT: ";
	for (int i = 1; i <= vexnum; i++)
	{
		if (top == 0)
		{
			std::cout << "LOOP";
			return;
		}
		else
		{
			j = top;
			top = a[top].count;
			std::cout << j;
			p = a[j].link;
			while (p != NULL)
			{
				int k = p->index;
				a[k].count = a[k].count - 1;
				if (a[k].count == 0)
				{
					a[k].count = top;
					top = k;
				}
				p = p->next;
			}
		}
	}
}
