
#include <iostream>

using namespace std;

struct free_throws
{
std::string name;
int made;
int attempts;
float percent;
};

const free_throws & clone(free_throws & ft)
{
free_throws * pt;
*pt = ft; // copy info
return *pt; // return reference to copy
}

int main()
{
   free_throws ft;
   clone(ft);
   return 0;
}
