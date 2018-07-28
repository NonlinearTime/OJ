#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;


#define MAX_SIZE 4
#define MAX_STEPS 16

int opt[MAX_SIZE * MAX_SIZE];
int recc,res;
bool visit[1 << MAX_STEPS];
int END;
queue<int > options;

void init() {
    recc = 0;
    END = 0;
    memset(visit,0,1 << MAX_STEPS);
    while (options.size()) options.pop();
    for (size_t i = 0 ; i < MAX_SIZE * MAX_SIZE ; ++i) opt[i] = 1 << i, END += opt[i];

}

int flip(int index, int rec) {
    rec = rec ^ opt[index];
    if (index - 1 >= 0) rec ^= opt[index - 1];
    if (index - 4 >= 0) rec ^= opt[index - 4];
    if (index + 1 < MAX_SIZE * MAX_SIZE ) rec ^= opt[index + 1];
    if (index + 4 < MAX_SIZE * MAX_SIZE ) rec ^= opt[index + 4];
    return rec;
}

int BFS(int board) {

    options.push(board);
    visit[board] = 1;
    int step = 0;

    while (options.size()) {
        int t1 = options.size();
        while (t1--) {
            int tmp = options.front();
            options.pop();
            if (tmp == 0 || tmp == END) {
//                    printf("%d %d\n",t,END);
                return step;
            }
            if (step > MAX_STEPS) {
                return -1;
            }
            for (size_t i = 0; i < MAX_STEPS; ++i) {
                int t = flip(i, tmp);

                if (!visit[t]) {
                    options.push(t);
                    visit[t] = 1;
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
    char buf[MAX_SIZE+1];
    init();
    for (size_t i = 0 ; i < MAX_SIZE ; ++i) {
        scanf("%s",buf);
        for (size_t j = 0 ; j < MAX_SIZE ; ++j) {
            if (buf[j] == 'b') recc ^= opt[i *4 + j];
        }
    }
//    printf("%p\n",rec);
    res = BFS(recc);
    if (res == -1) printf("Impossible\n");
    else printf("%d\n",res);

    return 0;
}

