#include <queue>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Sorting_Machine_2.h"

Sorting_Machine_2::Sorting_Machine_2()
{
    inserting_rep = true;
}
Sorting_Machine_2::~Sorting_Machine_2()
{

}
//---------------------------------
void Sorting_Machine_2::Partition(queue<item>& q, item& p, queue<item>& q1, queue<item>& q2)
{
	// clear q1 and q2
	while (q1.size() > 0)
	{
		q1.pop();
	}
	while (q2.size() > 0)
	{
		q2.pop();
	}
	item x;
	while (q.size() > 0)
	{
		x = q.front();
		q.pop();
		if (x <= p)
		{
			q1.push(x);
		}
		else
		{
			q2.push(x);
		}
	}
}
void Sorting_Machine_2::Combine(queue<item>& q, item& p, queue<item>& q1, queue<item>& q2)
{
	while (q.size() > 0)
	{
		q.pop();
	}
	item x;
	while (q1.size() > 0)
	{
		x = q1.front();
		q1.pop();
		q.push(x);
	}
	q.push(p);
	while (q2.size() > 0)
	{
		p = q2.front();
		q2.pop();
		q.push(p);
	}
}
void Sorting_Machine_2::Sort(queue<item>& q)
{
	if (q.size() > 1)
	{
		item temp;
		queue<item> q1, q2;
		
		temp = q.front();
		q.pop();
		
		Partition(q, temp, q1, q2);
		Sort(q1);
		Sort(q2);
		Combine(q, temp, q1, q2);
	}
}
void Sorting_Machine_2::Swap(item a, item b)
{
	item temp = a;

	a = b;
	b = temp;
}
//----------------------------------
void Sorting_Machine_2::Change_To_Insertion_Phase()
{
     inserting_rep = true;
}
void Sorting_Machine_2::Insert(item& x)
{
	contents_rep.push(x);
}
void Sorting_Machine_2::Change_To_Extraction_Phase()
{
	inserting_rep = false;
	Sort(contents_rep);
}
void Sorting_Machine_2::Remove_First(item& x)
{
	x = contents_rep.front();
	contents_rep.pop();
}
void Sorting_Machine_2::Remove_Any(item& x)
{
	x = contents_rep.front();
	contents_rep.pop();
}
void Sorting_Machine_2::Clear()
{
	while (contents_rep.size() > 0)
	{
		contents_rep.pop();
	}
}
bool Sorting_Machine_2::Is_In_Extraction_Phase()
{
	return (not(inserting_rep));
}
int Sorting_Machine_2::Size()
{
	return contents_rep.size();
}
