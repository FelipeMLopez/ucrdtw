#ifndef __UCRDTW_H__
#define __UCRDTW_H__

int ucrdtw(const double* data, long long data_size, const double* query, long query_size, double warp_width, int verbose, long long* location, double* distance, const int* dnc);

int ucrdtws(const double* data, long long data_size, const double* query, long query_size, double warp_width, int verbose, long long* location, double* distance, const int* dnc, int stride);

int ucrdtwf(FILE* data_stream, FILE* query_stream, long query_length, double warp_width, int verbose, long long* location, double* distance);

#endif