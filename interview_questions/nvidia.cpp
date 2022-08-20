Coding
Write code for a circular queue for fixed size objects. State assumptions.
What needs to change to make the code multithreaded/thread safe, if any?

class CircularQueue_t
{
private:
	struct Node_t
{
	int val;
	Node_t* next;
	
	Node_t(int val_) : val(val_), next(nullptr) {}
	};

	int maxElements;
uint32_t count;
Node_t* head;
Node_t* tail;

void addNode(Node_t* node_)
{
	if(head == nullptr)
{
	head = node_;
tail = head;
}
else
{
	tail->next = node_;
	tail = tail->next;
}
}

void removeNode(int& val)
{
	val = head->val;
	
Node_t* node = head;
	count–;
head = head->next;
if(head == nullptr)
{
	tail = nullptr;
}

delete node;
}
public:
	CircularQueue_t() : maxElements(10), count(0), head(nullptr), tail((nullptr)) {};
	CircularQueue_t(int maxElements_) : maxElements(maxElements_), count(0), head(nullptr), tail(nullptr){}
	
	int front(void) const
{
	AutoLock_t lock_(lock);
	if(head == nullptr)
{
	return -1;
}

return head->val;
}

int push_back(int val_);
{
	AutoLock_t lock_(lock);
	if(count == maxElement)
	{
		return -1; 
	}

	Node_t* node = new Node_t(val_);
	if(node == nullptr)
{
	return -1;
}

count++;
	addNode(node);
	return 0;
}

int pop_back(int& val)
{
AutoLock_t lock_(lock);
	if(head == nullptr)
{
	return -1;
}

removeNode(val);
return 0;
}
};



Is there anything wrong with the following code?
Problem 1

#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
void *mymalloc(unsigned int size) { return malloc(size); }

int main()
{
    char *buf;	// initialization missed
    size_t len; // initialization missed
    read(0, &len, sizeof(len));
	// check for overflow point view or max possible allocation size!!
    buf = mymalloc(len);
	// null check missed out
    read(0, buf, len);
	// sensitive data could be in allocated memory! are we safe enough to read out!?

    return 0;
}

Problem 2
#include <stdio.h>
int main(){
    char last_name[20]; // initialization missing!
    printf ("Enter your last name: ");
    scanf ("%s", last_name); // if the entered data is beyond 20 characters, user gain access!!
    return 0;
}

Problem 3

int main()
{
    int y=10;
    int a[10];
    while (y>=0) 
    {   
        a[y]=y; // seg fault! can happen!
        y=y-1;
    }
    return 0;
}

Problem 4
#include <unistd.h>
#include <stdlib.h> 
int main()
{
    char *buf;	// initialzation
    int len; // initialzation

    read(0, &len, sizeof(len));

    if (len > 8000) {return 0; } // signed extended ness might result in run time error
    buf = malloc(len); //validity check 
    read(0, buf, len);
    return 0;
}

Problem 5
#include <stdio.h>
#include <string.h>
int main(){
    char firstname[20];
    char lastname[20];
    char fullname[40];
    firstname[0]='\0';
    strncat(fullname, firstname, 20));
    strncat(fullname, lastname, 20); // firstname will get overwritten
    return 0;
}
