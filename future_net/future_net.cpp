#include "route.h"
#include "lib_io.h"
#include "lib_time.h"
#include "stdio.h"
#include "floyd.h"
#include "Dijkstra.h"
#include "define.h"

int V[7][7] = {
	0,1,1,7,7,7,
	7,0,7,1,7,7,
	7,7,0,1,1,7,
	1,7,7,0,7,1,
	7,7,7,7,0,1,
	7,7,7,7,7,0
};

int main(int argc, char *argv[])
{
	Floyd test;
	test.initialvector((int *)V,6);
	test.floyd();

	Dijkstra test_dijkstra;
	test_dijkstra.dijkstra(3,(int*)V,6);

    //print_time("Begin");
    char *topo[5000];
    int edge_num;
    char *demand;
    int demand_num;

    char *topo_file = argv[1];
    edge_num = read_file(topo, 5000, topo_file);
    if (edge_num == 0)
    {
        printf("Please input valid topo file.\n");
        return -1;
    }
    char *demand_file = argv[2];
    demand_num = read_file(&demand, 1, demand_file);
    if (demand_num != 1)
    {
        printf("Please input valid demand file.\n");
        return -1;
    }

    search_route(topo, edge_num, demand);

    char *result_file = argv[3];
    write_result(result_file);
    release_buff(topo, edge_num);
    release_buff(&demand, 1);

    //print_time("End");

	return 0;
}

