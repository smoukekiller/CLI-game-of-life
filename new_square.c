#include "new_square.h"


//int main(){
//	srandom(time(NULL));
//	int row, col;
//	row = 10000;
//	col = 10000;
//	bool *arr_ptr = init_array(row, col);	
//	bool *help_arr_ptr = init_array(row, col);
//	fill_random(arr_ptr, row, col);
//	render_new(arr_ptr, help_arr_ptr, row, col);
//}

bool *init_array(int row, int col){
	return malloc(sizeof(_Bool)*(row*col));
}

void print_board(bool *arr_ptr, int row, int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			printf("%b", arr_ptr[i*col+j]);	
		}
		printf("\n");
	}
}

void fill_random(bool *arr_ptr, int row, int col){
	for (int i = 0; i < (row*col); i++){
		arr_ptr[i] = (random()%2);
	}
}

int find_neighbours(bool *arr_ptr, int order, int row, int col){
	int order_tl, order_t, order_tr, order_l, order_r, order_bl, order_b, order_br;
	
	order_tl = order - col - 1;
	order_t = order - col;
	order_tr = order - col + 1;
	order_l = order - 1;
	order_r = order + 1;
	order_bl = order + col - 1;
	order_b = order + col;
	order_br = order + col + 1;
	//printf("order_r:%d\n", order_r);	
	//check top
	if((order - col) < 0){
		order_tl = -1;
		order_t = -1;
		order_tr = -1;
	}
	//check right
	if((order % col) == (col - 1)){
		//printf("right fail\n");
		order_tr = -1;
		order_r = -1;
		order_br = -1;
	}
	//check left
	if((order % col) == 0){
		order_tl = -1;
		order_l = -1;
		order_bl = -1;
	}	
	//check bottom
	if(order >= (col * (row-1))){
		order_bl = -1;
		order_b = -1;
		order_br = -1;
	}
	int total_counter = 0;
	if (order_tl >= 0) {total_counter+=arr_ptr[order_tl];}
	if (order_t >= 0) {total_counter+=arr_ptr[order_t];}
	if (order_tr >= 0) {total_counter+=arr_ptr[order_tr];}
	if (order_r >= 0) {total_counter+=arr_ptr[order_r];}
	if (order_l >= 0) {total_counter+=arr_ptr[order_l];}
	if (order_bl >= 0) {total_counter+=arr_ptr[order_bl];}
	if (order_b >= 0) {total_counter+=arr_ptr[order_b];}
	if (order_br >= 0) {total_counter+=arr_ptr[order_br];}
	//printf("total:%d\n", total_counter);
	return total_counter;
}

void render_new(bool *arr_ptr, bool *help_arr_ptr, int row, int col){

	int numberNei;
	for (int i = 0; i < (row*col); i++){
		numberNei = find_neighbours(arr_ptr, i, row, col);
		if (arr_ptr[i]){
			if((numberNei == 2) ||(numberNei == 3)){
				help_arr_ptr[i] = 1;
			}
			else{help_arr_ptr[i] = 0;}
		} 
		else{
			if(numberNei == 3){help_arr_ptr[i] = 1;}
			else{help_arr_ptr[i]=0;}
		}
	}
	for (int i = 0; i < (row*col); i++){
		arr_ptr[i] = help_arr_ptr[i];
	}
}
