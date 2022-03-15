#include<iostream>
#include<unistd.h>
#include"thread.hpp"


class Testthread:public Thread
{
    public:
        Testthread(int count):count_(count)
        {
            std::cout << "Testthread ..."  << std::endl;
        }
        ~Testthread()
        {
            std::cout <<"~Testthread ..." << std::endl;
        }
        void Run()
        {
            while(count_--)
            {
                std::cout << "this is a test %d"  << count_ << std::endl;
                sleep(1);
            }
        }
    private:
        int count_;
};

int main()
{
    Testthread t(5);
    t.Start();
    t.Join();
    return 0;
}