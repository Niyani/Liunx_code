void handler(int s)
{

}

int mysleep(int sec)
{
        signal(SIGALRM,handler);
        //先将alarm信号阻塞
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set,SIGALRM);
        sigprocmask(SIG_BLOCK,&set,NULL);
        alarm(sec);

        //增强版pause   sigsuspend();
        sigset_t myset;
        sigemptyset(&myset);
        sigsuspend(&myset);
        sigprocmask(SIG_UNBLOCK,&set,NULL);
        //pause();
        return alarm(0);
}
int main()
{
        int n=1;
        for(; ;)
        {
                printf("mmc %d\n",n++);
                mysleep(1);
        }
}
