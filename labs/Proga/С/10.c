#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    int min_avg = 10;
    int group = 100;

    for(int i = 0; i < m; i++){
        int k;
        scanf("%d", &k);

        int tot;

        for(int j = 0; j < k; j++){
            int n;
            scanf("%d", &n);
            tot += n;
        }

        int avg = tot / k;

        if(avg < min_avg && i < group){
            min_avg = avg;
            group = i + 1;
        }

        tot = 0;
    }

    if (group != 100) {
        printf("The good group %d", group);
    } else {
        printf("No");
    }

    return 0;
}
