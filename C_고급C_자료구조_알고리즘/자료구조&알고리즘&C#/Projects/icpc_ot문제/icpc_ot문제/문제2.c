#include <stdio.h>
#include <string.h>

typedef struct Info {
	char name[21];
	int win, draw, loss;
	double wRate;//½Â·ü
}Info;


int main() {
	int T,i,j,k,flag,savP1,savP2,sup,rank,sav=0;
	Info info[8];
	char support[21] = { '\0' };
	int remNum;
	int matTeam;
	char player1[21], player2[21];
	int p1, p2;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		flag = 0;
		for (j = 0; j < 8; j++) {
			getchar();
			scanf("%s %d %d %d", info[j].name, &info[j].win, &info[j].draw, &info[j].loss);
			if((info[j].win+info[j].draw+info[j].loss)!=0) 
				info[j].wRate = info[j].win / (double)(info[j].win + info[j].draw + info[j].loss);
			else info[j].wRate = 0;
		}

		getchar();
		scanf("%s", support);
		for (j = 0; j < 8; j++) {
			if (strcmp(support, info[j].name) == 0) sup = j;
		}
		
		rank = 1;

		for (j = 0; j < 8; j++) {
			if (info[sup].wRate < info[j].wRate) rank++;
		}
		if (rank <= 4) flag = 1;

		scanf("%d", &matTeam);
		
		for (j = 0; j < matTeam; j++) {
			getchar(); 
			scanf("%s %s", player1, player2);
			sav = 0;

			if (flag == 0) {
				for (k = 0; k < 8; k++) {
					if (strcmp(player1, info[k].name) == 0) p1 = k;
					if (strcmp(player2, info[k].name) == 0) p2 = k;
				}
		
				if (strcmp(info[sup].name, player1) == 0) sav = 1;
				if (strcmp(info[sup].name, player2) == 0) sav = 1;

				if (sav != 1) { 
					info[p1].draw++;
					info[p2].draw++;
				}
				else {
					if (strcmp(info[p1].name, info[sup].name) == 0) {
						info[p1].win++;
						info[p2].loss++;
					}
					else {
						info[p2].win++;
						info[p1].loss++;
					}
				}

				info[p1].wRate = info[p1].win / (double)(info[p1].win + info[p1].loss + info[p1].draw);
				info[p2].wRate = info[p2].win / (double)(info[p2].win + info[p2].loss + info[p2].draw);
				
				rank = 1;

				for (k = 0; k < 8; k++) {
					if (info[k].wRate > info[sup].wRate) rank++;
				}

				if (rank <= 4) flag = 1;
			}

		}

		if (flag == 1) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}