#pragma once
#include <iostream>
#include <string>

struct node 
{
	int index;
	struct node * next = NULL;
	std::string label;
};
struct nodehead
{
	int count = 0;
	 
	struct node * link = NULL;
};
class ToplogicalSort
{
private:
	struct nodehead * a;
	int top = 0;
	int vexnum = 0;
public:
	ToplogicalSort();
	~ToplogicalSort();
	void createGraph(void);
	void toplogical(void);
};

