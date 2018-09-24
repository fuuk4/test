#include <stdio.h>
#include <stdlib.h>

struct TestRes{
	char name[20];
	int jap;
	int math;
	int eng;
	int sum;
	struct TestRes *next;
	struct TestRes *pref;
};

struct TestRes *root;
struct TestRes *nowP;
void addVal(char *, int, int, int);

void main(){
	int jp, math, eng,jMax,mMax,eMax;
	char name[20],jpM[20],mathM[20],engM[20];
	root = NULL;

	for(int i = 0; i < 5; i++){
		printf("名前：");
		scanf("%s", &name[0]);
		printf("国語：");
		scanf("%d", &jp);
		printf("数学：");
		scanf("%d", &math);
		printf("英語：");
		scanf("%d", &eng);
		addVal(name, jp, math, eng);
		if(i == 0){
			strcpy(jpM, name);
			strcpy(mathM, name);
			strcpy(engM, name);
			jMax = jp;
			mMax = math;
			eMax = eng;
			continue;
		}
		if(jp > jMax){
			strcpy(jpM, name);
		}
		if(math > mMax){
			strcpy(mathM, name);
		}
		if(eng > eMax){
			strcpy(engM, name);
		}
	}
	printf("name\t\tｺｸｺﾞ\tｽｳｶﾞｸ\tｴｲｺﾞ\tｺﾞｳｹｲ\n");
	struct TestRes *fin = root;
	while(1){
		struct TestRes *fin = root;
		if(fin == NULL){
			break;
		}
		printf("%s\t\t", fin->name);
		printf("%d\t", fin->jap);
		printf("%d\t", fin->math);
		printf("%d\t", fin->eng);
		printf("%d\t\n", fin->sum);
		fin = fin->next;
	}

	printf("ﾄｸﾃﾝｼｬ\n");
	printf("ｺｸｺﾞ\t%s\n", jpM);
	printf("ｽｳｶﾞｸ\t%s\n", mathM);
	printf("ｴｲｺﾞ\t%s\n", engM);

	system("pause");
}

struct TestRes *memAloc(char *n,int j,int m,int e){
	struct TestRes *p;
	p = (struct TestRes *)malloc(sizeof(struct TestRes));
	p->next = NULL;
	p->pref = NULL;
	strcpy(p->name, n);
	p->jap = j;
	p->math = m;
	p->eng = e;
	p->sum = 0;
	return p;
};

void addVal(char *n, int j, int m, int e){
	struct TestRes *add;
	struct TestRes *now = nowP;
	add = memAloc(n,j,m,e);
	if(root == NULL){
		root = add;
		nowP = add;
	} else{
		nowP->next = add;
		add->pref = nowP;
		nowP = add;
	}
	add->sum = add->jap + add->math + add->eng;
}