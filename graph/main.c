#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usefc.h"
#include "vertex.h"
#include "edge.h"

#define LINE_LEN 256

int main(int argc, char *argv[]) {
	int v_argument_index, e_argument_index, mst_argument_index, mrn_argument_index;
	uint vertex_dlen = 0, edge_dlen = 0;
	vertex *vertex_data;
	edge *edge_data;

/* osetreni argumentu */
	if(argc < 4){
		printf("Error: Invalid argument count!\n");
		return EXIT_FAILURE;
	} 
	
	v_argument_index = inArrayString(argc, argv, "-v");
	e_argument_index = inArrayString(argc, argv, "-e");
	mst_argument_index = inArrayString(argc, argv, "-mst");
	mrn_argument_index = inArrayString(argc, argv, "-mrn");
	 
	if(v_argument_index<0 || e_argument_index<0){
		printf("Error: Invalid argument count!\n");
		return EXIT_FAILURE;
	} 

/* nacteni vrcholu */
	vertex_data = vertex_load(argv[v_argument_index+1], &vertex_dlen);
	if(!vertex_dlen){
		return 1;
	}
	qsort(vertex_data, vertex_dlen, sizeof(vertex), vertex_compar_fn);
	vertex_print(vertex_data, vertex_dlen);

/* nacteni hran */
	edge_data = edge_load(argv[e_argument_index+1], &edge_dlen);
	if(!edge_dlen){
		return 2;
	}
	qsort(edge_data, edge_dlen, sizeof(edge), edge_compar_fn);
	edge_print(edge_data, edge_dlen);

	if(mst_argument_index>=0)
		printf("ready for argument mst\n");
	if(mrn_argument_index>=0)
		printf("ready for argument mrn\n");

	return 0;
}