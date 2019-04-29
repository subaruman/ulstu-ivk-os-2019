#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;//тип данных pid_t
    printf ("Лабораторная работа № 3.3\
            \nБатюшкиной А.Ю. ИСТбд-21");
    // Узнаем идентификаторы
    pid = getpid();
    pid=fork();//новый процесс может быть порожден единственным способом – с помощью системного вызова fork()
    if(pid!=0)//если это не ребенок
    {
        sleep(360);//задержка процесса на 360 сек

    }
    else
    {
        exit(2); //процессу родителю ничего не возвращает
    }
}
