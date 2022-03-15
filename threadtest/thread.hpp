#ifndef _THREAD_H_
#define _THREAD_H_
#include<pthread.h>
#include<iostream>

class Thread
{
    public:
        Thread();
        virtual ~Thread();
        void Start();
        void Join();
        void setautoDelete(bool autoDelete);

    private:
        // 静态成员函数，类同全局函数
        static void *threadrounte(void *arg);
        virtual void Run() = 0;  //虚函数,也是普通成员函数
        pthread_t pthread_id;
        bool autoDelete_;
};



#endif