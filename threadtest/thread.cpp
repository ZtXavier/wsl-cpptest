#include"thread.hpp"


Thread::Thread():autoDelete_(false)
{
    std::cout << "thread ..." << std::endl;
}

Thread::~Thread()
{
    std::cout << "~thread ..." << std::endl;
}

void Thread::Start()
{
    pthread_create(&pthread_id,NULL,threadrounte,this);
}

void Thread::Join()
{
    pthread_join(pthread_id,NULL);
}

void *Thread::threadrounte(void *arg)
{
    Thread *thread = static_cast<Thread*>(arg);
    thread->Run();
    if (thread->autoDelete_)
    {
        delete thread;
    }
    return NULL;
}

void Thread::setautoDelete(bool autoDelete)
{
    autoDelete_ = autoDelete;
}