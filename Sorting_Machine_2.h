#include <queue>
#include <cstdlib>
#include <string>

#ifndef _Sorting_Machine_2_
#define _Sorting_Machine_2_

using namespace std;

typedef int item;

class Sorting_Machine_2
{
	private:
		queue<item> contents_rep;
		bool inserting_rep;

		void Partition(queue<item>& q, item& p, queue<item>& q1, queue<item>& q2);
		/*!
		!*/
        	void Combine(queue<item>& q, item& p, queue<item>& q1, queue<item>& q2);
		/*!
		!*/
		void Sort(queue<item>& q);	
		/*!
		!*/
		void Swap(item a, item b);
		/*!
		!*/			
	public:
		Sorting_Machine_2();
		/*!
		!*/
		~Sorting_Machine_2();
		
		void Change_To_Insertion_Phase();
		/*!
		!*/
		void Insert(item& x);
		/*!
		!*/
		void Change_To_Extraction_Phase();
		/*!
		!*/
		void Remove_First(item& x);
		/*!
		!*/
		void Remove_Any(item& x);
		/*!
		!*/
		void Clear();
		/*!
		!*/
		
		bool Is_In_Extraction_Phase();
		/*!
		!*/
		int Size();
		/*!
		!*/
};

#include "Sorting_Machine_2.cc"
#endif
