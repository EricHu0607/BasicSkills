#pragma once
#ifndef SEARCH_H
#define SEARCH_H

int binary_search(int data[], int size, int search_data);
int binary_search_first_data(int data[], int size, int search_data);
int binary_search_last_data(int data[], int size, int search_data);
int binary_search_last_below(int data[], int size, int search_data);

#endif // !SEARCH_H
