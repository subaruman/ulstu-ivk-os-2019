//ИСТбд-22 Бутузов А.Е.>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


/*FIFO во всем подобен каналу pipe, за одним исключением:
данные о расположении FIFO в адресном пространстве ядра и его состоянии
процессы могут получать не через родственные связи, а через файловую систему.

Задание: напишите на базе предыдущего примера две программы, одна
из которых пишет информацию в FIFO, а вторая – читает из него, так чтобы
между ними не было ярко выраженных родственных связей (т.е. чтобы ни
одна из них не была потомком другой).*/
int main()
{
    int fd;
    char str[]= "FIFO for lab 4";
    printf("Запись информации в FIFO...\n");
    //создания FIFO используется системный вызов mknod
    printf("Начало создания FIFO...\n");
    mknod("/home/andrey/Desktop/OS_GIT/Lab4/fifo", S_IFIFO | 0666, 0);//заводится файл-метка
    printf("FIFO создан...\n");
    // dev = 0 - является несущественным в этой ситуации
    //S_IFIFO - указывает, что системный вызов должен создать FIFO
    //0666 устанавливает атрибуты прав доступа различных категорий пользователей (rw- rw- r--)
    printf("Открываем FIFO на запись...\n");
    fd = open("/home/andrey/Desktop/OS_GIT/Lab4/fifo", O_WRONLY);//-1 ошибка или дескриптор
    printf("Начало записи данных в FIFO...\n");
    write(fd, str, strlen(str));//Если FIFO открывается только для записи, и флаг O_NDELAY не задан,
    //то процесс, осуществивший системный вызов, блокируется до тех пор, пока
    //какой-либо другой процесс не откроет FIFO на чтение.
    printf("Данные записаны\n");
    close(fd);
    /*Когда все процессы, работающие с FIFO, закрывают все файловые дескрипторы,
    ассоциированные с ним, система освобождает ресурсы, выделенные под FIFO.
    Вся непрочитанная информация теряется. В то же время файл-метка остается
    на диске и может использоваться для новой реальной организации FIFO в дальнейшем.*/
    return 0;
}

