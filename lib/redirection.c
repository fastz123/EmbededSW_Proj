
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define buf_size 100
int frequency[256] = { 0, };

char *codetable[256];

struct node
{
	char c;
	int freq;
	struct node *left;
	struct node *right;
};

struct dnode
{
	char c;
	struct dnode *left;
	struct dnode *right;
};
struct dnode *root = 0;

char codebuf[100];
int codeidx = -1;//어디까지 채웠는지 알수있는 변수

char decodebuff[100];
int decodeidx = -1;

struct node *heap[256];
int lastidx = 0;

void addToHeap(struct node *n)	//heap배열에 집어넣는함수(enque)
{
	if (lastidx == 99) return;	//꽉찼다.

	lastidx++;
	heap[lastidx] = n;

	int me = lastidx;
	int p = me / 2;

	while (1)
	{
		if (p == 0) return;		// 제일 작은 부모와의 비교가 끝났을때.
		if (heap[p]->freq <= heap[me]->freq)		// 부모가 더 작다.
		{
			return;
		}
		else
		{
			struct node *temp;
			temp = heap[me];
			heap[me] = heap[p];
			heap[p] = temp;
			me = p;
			p = me / 2;
		}
	}
}

int whichIsSmaller(int i)
{
	int left = i * 2;
	int right = left + 1;
	if (left>lastidx)	// 자식이 없다.
	{
		return -1;
	}
	else if (right <= lastidx)	// 자식이 2개이다.
	{
		if (heap[left]->freq < heap[right]->freq)
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else			// 자식이 1개이다.
	{
		return left;
	}
}

struct node* delFromHeap()	// heap배열에서 제일 부모의 노드를 빼는 함수(deque)
{
	if (lastidx == 0) return 0;	// 비어있어서 아무것도 꺼낼수 없다.
	struct node *retval = heap[1];		// 리턴값 save

	heap[1] = heap[lastidx];	// 제일 머리 값이 비었으므로 마지막에있는 값을 채워준다.
	lastidx--;

	int me = 1;

	while (1)
	{
		int child = whichIsSmaller(me);
		if (child<0)	// 자식이 없다.
		{
			return retval;
		}
		else		//자식이 있다.
		{
			if (heap[me]->freq <= heap[child]->freq)
			{
				return retval;
			}
			else
			{
				struct node *temp;
				temp = heap[me];
				heap[me] = heap[child];
				heap[child] = temp;
				me = child;
			}
		}
	}
}



void traverse(struct node *n, char code)
{
	codeidx++;

	codebuf[codeidx] = code;
	codebuf[codeidx + 1] = NULL;

	if (n->left == 0 && n->right == 0)
	{
		printf("%c(%d번) -> %s\n", n->c, frequency[n->c],codebuf);
		//codetable에 허프만코드 저장
		char *str = (char *)malloc(sizeof(codebuf) + 1);
		strcpy(str, codebuf);
		codetable[(int)n->c] = str;    

		codebuf[codeidx] = NULL;
		codeidx--;
		return;
	}
	else
	{
		traverse(n->left, '0');
		traverse(n->right, '1');
		codebuf[codeidx] = NULL;
		codeidx--;
		return;
	}
}

void decodetraverse(struct dnode *n, char code)
{
	decodeidx++;

	decodebuff[decodeidx] = code;
	decodebuff[decodeidx + 1] = NULL;

	if (n->left == 0 && n->right == 0)
	{
		printf("%c(ascii number %d) -> %s\n",n->c,(int)n->c,decodebuff);
		decodebuff[decodeidx] = NULL;
		decodeidx--;
		return;
	}
	else
	{
		decodetraverse(n->left, '0');
		decodetraverse(n->right, '1');
		decodebuff[decodeidx] = NULL;
		decodeidx--;
		return;
	}
}

void makeatree(char *argv)
{

	for (int i = 0; i<256; i++)		// frequency배열에 있는 값들을 모두 노드에 쭉 집어넣어야한다.
	{
		if (frequency[i]<1)
		{
			continue;
		}

		struct node *cur = (struct node *) malloc(sizeof(struct node));

		cur->c = (char(i));
		cur->freq = frequency[i];
		cur->left = 0;
		cur->right = 0;

		addToHeap(cur);
	}

	//heap 의 최소길이는 256칸


	struct node * first = 0;
	struct node * second = 0;

	while (1)				// 허프만 트리 완성이 끝날때까지 , 다 끝나면 한개만남고 그것은 제일꼭대기의 root를 가르킨다.
	{
		first = delFromHeap();
		second = delFromHeap();

		if (second == 0)	// 1개만 남아있는경우
		{
			break;
		}


		struct node * cur = (struct node *)malloc(sizeof(struct node));

		cur->freq = first->freq + second->freq;
		cur->left = first;
		cur->right = second;

		addToHeap(cur);
	}


	//codetable초기화
	memset(codetable, 0, sizeof(codetable));

	traverse(first->left, '0');
	traverse(first->right, '1');

	int numofcode = 0;

	//codetable에 저장된 문자와 해당하는 코드를 출력해본다
	for (int i = 0; i < 256; i++)
	{
		if (codetable[i] != 0)
		{
			//printf("code %c >> %s\n",(char)i,codetable[i]);
			numofcode++;
		}
	}
	//몇개의 코드가 있는지?
	//printf("number of code is %d", numofcode);

	//1. 파일 이름 만들기
	char outputfilename[100];
	char *period = strchr(argv, (int)'.');
	strncpy(outputfilename,argv,(int)(period-argv)); // outputfilename >> alice
	outputfilename[int(period - argv)] = 0;
	strcat(outputfilename,".encoded");//alice.encoded가 된다.
	
	//printf("filenameis %s",outputfilename);


	FILE *fout;
	fout = fopen(outputfilename, "wb");
	if (fout == 0)
	{
		printf("error open file");
	}
	fwrite(&numofcode, sizeof(int), 1, fout); //code의 개수
	for (int i = 0; i<256; i++)
	{
		char temp[100] = {0,};
		if (codetable[i] == 0)
		{
			continue;
		}
		temp[0] = (char)i;
		temp[1] = (char)strlen(codetable[i]);
		strcpy(temp + 2, codetable[i]);
		fwrite(temp, sizeof(char), strlen(temp), fout);
	}
	//encoded file contents

	//alice.txt를 다시 연다
	FILE *fin = 0;
	fin = fopen(argv, "rt");
	if (fin != 0)
	{
		//전체 비트 개수를 기록할 위치 기억
		int loc;
		loc = ftell(fout);

		if (fseek(fout, 4, SEEK_CUR) != 0)
		{
			printf("Failed to move\n");
			fclose(fin);
			fclose(fout);
			return;
		}
		char buf[100]={ 0, };
		char bitbuf[100];//생성되는 비트스트림저장 버퍼
		int bitbufIdx = 0;//현재 비트스트림 저장위치
		int bitshiftcnt = 7;//비트 시프트 횟수
		int totalbitnum = 0;//총비트수
		char flag = 0;//flag 0은 기록할것이 없다. 1은 기록할것이 있다.

					  //bitbuf를 0으로 초기화
		memset(bitbuf, 0, 100);


		//실제로 파일 읽어서 encoding
		while (fgets(buf, 100, fin) != 0)
		{
			int len = strlen(buf);
			for (int i = 0; i < len; i++)
			{
				char *code = codetable[(int)buf[i]];
				//비트로 만드는과정
				for (int j = 0; j < strlen(code); j++)
				{
					char v = 0;
					if (code[j] == '0')
					{
						v = 0;
					}
					else if (code[j] == '1')
					{
						v = 1;
					}
					else
					{
						printf("Invalid code\n");
					}
					v = v << bitshiftcnt;
					bitshiftcnt--;

					bitbuf[bitbufIdx] |= v;
					flag = 1;

					totalbitnum++;
					if (bitshiftcnt < 0)//다음칸으로넘어가기
					{
						bitshiftcnt = 7;
						bitbufIdx++;
						if (bitbufIdx >= 100)
						{
							fwrite(bitbuf, 1, 100, fout);
							flag = 0;
							bitbufIdx = 0;
							memset(bitbuf, 0, 100);
						}
					}
				}
			}
		}
		if (flag == 1)
		{
			fwrite(bitbuf, 1, bitbufIdx + 1, fout);
		}
		if (fseek(fout, loc, SEEK_SET) == 0)
		{
			fwrite(&totalbitnum, sizeof(totalbitnum), 1, fout);
		}
		else
		{
			printf("Unable to record total number of bits\n");
		}
		fclose(fin);
	}
	fclose(fout);
	printf("finish encoding %s",argv);
}

void encoding(char* argv)
{
	char buf[buf_size];
	FILE *f;
	f = fopen(argv, "rt");
	if (f == 0)
	{
		printf("no such file");
		return;
	}
	while (fgets(buf, buf_size, f) != 0)
	{
		int len = strlen(buf);
		for (int i = 0; i<len; i++)
		{
			frequency[buf[i]]++;
		}
	}
	fclose(f);
	/*for (int k = 0; k < 256; k++)
	{
	if(frequency[k]>0)
	printf("%d     (%c) %d\n",k ,k, frequency[k]);
	}*/

	makeatree(argv);

	return;
}

void remaketree(char *argv)	// encoded 파일을 인자로 받는다.
{
	int num;
	FILE *f;
	f = fopen(argv, "rb");
	if (f == 0)
	{
		printf("error");
		return;
	}

	struct dnode *huffroot = (struct dnode *)malloc(sizeof(struct dnode));
	struct dnode *cur = huffroot;
	huffroot->left = 0;
	huffroot->right = 0;
	fread(&num, sizeof(int), 1, f);	// 몇개의 문자인지 체크
									//printf("num is %d", num);
	int cnt = 0;
	while (cnt < num)
	{
		char c;	//어떤 문자인지
		fread(&c, sizeof(char), 1, f);
		char n;	// 길이
		fread(&n, sizeof(char), 1, f);
		for (int i = 0; i<n; i++)
		{
			char code;
			fread(&code, sizeof(char), 1, f);
			if (code == '0')	// tree에서 왼쪽
			{
				if (cur->left == 0)
				{
					cur->left = (struct dnode*)malloc(sizeof(struct dnode));
					cur->left->left = 0;
					cur->left->right = 0;
				}
				cur = cur->left;
			}
			else		// 오른쪽으로 내려간다
			{
				if (cur->right == 0)
				{
					cur->right = (struct dnode*)malloc(sizeof(struct dnode));
					cur->right->left = 0;
					cur->right->right = 0;
				}
				cur = cur->right;
			}
		}
		cur->c = c;
		cur = huffroot;
		cnt++;
	}


	printf("코드 검증\n\n");
	//decodetraverse(huffroot->left, '0');
	//decodetraverse(huffroot->right, '1');
	//트리복구완료


	char outputfilename[100];
	char *period = strchr(argv, (int)'.');
	strncpy(outputfilename, argv, (int)(period - argv)); // outputfilename >> alice
	outputfilename[int(period - argv)] = 0;
	strcat(outputfilename, ".decoded");//alice.decoded가 된다.

	root = huffroot;
	int numbits;
	struct dnode *temp;	//현재 트리의 root를 가르키고있음.

	fread(&numbits, sizeof(int), 1, f);
	char contents;
	temp = root;
	int finished_flag = 0;

	FILE *fout;
	fout = fopen(outputfilename, "wt");


	while (1)
	{
		fread(&contents, sizeof(char), 1, f);
		for (int i = 0; i<8; i++)
		{
			if ((contents & 0x80) == 0)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}

			if (temp->left == 0 && temp->right == 0)	// 끝까지왔다. > decoding
			{
				printf("%c", temp->c);
				fputc(temp->c, fout);
				temp = huffroot;
			}
			numbits--;
			if (numbits == 0)	//모든 bit에 대해서 decoding완료
			{
				finished_flag = 1;
				break;
			}
			contents = contents << 1;
		}
		if (finished_flag == 1) break;
	}
	fclose(f);
	fclose(fout);
	printf("\n\nfinish decoding\n\n");
}

void decoding(char *argv)
{
	remaketree(argv);
}

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		if (strcmp(argv[1], "-e") == 0)
		{
			encoding(argv[2]);
			//printf("start encoding\n");
		}
		else if (strcmp(argv[1], "-d") == 0)
		{
			printf("start decoding\n");
			decoding(argv[2]);
		}
		else
		{
			printf("올바르지 않은 사용입니다.");
			return -1;
		}
	}
	return 0;
}

