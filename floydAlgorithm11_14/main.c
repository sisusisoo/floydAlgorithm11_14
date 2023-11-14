#include <stdio.h>
#include <stdlib.h>
#define Count_Vertice 10
#define INF 2000


int e[Count_Vertice][Count_Vertice] = {
	
		
		 {  0,  3,INF,INF,INF, 11, 12,INF,INF,INF},//1
		 {  3,  0,  5,  4,  1,  7,  8,INF,INF,INF},//2
		 {INF,  5,  0,  2,INF,INF,  6,  5,INF,INF},//3
		 {INF,  4,  2,  0, 13,INF,INF, 14,INF, 16},//4
		 {INF,  1,INF, 13,  0,  9,INF,INF, 18, 17},//5
		 { 11,  7,INF,INF,  9,  0,INF,INF,INF,INF},//6
		 { 12,  8,  6,INF,INF,INF,  0, 13,INF,INF},//7
		 {INF,INF,  5, 14,INF,INF, 13,  0,INF, 15},//8
		 {INF,INF,INF,INF, 18,INF,INF,INF,  0, 10},//9
		 {INF,INF,INF, 16, 17,INF,INF, 15, 10,  0}
};
int D[Count_Vertice][Count_Vertice]; // D[i][j]�� i���� j���� ���� �ּ� �Ÿ��� ����
int P[Count_Vertice][Count_Vertice]; // P[i][j]�� i���� j���� ���� �� ��ġ�� �ְ� ���� ������ ����

void Floyd() {
	int i, j, k;
	for (i = 0; i < Count_Vertice; i++) // �迭 �ʱ�ȭ
		for (j = 0; j < Count_Vertice; j++) {
			P[i][j] = -1;
			D[i][j] = e[i][j];//�⺻�� ž�� 
		}
	for (k = 0; k < Count_Vertice; k++)
		for (i = 0; i < Count_Vertice; i++)
			for (j = 0; j < Count_Vertice; j++)
				if (D[i][j] > D[i][k] + D[k][j]) {
					// k�� ��ĥ �� D[i][j]�� �� ª������ ���
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;//Ȯ�� 
				}
}

void Print_Path(int a, int b) { // Print_Path[i][j]���� i�� j�� ������� ���� 
	if (P[a][b] != -1) { // P[a][b] = -1 --> a���� �ٷ� b�� ���� ���� �ִܰŸ�
		Print_Path(a, P[a][b]);
		printf("%d ", P[a][b]+1);
		Print_Path(P[a][b], b);
	}
}

int main(int argc, char* argv[]) {
	Floyd();
	int a, b;

	while (1) {
		printf("������� �������� �Է��Ͻÿ�. (1 ~ %d)\n", Count_Vertice-1);
		scanf_s("%d %d", &a, &b);
		//0���� ���� x 1���� �����ϰ� �Ϸ��� 
		a = a - 1;
		b = b - 1;
		printf("�ִܰŸ� : %d\n", D[a][b]);
		printf("�ִܰ�� : ");
		printf("%d ", a+1); Print_Path(a, b);
		if (D[a][b] != 0) printf("%d", b+1); // D[a][b] = 0 "=" a = b
		printf("\n");
	}

	return 0;
}