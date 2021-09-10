#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int QElemType;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct
{
	QElemType* base;
	int front;
	int rear;
}MySqQueue;

Status InitQueue(MySqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)	exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(MySqQueue& Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(MySqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
	{
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(MySqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

QElemType GetHead(MySqQueue Q)
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}

Status QueueEmpty(MySqQueue Q)
{
	if (Q.front == Q.rear) /* 队列空的标志 */
		return TRUE;
	else
		return FALSE;
}

#endif // !_MYQUEUE_H_

