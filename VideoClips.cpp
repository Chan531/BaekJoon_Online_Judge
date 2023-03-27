#include "videoclips.h"

int sparse_table[31][100000];

void videos(int K, int M, int S[]) {
	for (int i = 0; i < K; i++)
		sparse_table[0][i] = S[i];

	for (int i = 1; i < 30; i++)
		for (int j = 0; j < K; j++)
			sparse_table[i][j] = sparse_table[i - 1][sparse_table[i - 1][j]];

	for (int i = 0; i < K; i++)
	{
		int idx = i;
		for (int j = 0; j < 30; j++)
			if ((1 << j) & (M - 1))
				idx = sparse_table[j][idx];

		sparse_table[30][i] = idx;
	}
}

int clip(int I) {
	return sparse_table[30][I];
}
