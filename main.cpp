#include<iostream>

void foo1(int a, int b,int d);

int main()
{
        int a;
	int b;
	int d;
        
        std::cout << " Brinchi Raqam Kriting ";
        std::cin >> a;


        std::cout << " Ikkinchi Raqani Kriting ";
        std::cin >> b;

	std::cout << " Hello git World " << std::endl;

	foo1(a,b,d);
return 0;
}
void foo1(int a,int b, int d)
{
       char c;
       std::cout << "Amallarni Brini Tanlang +,-,*,/ ";
       std::cin >> c;

       switch(c)
	{
	       case'+':
	 {
	       d = a + b;
               std::cout << a << c << b << " = " << d;
	 }
		       break;
	}
}
