#include "Dijkstra.h"
#include "define.h"

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
}

void Dijkstra::dijkstra(int start, int* V, int N)
{
	vector<bool> s;                 //�Ƿ��Ѿ���S������  
	s.reserve(0);  
	s.assign(N, false);

   /*��ʼ��dist��prev����*/  
    for(int i =0; i < N; ++i)  
    {  
        dist[ i ] = V[ start*N + i ];  
        if(V[ start*N + i ] < MAX_COST)  
            prev[ i ] = start;  
        else  
            prev[ i ] = -1;       //��ʾ����֪��ǰһ���ڵ���ʲô  
    }  
    prev[ start ] = -1;  
      
    /*��ʼʹ��̰��˼��ѭ��������S�����е�ÿһ���ڵ�*/  
    s[start] = true;          //��ʼ�ڵ����S������  
      
      
    int u = start;  
      
    for (int i = 1; i < N; i ++)      //����ѭ����1��ʼ����Ϊ��ʼ�ڵ��Ѿ������S���ˣ�����N-1���ڵ�Ҫ����  
    {  
          
        /*ѡ��dist��С��һ���ڵ�*/  
        int nextVertex = u;  
        int tempdist = MAX_COST;  
        for(int j = 0; j < N; ++j)  
        {  
            if((s[j] == false) && (dist[j] < tempdist))//Ѱ�Ҳ���S�����е�dist��С�Ľڵ�  
            {  
                nextVertex = j;  
                tempdist = dist[j];  
            }  
        }  
        s[nextVertex] = true;//����S������  
        u = nextVertex;//��һ��Ѱ�ҵĿ�ʼ�ڵ�  
          
          
        /*����dist*/  
        for (int j =0; j < N; j ++)  
        {  
            if (s[j] == false && V[u*N +j] < MAX_COST)  
            {  
                int temp = dist[ u ] + V[u*N + j ];  
                if (temp < dist[ j ])  
                {  
                    dist[ j ] = temp;  
                    prev[ j ] = u;  
                }  
            }  
        }  
    }  
         
} 
