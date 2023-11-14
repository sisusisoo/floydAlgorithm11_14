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
int D[Count_Vertice][Count_Vertice]; // D[i][j]는 i에서 j까지 가는 최소 거리를 저장
int P[Count_Vertice][Count_Vertice]; // P[i][j]는 i에서 j까지 가는 데 거치는 최고 차수 정점을 저장

void Floyd() {
	int i, j, k;
	for (i = 0; i < Count_Vertice; i++) // 배열 초기화
		for (j = 0; j < Count_Vertice; j++) {
			P[i][j] = -1;
			D[i][j] = e[i][j];//기본값 탑재 
		}
	for (k = 0; k < Count_Vertice; k++)
		for (i = 0; i < Count_Vertice; i++)
			for (j = 0; j < Count_Vertice; j++)
				if (D[i][j] > D[i][k] + D[k][j]) {
					// k를 거칠 시 D[i][j]가 더 짧아지는 경우
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;//확인 
				}
}

void Print_Path(int a, int b) { // Print_Path[i][j]에서 i와 j는 출력하지 않음 
	if (P[a][b] != -1) { // P[a][b] = -1 --> a에서 바로 b로 가는 것이 최단거리
		Print_Path(a, P[a][b]);
		printf("%d ", P[a][b]+1);
		Print_Path(P[a][b], b);
	}
}

int main(int argc, char* argv[]) {
	Floyd();
	int a, b;

	while (1) {
		printf("출발점과 도착점을 입력하시오. (1 ~ %d)\n", Count_Vertice-1);
		scanf_s("%d %d", &a, &b);
		//0부터 시작 x 1부터 시작하게 하려고 
		a = a - 1;
		b = b - 1;
		printf("최단거리 : %d\n", D[a][b]);
		printf("최단경로 : ");
		printf("%d ", a+1); Print_Path(a, b);
		if (D[a][b] != 0) printf("%d", b+1); // D[a][b] = 0 "=" a = b
		printf("\n");
	}

	return 0;
}