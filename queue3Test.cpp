#include "queue3.h"
#include <iostream>
using namespace std;
int main()
{

	
	queue queue1;
	queue1.push(1);
	queue1.push(2);
	queue1.push(3);
	queue1.push(10);
	cout << "The front is: " << queue1.front() << endl;




	queue1.pop();
	cout << "After poping once, The front is: " << queue1.front() << endl;
	queue1.pop();
	cout << "After poping again, The front is: " << queue1.front() << endl;
	queue1.pop();
	cout << "After poping one more time, The front is: " << queue1.front() << endl;

	queue1.pop();
	cout << "After poping one last time, The queue is empty"<< endl;

	queue1.push(1);
	cout << "After pushing one, The front is: " << queue1.front() << endl;


	
	return 0;
}